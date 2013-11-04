
#include "bozdisco_shared.h"
#include "boz/internal_p.h"

void _bozdiscovery_end(bozdisco_ref a) {
    skaclient2_end(&a->connection);
}
