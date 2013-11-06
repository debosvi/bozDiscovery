/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/strerr2.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

static int _bozdisco_svc_del_iter(char *p, void *stuff) {
    return 0;
}

int bozdisco_svc_delnode(const char *ip, const char *svc) {
        
//     gensetdyn_init(&bozdisco_nodes, sizeof(bozdisco_node_t), 1, 0, 1);
    
    return 0;
}
