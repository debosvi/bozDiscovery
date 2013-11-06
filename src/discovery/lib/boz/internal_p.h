
#ifndef _BOZ_INTERNAL_P_H_
#define _BOZ_INTERNAL_P_H_

#include <errno.h>
#include <pthread.h>
#include <skarnet/gensetdyn.h>
#include <skarnet/random.h>
#include <skarnet/tai.h>
#include <skarnet/skaclient.h>

#include "boz/discovery_p.h"

typedef struct bozdisco_s bozdisco, bozdisco_t, *bozdisco_ref, *bozdisco_t_ref ;
struct bozdisco_s {
    unsigned int        magic; 
    skaclient2_t        connection;
    pthread_mutex_t     mutex;
    gensetdyn           mgr;
};

#define BOZDISCO_ZERO { 0, SKACLIENT2_ZERO, PTHREAD_MUTEX_INITIALIZER, GENSETDYN_INIT(struct boz_disc_s, 4, 0, 1) }

extern bozdisco const bozdisco_zero ;
extern bozdisco g_disco_main;

#define BOZDISCO_LOCK_MUTEX(x)      pthread_mutex_lock(&x)
#define BOZDISCO_UNLOCK_MUTEX(x)    pthread_mutex_unlock(&x)

extern int _bozdiscovery_startf(bozdisco_ref a, struct taia const *deadline, struct taia *stamp);
extern void _bozdiscovery_end(bozdisco_ref a) ;
extern int _bozdiscovery_fd(bozdisco_ref a) ;

#endif
