
#include <stdio.h>
#include "boz/internal_p.h"

gensetdyn g_discovery_storage = GENSETDYN_INIT(struct boz_disc_s, 4, 0, 1);
unsigned int g_discovery_magic=0; 

__attribute__((constructor))
static void init() {
    fprintf(stderr, "discovery constructor\n");
    goodrandom_init ();
    g_discovery_magic = goodrandom_int(0);
}

__attribute__((destructor))
static void fini() {
    fprintf(stderr, "discovery destructor\n");
    goodrandom_finish ();
}