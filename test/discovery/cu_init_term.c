
#include "cu_discovery.h"

void test_init_args(void) {
    boz_disc_t mgr;
    int ret=0;

    ret=boz_discovery_init(&mgr);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);

    mgr=BOZ_DISC_ZERO;
    ret=boz_discovery_init(&mgr);
    CU_ASSERT(ret == 0);
    CU_ASSERT(errno == 0);
    CU_ASSERT(mgr != BOZ_DISC_ZERO);
}

void test_term_args(void) {
    boz_disc_t mgr, tmgr;
    int ret=0;

    mgr=BOZ_DISC_ZERO;
    ret=boz_discovery_term(&mgr);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT(mgr == BOZ_DISC_ZERO);

    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_term(&mgr);
    CU_ASSERT(ret == 0);
    CU_ASSERT(errno == 0);
    CU_ASSERT(mgr == BOZ_DISC_ZERO);

    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    tmgr=mgr;
    boz_discovery_term(&tmgr);
    tmgr=mgr;
    ret=boz_discovery_term(&mgr);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT( mgr != BOZ_DISC_ZERO);
}

