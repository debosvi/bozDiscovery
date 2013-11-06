
set(CU_TEST_NAME cu_discovery)

set(CU_TEST_SOURCES
    cu_suite.c
    cu_main.c
    cu_init_term.c
    cu_register.c
    cu_unregister.c
    cu_geturi.c
    )
    
add_executable(${CU_TEST_NAME} 
    ${CU_TEST_SOURCES}
    )
target_link_libraries(${CU_TEST_NAME}
    bozdiscovery
    cunit
    )
