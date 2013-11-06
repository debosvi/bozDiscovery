
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "czmq.h"

static const char *announce = "BOZDISCOVERY";

int main(int ac, char **av) {
    zbeacon_t *g_beacon=NULL;
    char *uri=(char*)announce;
    
    if(ac>1)
        uri=av[1];
    
    g_beacon = zbeacon_new(9999);
    if(!g_beacon)
        exit(EXIT_FAILURE);
    
    fprintf(stderr, "publish uri: %s\n", uri);
    zbeacon_noecho(g_beacon);
    zbeacon_set_interval(g_beacon, 2000);
    zbeacon_publish(g_beacon, (byte*)uri, strlen(uri));
            
    fprintf(stderr, "Press key to exit\n");
    getchar();
    
    zbeacon_destroy(&g_beacon);
    exit(EXIT_SUCCESS);
}