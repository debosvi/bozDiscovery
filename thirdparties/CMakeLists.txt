
include(ExternalProject)

set(3RD_DL_DIR ${CMAKE_BINARY_DIR}/.support)

add_subdirectory(libsodium)
add_subdirectory(libzeromq)
add_subdirectory(libczmq)


set(SKA_PKG_DIR ${CMAKE_CURRENT_BINARY_DIR}/package)
set(SKARNET_STAGING_DIR ${CMAKE_CURRENT_BINARY_DIR}/skarnet)
set(SKARNET_SYSDEPS_DIR ${SKARNET_STAGING_DIR}/sysdeps)

add_subdirectory(skalibs)

