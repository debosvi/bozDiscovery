
#include "cu_discovery.h"

int main() {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if (
        (NULL == CU_add_test(pSuite, "test of init args", test_init_args))
        || (NULL == CU_add_test(pSuite, "test of term args", test_term_args))
        || (NULL == CU_add_test(pSuite, "test of register args", test_register_args))
        || (NULL == CU_add_test(pSuite, "test of unregister args", test_unregister_args))
        || (NULL == CU_add_test(pSuite, "test of geturi args", test_geturi_args))
        ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_list_tests_to_file();
    CU_automated_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
