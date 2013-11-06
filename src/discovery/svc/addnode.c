/* ISC license. */

#include <errno.h>
#include <signal.h>

#include "skarnet/strerr2.h"
#include "skarnet/skaclient.h"

#include "bozdisco_shared.h"
#include "bozdisco_svc_p.h"

static int _bozdisco_svc_add_iter(char *p, void *stuff) {
    bozdisco_node_t *elem1=(bozdisco_node_t*)p;
    bozdisco_node_t *elem2=(bozdisco_node_t*)stuff;
    int ipmatch=0, urimatch=0;
    
    ipmatch = !strncmp(elem1->ip, elem2->ip, BOZ_DISC_IP_MAXLEN);
    urimatch = !strncmp(elem1->uri, elem2->uri, BOZ_DISC_URI_MAXLEN);
//     fprintf(stderr, "%s: ip(%d), uri(%d)\n", __FUNCTION__, ipmatch, urimatch); 
    
    if (ipmatch && urimatch) {
        elem2->idx=GENSETDYN_P(bozdisco_node_t, &bozdisco_nodes, 0)->idx;
        return 1;
    }
    return 0;
}

int bozdisco_svc_addnode(const char *ip, const char *uri) {
    unsigned int found;
    bozdisco_node_t elem;
    bozdisco_node_t *p=&elem;
    
    if(strlen(ip)>BOZ_DISC_IP_MAXLEN) return -1;
    if(strlen(uri)>BOZ_DISC_URI_MAXLEN) return -1;
    
    memset(&elem, 0, sizeof(bozdisco_node_t));
    memcpy(&elem.ip[0], ip, strlen(ip));
    memcpy(&elem.uri[0], uri, strlen(uri));
    elem.idx=-1;
    
    found=gensetdyn_iter (&bozdisco_nodes, _bozdisco_svc_add_iter, (void*)&elem);  
    
    if(!found) {
        unsigned int idx;
        gensetdyn_new(&bozdisco_nodes, &idx);        
        p=GENSETDYN_P(bozdisco_node_t, &bozdisco_nodes, idx);
        elem.idx=idx;
        (*p)=elem;
//         fprintf(stderr, "%s: new elem ip(%s), uri(%s)\n", __FUNCTION__, p->ip, p->uri); 
    }
    else {
//         fprintf(stderr, "%s: update elem ip(%s), uri(%s)\n", __FUNCTION__, p->ip, p->uri); 
    }
    
    return found;
}
