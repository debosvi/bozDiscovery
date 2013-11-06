
#ifndef _BOZDISCO_SVC_H_
#define _BOZDISCO_SVC_H_

#include "czmq.h"
#include "skarnet/bufalloc.h"
#include "skarnet/gensetdyn.h"

#include "discovery.h"

#define BOZDISCO_SVC_DEF_PORT   9999
#define BOZ_DISC_IP_MAXLEN      64

typedef struct {
    unsigned int idx;
    char ip[BOZ_DISC_IP_MAXLEN];
    char uri[BOZ_DISC_URI_MAXLEN];
} bozdisco_node_t;

extern bufalloc asyncout;
extern zbeacon_t *g_beacon;
extern gensetdyn bozdisco_nodes;

extern void bozdisco_svc_sync(void);
extern int bozdisco_svc_init(void);
extern int bozdisco_svc_term(void);

// bozdisco_svc_addnode, returns 0 on add, 1 on update
extern int bozdisco_svc_addnode(const char *ip, const char *uri);
extern int bozdisco_svc_delnode(const char *ip, const char *uri);

#endif