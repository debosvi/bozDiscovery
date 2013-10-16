macro(add_test_if_enable dir var)
    if("${var}" STREQUAL "y")
        add_subdirectory(${dir})
    endif()
endmacro()

macro(boz_add_test comp uc )
    string(TOUPPER ${comp} RTD_TEST_COMP)
    add_executable(boz-${comp}-test-uc${uc} test_boz_${comp}_uc${uc}.c)
    target_link_libraries(boz-${comp}-test-uc${uc} ${ARGN})
    add_test(boz-${comp}-test-uc${uc} boz-${comp}-test-uc${uc})
endmacro(boz_add_test c)