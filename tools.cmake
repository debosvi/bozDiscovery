find_package(LibXml2 REQUIRED)
message(STATUS "libxml2 headers path: "${LIBXML2_INCLUDE_DIR})
include_directories(${LIBXML2_INCLUDE_DIR})

find_package(Skarnet REQUIRED)
message(STATUS "Skarnet found: " ${SKARNET_VERSION_STRING})
include_directories(${SKARNET_INCLUDE_DIRS})
link_directories(${SKARNET_LIBRARY_DIRS})

include_directories(${HEADER_INSTALL_DIR})
