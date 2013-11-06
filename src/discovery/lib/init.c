
#include "boz/internal_p.h"

int boz_discovery_init(boz_disc_t *mgr) {
    unsigned int idx=-1;
    int ret=-1;
    
    if((*mgr)!=BOZ_DISC_ZERO)
        return(errno=EINVAL,-1);
    
    BOZDISCO_LOCK_MUTEX(g_disco_main.mutex);
    ret=gensetdyn_new (&g_disco_main.mgr, &idx);
    BOZDISCO_UNLOCK_MUTEX(g_disco_main.mutex);
    
    if(ret<0) 
        return (errno=EIO,-1);

    (*mgr)=GENSETDYN_P(struct boz_disc_s, &g_disco_main.mgr, idx);
    (*mgr)->magic=g_disco_main.magic;
    (*mgr)->idx=idx;
    pthread_mutex_init(&(*mgr)->mutex, NULL);
    gensetdyn_init(&(*mgr)->reg, sizeof(boz_disc_reg_t), 4, 0, 1);

    return (errno=0,0);   
}
