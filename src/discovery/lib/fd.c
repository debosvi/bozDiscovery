
#include "bozdisco_shared.h"
#include "boz/internal_p.h"

int _bozdiscovery_fd(bozdisco_ref a) {
    return skaclient2_fd(&a->connection);
}
