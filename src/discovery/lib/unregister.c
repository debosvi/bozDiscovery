
#include "boz/internal_p.h"

int boz_discovery_unregister(const boz_disc_t mgr, const int id) {
    boz_disc_reg_t *p=NULL;
    int ret=-1;
    unsigned int idx=-1;
   
    if(!mgr)
        return (errno=EINVAL,-1);

    if(mgr->magic!=g_disco_main.magic)
        return (errno=EINVAL,-1);
    
    idx=(unsigned int)id;

    BOZDISCO_LOCK_MUTEX(mgr->mutex);
    ret=gensetdyn_delete (&mgr->reg, idx);
    
    if(!ret) {
        BOZDISCO_UNLOCK_MUTEX(mgr->mutex);
        return (errno=ENOENT,-1);
    }

    p=GENSETDYN_P(boz_disc_reg_t, &mgr->reg, idx);
    p->idx=-1;
    memset(&p->uri[0], 0, BOZ_DISC_URI_MAXLEN);
    BOZDISCO_UNLOCK_MUTEX(mgr->mutex);
    
    return (errno=0,0);   
}
