cmake_minimum_required (VERSION 2.8)
project (bozDiscovery)

include(project_ver.cmake)
include(ext_build/boz-build.cmake)
include(CTest)

include(tools.cmake)

#set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_subdirectory(include)

add_subdirectory(thirdparties)
add_subdirectory(src)
add_subdirectory(test)

add_test_if_enable(test BOZ_GLOBAL_TEST)

include(package/package.cmake)
