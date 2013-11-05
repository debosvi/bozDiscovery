
#include "boz/internal_p.h"

static int _boz_disc_iter_reg(char *p, void *stuff) {
    char *uri=(char*)stuff;
    
    return strncmp(p, uri, BOZ_DISC_URI_MAXLEN);   
}

int boz_discovery_register(const boz_disc_t mgr, const char* uri) {
    boz_disc_reg_t *p=NULL;
    unsigned int idx=-1;
    int ret=-1;
    
    if(mgr->magic!=g_discovery_magic)
        return (errno=EINVAL,-1);
    
    if(!uri) 
        return (errno=EFAULT,-1);
    if(strlen(uri)>=BOZ_DISC_URI_MAXLEN)
        return (errno=EFBIG,-1);
    
    idx=gensetdyn_iter (&mgr->reg, _boz_disc_iter_reg, (void*)uri);
    if(idx)
        return (errno=EEXIST,-1);
    
    ret=gensetdyn_new (&mgr->reg, &idx);
    if(ret<0) return -1;
    
    p=GENSETDYN_P(boz_disc_reg_t, &mgr->reg, idx);
    p->idx=idx;
    memcpy(&p->uri[0], uri, strlen(uri));
    
    return idx;   
}
