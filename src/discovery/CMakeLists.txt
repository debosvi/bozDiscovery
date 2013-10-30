

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DISCOVERY_LIB_NAME bozdiscovery)

set(DISCOVERY_LIB_SOURCES
    internal.c
    init.c
    term.c
    )
    
add_library(${DISCOVERY_LIB_NAME} SHARED
    ${DISCOVERY_LIB_SOURCES}
    )
target_link_libraries(${DISCOVERY_LIB_NAME}
    datastruct.a random.a stdcrypto.a stddjb.a
    
    )
    