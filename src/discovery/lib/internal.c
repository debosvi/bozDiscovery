
#include <stdio.h>

#include "bozdisco_shared.h"
#include "boz/internal_p.h"

gensetdyn g_discovery_storage = GENSETDYN_INIT(struct boz_disc_s, 4, 0, 1);
unsigned int g_discovery_magic=0; 
bozdisco const g_disco_zero = BOZDISCO_ZERO;

static bozdisco g_disco_main;

__attribute__((constructor))
static void init() {
    fprintf(stderr, "discovery constructor\n");
    goodrandom_init ();
    g_discovery_magic = goodrandom_int(0);
    g_disco_main = g_disco_zero;
    _bozdiscovery_startf(&g_disco_main, NULL, NULL);
}

__attribute__((destructor))
static void fini() {
    fprintf(stderr, "discovery destructor\n");
    _bozdiscovery_end(&g_disco_main);
    g_disco_main = g_disco_zero;
    goodrandom_finish ();
}
