/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/strerr2.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

void bozdisco_svc_sync(void) {
    struct taia deadline, stamp;
    taia_now(&stamp);
    taia_addsec(&deadline, &stamp, 2);
    if (!skaserver2_sync
        (&asyncout, BOZDISCO_BANNER1, BOZDISCO_BANNER1_LEN, BOZDISCO_BANNER2, BOZDISCO_BANNER2_LEN, &deadline,
            &stamp))
        strerr_diefu1sys(111, "sync with client");
}
