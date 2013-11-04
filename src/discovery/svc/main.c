/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/uint16.h"
#include "skarnet/uint32.h"
#include "skarnet/allreadwrite.h"
#include "skarnet/error.h"
#include "skarnet/strerr2.h"
#include "skarnet/sig.h"
#include "skarnet/tai.h"
#include "skarnet/djbunix.h"
#include "skarnet/iopause.h"
#include "skarnet/netstring.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

static bufalloc asyncout = BUFALLOC_ZERO;

static const char *announce = "BOZDISCOVERY";

int main(void) {
    stralloc indata = STRALLOC_ZERO;
    unsigned int instate = 0;
    PROG = BOZDISCO_PROG;

    if (ndelay_on(0) < 0)
        strerr_diefu2sys(111, "ndelay_on ", "0");
    if (ndelay_on(1) < 0)
        strerr_diefu2sys(111, "ndelay_on ", "1");
    if (sig_ignore(SIGPIPE) < 0)
        strerr_diefu1sys(111, "ignore SIGPIPE");

    {
        struct taia deadline, stamp;
        taia_now(&stamp);
        taia_addsec(&deadline, &stamp, 2);
        if (!skaserver2_sync
            (&asyncout, BOZDISCO_BANNER1, BOZDISCO_BANNER1_LEN, BOZDISCO_BANNER2, BOZDISCO_BANNER2_LEN, &deadline,
             &stamp))
            strerr_diefu1sys(111, "sync with client");
    }

    g_beacon = zbeacon_new(BOZDISCO_SVC_DEF_PORT);
    if(g_beacon) {
        zbeacon_noecho(g_beacon);
        zbeacon_set_interval(g_beacon, 2000);
        zbeacon_publish(g_beacon, (byte*)announce, strlen(announce));
//         fprintf(stderr, "%s: announce fd(%d)", PROG, (int)zbeacon_socket(g_beacon));
    }
    
    for (;;) {
        register unsigned int n = 1;
        iopause_fd x[3 + n];
        int ri;
//         zpoller_t *poller = NULL;

        x[0].fd = 0;
        x[0].events = IOPAUSE_EXCEPT | IOPAUSE_READ;
        x[1].fd = 1;
        x[1].events = IOPAUSE_EXCEPT | (bufalloc_len(bufalloc_1) ? IOPAUSE_WRITE : 0);
        x[2].fd = bufalloc_fd(&asyncout);
        x[2].events = IOPAUSE_EXCEPT | (bufalloc_len(&asyncout) ? IOPAUSE_WRITE : 0);
        
        

        ri = iopause(x, 3 + n, 0, 0);
        if (ri < 0) {
            strerr_diefu1sys(111, "iopause");
        }

        /* client closed => exit */
        if ((x[0].revents | x[1].revents) & IOPAUSE_EXCEPT)
            break;

        /* client reading => flush pending data */
        if (x[1].revents & IOPAUSE_WRITE)
            if ((bufalloc_flush(bufalloc_1) == -1) && !error_isagain(errno)) {
                strerr_diefu1sys(111, "flush stdout");
            }
        if (x[2].revents & IOPAUSE_WRITE)
            if ((bufalloc_flush(&asyncout) == -1) && !error_isagain(errno)) {
                strerr_diefu1sys(111, "flush asyncout");
            }

        /* client writing => get data and parse it */
        if (buffer_len(buffer_0small) || x[0].revents & IOPAUSE_READ) {
            int r;
            for (;;) {
                r = sanitize_read(netstring_get(buffer_0small, &indata, &instate));
                if (r <= 0)
                    break;
                indata.len = 0;
            }                   /* end loop: parse input from client */

            if (r < 0) {
                if (errno == EPIPE)
                    break;      /* client closed */
                else {
                    strerr_diefu1sys(111, "read a netstring");
                }
            }
        }                       /* end if: stuff to read on stdin */
    }                           /* end loop: main iopause */

    zbeacon_destroy(&g_beacon);
    return 0;
}
