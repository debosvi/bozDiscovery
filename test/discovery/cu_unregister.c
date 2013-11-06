
#include "cu_discovery.h"

void test_unregister_args(void) {
    boz_disc_t mgr;
    int ret=0;
    int reg_id=-1;

    // test bad manager
    mgr=BOZ_DISC_ZERO;
    ret=boz_discovery_unregister(mgr, 0);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT(mgr == BOZ_DISC_ZERO);

    // test bad ID
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_unregister(mgr, reg_id);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == ENOENT);
    ret=boz_discovery_term(&mgr);

    // test unregister ID
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_register(mgr, "tcp://toto:3142");
    reg_id=ret;
    ret=boz_discovery_unregister(mgr, reg_id);
    CU_ASSERT(ret == 0);
    CU_ASSERT(errno == 0);
    ret=boz_discovery_unregister(mgr, reg_id);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == ENOENT);
    ret=boz_discovery_term(&mgr);
}

