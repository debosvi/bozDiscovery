
#include "cu_discovery.h"

void test_geturi_args(void) {
    boz_disc_t mgr;
    int ret=0;
    int reg_id=-1;
    char *uri=NULL;

    // test bad manager
    mgr=BOZ_DISC_ZERO;
    uri=boz_discovery_geturi(mgr, 0);
    CU_ASSERT(uri == NULL);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT(mgr == BOZ_DISC_ZERO);

    // test bad ID
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    uri=boz_discovery_geturi(mgr, reg_id);
    CU_ASSERT(uri == NULL);
    CU_ASSERT(errno == ENOENT);
    ret=boz_discovery_term(&mgr);

    // test geturi on ID
    mgr=BOZ_DISC_ZERO;
    boz_discovery_init(&mgr);
    ret=boz_discovery_register(mgr, "tcp://toto:3142");
    reg_id=ret;
    uri=boz_discovery_geturi(mgr, reg_id);
    CU_ASSERT(uri != 0);
    CU_ASSERT_STRING_EQUAL(uri, "tcp://toto:3142");
    CU_ASSERT(errno == 0);
    if(uri)
        free(uri);
    boz_discovery_unregister(mgr, reg_id);
    uri=boz_discovery_geturi(mgr, reg_id);
    CU_ASSERT(uri == 0);
    CU_ASSERT(errno == ENOENT);
    ret=boz_discovery_term(&mgr);
}

