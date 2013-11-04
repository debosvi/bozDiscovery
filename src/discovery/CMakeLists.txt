
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_definitions(-DBOZDISCO_PROG="boz-bozdiscd")

set(DISCOVERY_LIB_NAME bozdiscovery)
set(DISCOVERY_SVC_NAME boz-bozdiscd)

add_subdirectory(lib)
add_subdirectory(svc)
