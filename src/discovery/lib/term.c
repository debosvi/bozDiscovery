
#include "boz/internal_p.h"

int boz_discovery_term(boz_disc_t *mgr) {
    if(!mgr || !(*mgr))
        return (errno=EINVAL,-1);

    if((*mgr)->magic!=g_discovery_magic)
        return (errno=EINVAL,-1);
    
    gensetdyn_free (&(*mgr)->reg);
    if(!gensetdyn_delete (&g_discovery_storage, (*mgr)->idx))
        return (errno=EIO,-1);

    (*mgr)->reg = gensetdyn_zero;
    (*mgr)->idx = -1;
    (*mgr)->magic = 0;

    (*mgr)=BOZ_DISC_ZERO;
    return (errno=0,0);   
}
