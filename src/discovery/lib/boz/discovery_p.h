
#ifndef _BOZ_DISCOVERY_P_H_
#define _BOZ_DISCOVERY_P_H_

#include "discovery.h"

typedef struct {
    unsigned int    idx;
    char            uri[BOZ_DISC_URI_MAXLEN];
} boz_disc_reg_t;    

struct boz_disc_s {
    unsigned int    magic;
    unsigned int    idx;
    pthread_mutex_t mutex;
    gensetdyn       reg;
};

extern int _boz_disc_iter(char *p, void *stuff);

#endif
