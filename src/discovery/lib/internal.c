
#include <stdio.h>

#include "bozdisco_shared.h"
#include "boz/internal_p.h"

unsigned int g_discovery_magic=0; 
bozdisco const g_disco_zero = BOZDISCO_ZERO;

bozdisco g_disco_main;

__attribute__((constructor))
static void init() {
    fprintf(stderr, "discovery constructor\n");
    g_disco_main = g_disco_zero;
    goodrandom_init ();
    g_disco_main.magic = goodrandom_int(0X5A5A5A5A);
    fprintf(stderr, "\tdicovery magic(%u)\n", g_disco_main.magic);
    _bozdiscovery_startf(&g_disco_main, NULL, NULL);
}

__attribute__((destructor))
static void fini() {
    fprintf(stderr, "discovery destructor\n");
    _bozdiscovery_end(&g_disco_main);
    gensetdyn_free (&g_disco_main.mgr);
    g_disco_main = g_disco_zero;
    goodrandom_finish ();
}
