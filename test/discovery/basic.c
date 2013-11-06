
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "discovery.h"

int main(int ac, char **av) {
    int ret = 0;
    boz_disc_t manager = BOZ_DISC_ZERO;

    (void) ac;
    (void) av;

    ret = boz_discovery_init(&manager);
    if (ret < 0) {
        fprintf(stderr, "Unable to init discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    getchar();

    ret = boz_discovery_term(&manager);
    if (ret < 0) {
        fprintf(stderr, "Unable to term discovery manager, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "All test succeeded\n");
    exit(EXIT_SUCCESS);
}
