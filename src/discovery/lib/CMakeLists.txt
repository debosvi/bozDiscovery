
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DISCOVERY_LIB_SOURCES
    internal.c
    init.c
    term.c
    startf.c
    end.c
    fd.c
    )
    
add_library(${DISCOVERY_LIB_NAME} SHARED
    ${DISCOVERY_LIB_SOURCES}
    )
target_link_libraries(${DISCOVERY_LIB_NAME}
    unixonacid.a datastruct.a random.a stdcrypto.a stddjb.a
    
    )
    
