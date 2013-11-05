
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "czmq.h"

static const char *announce = "BOZDISCOVERY";

int main(int ac, char **av) {
    zbeacon_t *g_beacon=NULL;
    
    (void)ac;
    (void)av;
    
    g_beacon = zbeacon_new(9999);
    if(g_beacon) {
        zbeacon_noecho(g_beacon);
        zbeacon_set_interval(g_beacon, 2000);
        zbeacon_publish(g_beacon, (byte*)announce, strlen(announce));
        //         fprintf(stderr, "%s: announce fd(%d)", PROG, (int)zbeacon_socket(g_beacon));
    }
        
    fprintf(stderr, "Press key to exit\n");
    getchar();
    
    zbeacon_destroy(&g_beacon);
    exit(EXIT_SUCCESS);
}