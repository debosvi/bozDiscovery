
#include "boz/internal_p.h"

int boz_discovery_term(boz_disc_t *manager) {
    if((*manager)->magic!=0x5A5A5A5A)
        return (errno=EINVAL,-1);
    gensetdyn_delete (&g_discovery_storage, (*manager)->idx);
    return 0;   
}
