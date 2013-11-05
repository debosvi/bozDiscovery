
#include "boz/internal_p.h"

static int _boz_disc_iter_uri(char *p, void *stuff) {
    unsigned int idx=*(unsigned int*)stuff;
    boz_disc_reg_t *tmp=(boz_disc_reg_t*)p;
    
    return idx==tmp->idx;   
}

char* boz_discovery_geturi(const boz_disc_t mgr, const int id) {
    boz_disc_reg_t *p=NULL;
    unsigned int idx=-1;
    
    if(mgr->magic!=g_discovery_magic)
        return (errno=EINVAL,NULL);
    
    idx=gensetdyn_iter (&mgr->reg, _boz_disc_iter_uri, (void*)&id);
    if(!idx)
        return (errno=ENOENT,NULL);
    
    p=GENSETDYN_P(boz_disc_reg_t, &mgr->reg, id);

    return &p->uri[0];   
}
