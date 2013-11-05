
#include "boz/internal_p.h"

int boz_discovery_unregister(const boz_disc_t mgr, const int id) {
    unsigned int idx=-1;
   
    if(mgr->magic!=g_discovery_magic)
        return (errno=EINVAL,-1);
    
    idx=(unsigned int)id;
    
    if(!gensetdyn_delete (&mgr->reg, idx))
        return (errno=ENOENT,-1);

    return (errno=0,0);   
}
