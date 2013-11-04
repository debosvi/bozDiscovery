
#include "bozdisco_shared.h"
#include "boz/internal_p.h"

int _bozdiscovery_startf(bozdisco_ref a, struct taia const *deadline, struct taia *stamp) {
    char const *cargv[2] = { BOZDISCO_PROG, 0 };
    char const *cenvp[1] = { 0 };
    return skaclient2_startf(&a->connection, cargv[0], cargv, cenvp, BOZDISCO_BANNER1, BOZDISCO_BANNER1_LEN, BOZDISCO_BANNER2,
                             BOZDISCO_BANNER2_LEN, SKACLIENT_OPTION_WAITPID, deadline, stamp);
}
