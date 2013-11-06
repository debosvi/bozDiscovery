
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "czmq.h"

int main(int ac, char **av) {
    zbeacon_t *g_beacon=NULL;
    char *uri=NULL;
    
    if(ac>1)
        uri=av[1];
    
    g_beacon = zbeacon_new(9999);
    if(!g_beacon)
        exit(EXIT_FAILURE);
    
    zbeacon_noecho(g_beacon);
    zbeacon_set_interval(g_beacon, 2000);
    zbeacon_subscribe(g_beacon, (byte*)uri, (uri?strlen(uri):0));
        
    fprintf(stderr, "Press key to exit\n");
    
    for (;;) {
        zmq_pollitem_t x[2];
        int ri;
        //         zpoller_t *poller = NULL;
        
        x[0].socket = NULL;
        x[0].fd = 0;
        x[0].events = ZMQ_POLLERR | ZMQ_POLLIN;
        x[1].socket = zbeacon_socket(g_beacon);
        x[1].fd = -1;
        x[1].events = ZMQ_POLLERR | ZMQ_POLLIN;
        
        ri = zmq_poll(x, 2, -1);
        if (ri < 0) {
            fprintf(stderr, "zmq_poll error");
            break;
        }
    
        if ((x[0].revents) & ZMQ_POLLIN)
            break;
    
        if (x[1].revents & ZMQ_POLLIN) {
            char *ipaddress=NULL, *beacon=NULL;
            zstr_recvx (x[1].socket, &ipaddress, &beacon, NULL);
            fprintf(stderr, "ip(%s), beacon(%s)\n", ipaddress, beacon);
            free (ipaddress);
            free (beacon);
        }
    }
    
    zbeacon_destroy(&g_beacon);
    exit(EXIT_SUCCESS);
}