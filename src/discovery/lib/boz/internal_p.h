
#ifndef _BOZ_INTERNAL_P_H_
#define _BOZ_INTERNAL_P_H_

#include <errno.h>
#include <skarnet/gensetdyn.h>
#include <skarnet/random.h>
#include <skarnet/tai.h>
#include <skarnet/skaclient.h>

#include "boz/discovery_p.h"

extern gensetdyn g_discovery_storage;
extern unsigned int g_discovery_magic; 

typedef struct bozdisco_s bozdisco, bozdisco_t, *bozdisco_ref, *bozdisco_t_ref ;
struct bozdisco_s {
  skaclient2_t connection ;
} ;
#define BOZDISCO_ZERO { SKACLIENT2_ZERO }
extern bozdisco const bozdisco_zero ;

extern int _bozdiscovery_startf(bozdisco_ref a, struct taia const *deadline, struct taia *stamp);
extern void _bozdiscovery_end(bozdisco_ref a) ;
extern int _bozdiscovery_fd(bozdisco_ref a) ;

#endif
