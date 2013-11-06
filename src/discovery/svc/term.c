/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/strerr2.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

int bozdisco_svc_term(void) {
    gensetdyn_free(&bozdisco_nodes);
    zbeacon_destroy(&g_beacon);
        
    return 0;
}
