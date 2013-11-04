
set(USR_DIR /usr/share/boz)
if(NOT "${BOZ_WIDE_GLOBAL_PATH}" STREQUAL "")
	set(USR_DIR ${BOZ_WIDE_GLOBAL_PATH})
endif()
message(STATUS "Global install path: " ${USR_DIR})


set(BINARY_INSTALL_DIR ${USR_DIR}/bin)
set(LIBRARY_INSTALL_DIR ${USR_DIR}/lib)
set(HEADER_INSTALL_DIR ${USR_DIR}/include)
set(LOG_INSTALL_DIR ${USR_DIR}/log)
set(BOZ_WEB_ROOT_DIR ${USR_DIR}/www)
set(CONFIG_INSTALL_DIR ${USR_DIR}/configs)
set(SCRIPT_INSTALL_DIR ${USR_DIR}/scripts)
set(SERVICES_INSTALL_DIR ${USR_DIR}/s6-services)
set(SERVICE_READY_DIR /tmp/s6-services)
set(SERVICE_SCAN_DIR /tmp/s6-service)
set(SERVICES_LOG_INSTALL_DIR ${LOG_INSTALL_DIR}/s6-services)
set(BOZ_CONFIG_DIR ${CMAKE_BINARY_DIR}/config)
set(LOAD_CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH ${LIBRARY_INSTALL_DIR})
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

option(BUILD_TYPE "Which build type to generate" "debug")
         
if("${BUILD_TYPE}" STREQUAL "release")
    set(CMAKE_BUILD_TYPE RELEASE)
elseif("${BUILD_TYPE}" STREQUAL "debug")
    set(CMAKE_BUILD_TYPE DEBUG)
else()
    set(CMAKE_BUILD_TYPE DEBUG)
endif()

message(STATUS "Build mode: "${CMAKE_BUILD_TYPE})

if(EXISTS "${LOAD_CONFIG_DIR}/Config.in")
add_definitions(-include ${CMAKE_BINARY_DIR}/config/config.h )
endif()

add_definitions(-Wall -Wextra )

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_C_FLAGS_RELEASE "-O2 -Werror")

set(CMAKE_C_FLAGS "-Wmissing-prototypes -Wbad-function-cast -Wshadow -Wfloat-equal")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wswitch-default")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdeclaration-after-statement")
add_definitions(-Wmissing-declarations -Wwrite-strings )
add_definitions(-Wunknown-pragmas)
add_definitions(-Wformat-security)
add_definitions(-Wstrict-aliasing -Wreturn-type -Wmissing-noreturn)
