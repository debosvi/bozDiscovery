
#include "boz/internal_p.h"

int boz_discovery_term(boz_disc_t *mgr) {
    int ret=-1;
    
    if(!mgr || !(*mgr))
        return (errno=EINVAL,-1);

    if((*mgr)->magic!=g_disco_main.magic)
        return (errno=EINVAL,-1);
    
    BOZDISCO_LOCK_MUTEX(g_disco_main.mutex);
    ret=gensetdyn_delete (&g_disco_main.mgr, (*mgr)->idx);
        
    if(!ret) {
        BOZDISCO_UNLOCK_MUTEX(g_disco_main.mutex);
        return (errno=EIO,-1);
    }

    gensetdyn_free (&(*mgr)->reg);
    (*mgr)->reg = gensetdyn_zero;
    (*mgr)->idx = -1;
    (*mgr)->magic = 0;
    pthread_mutex_destroy(&(*mgr)->mutex);
    BOZDISCO_UNLOCK_MUTEX(g_disco_main.mutex);
    
    (*mgr)=BOZ_DISC_ZERO;
    return (errno=0,0);   
}
