
#include "cu_discovery.h"

void test_register_args(void) {
    boz_disc_t mgr;
    int ret=0;

    // test bad manager
    mgr=BOZ_DISC_ZERO;
    ret=boz_discovery_register(mgr, NULL);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT(mgr == BOZ_DISC_ZERO);

    // test bad URI
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_register(mgr, NULL);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EFAULT);
    ret=boz_discovery_term(&mgr);

    // test URI exceed length
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_register(mgr, "tcp://totototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototototo");
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EFBIG);
    ret=boz_discovery_term(&mgr);

    // test double register on same URI
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_register(mgr, "tcp://toto:3142");
    CU_ASSERT(ret >= 0);
    CU_ASSERT(errno == 0);
    ret=boz_discovery_register(mgr, "tcp://toto:3142");
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EEXIST);
    ret=boz_discovery_term(&mgr);
}

