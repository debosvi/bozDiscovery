
set(DISCOVERY_TEST_NAME test_discovery)

set(DISCOVERY_TEST_SOURCES
    basic.c
    )
    
add_executable(${DISCOVERY_TEST_NAME} 
    ${DISCOVERY_TEST_SOURCES}
    )
target_link_libraries(${DISCOVERY_TEST_NAME}
    bozdiscovery
    )