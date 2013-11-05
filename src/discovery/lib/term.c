
#include "boz/internal_p.h"

int boz_discovery_term(boz_disc_t *mgr) {
    if((*mgr)->magic!=g_discovery_magic)
        return (errno=EINVAL,-1);
    
    gensetdyn_free (&(*mgr)->reg);
    gensetdyn_delete (&g_discovery_storage, (*mgr)->idx);
    return 0;   
}
