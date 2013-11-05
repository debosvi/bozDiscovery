
#include "boz/internal_p.h"

int boz_discovery_init(boz_disc_t *mgr) {
    unsigned int idx=-1;
    int ret=-1;
    ret=gensetdyn_new (&g_discovery_storage, &idx);
    if(ret<0) return -1;
    (*mgr)=GENSETDYN_P(struct boz_disc_s, &g_discovery_storage, idx);
    (*mgr)->magic=g_discovery_magic;
    (*mgr)->idx=idx;
    gensetdyn_init(&(*mgr)->reg, sizeof(boz_disc_reg_t), 4, 0, 1);
    return 0;   
}
