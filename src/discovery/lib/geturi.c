
#include "boz/internal_p.h"

static int _boz_disc_iter_uri(char *p, void *stuff) {
    unsigned int idx=*(unsigned int*)stuff;
    boz_disc_reg_t *tmp=(boz_disc_reg_t*)p;
    
    return idx==tmp->idx;   
}

char* boz_discovery_geturi(const boz_disc_t mgr, const int id) {
    boz_disc_reg_t *p=NULL;
    unsigned int idx=-1;
    char *tmp=NULL;
    
    if(!mgr)
        return (errno=EINVAL,NULL);

    if(mgr->magic!=g_disco_main.magic)
        return (errno=EINVAL,NULL);
    
    BOZDISCO_LOCK_MUTEX(mgr->mutex);
    idx=gensetdyn_iter (&mgr->reg, _boz_disc_iter_uri, (void*)&id);

    if(!idx) {
        BOZDISCO_UNLOCK_MUTEX(mgr->mutex);
        return (errno=ENOENT,NULL);
    }
    
    p=GENSETDYN_P(boz_disc_reg_t, &mgr->reg, id);

    tmp=strdup(&p->uri[0]);   
    BOZDISCO_UNLOCK_MUTEX(mgr->mutex);
    
    return tmp;
}
