
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "discovery.h"

int main(int ac, char **av) {
    int ret = 0;
    boz_disc_t manager = BOZ_DISC_ZERO;
    int reg_id=-1;
    char *uri=NULL;
    
    (void) ac;
    (void) av;

    ret = boz_discovery_init(&manager);
    if (ret < 0) {
        fprintf(stderr, "Unable to init discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    ret = boz_discovery_register(manager, "tcp://toto:3142");
    if (ret < 0) {
        fprintf(stderr, "Unable to register on discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    reg_id=ret;
    
    uri = boz_discovery_geturi(manager, reg_id);
    if (!uri) {
        fprintf(stderr, "Unable to get uri on discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "URI (%s)\n", uri);
    free(uri);
    
    getchar();

    ret = boz_discovery_unregister(manager, reg_id);
    if (ret < 0) {
        fprintf(stderr, "Unable to unregister on discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    ret = boz_discovery_term(&manager);
    if (ret < 0) {
        fprintf(stderr, "Unable to term discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "All test succeeded\n");
    exit(EXIT_SUCCESS);
}
