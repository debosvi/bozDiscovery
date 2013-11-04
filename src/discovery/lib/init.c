
#include "boz/internal_p.h"

int boz_discovery_init(boz_disc_t *manager) {
    unsigned int idx=-1;
    int ret=-1;
    ret=gensetdyn_new (&g_discovery_storage, &idx);
    if(ret<0) return -1;
    (*manager)=GENSETDYN_P(struct boz_disc_s, &g_discovery_storage, idx);
    (*manager)->magic=g_discovery_magic;
    (*manager)->idx=idx;
    return 0;   
}
