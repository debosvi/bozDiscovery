/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/strerr2.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

int bozdisco_svc_init(void) {
    g_beacon = zbeacon_new(BOZDISCO_SVC_DEF_PORT);
    if(g_beacon) {
        zbeacon_noecho(g_beacon);
        zbeacon_subscribe(g_beacon, NULL, 0);
    }
    
    gensetdyn_init(&bozdisco_nodes, sizeof(bozdisco_node_t), 1, 0, 1);
    
    return 0;
}
