
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DISCOVERY_SVC_SOURCES
    global.c
    sync.c
    init.c 
    term.c
    addnode.c
    delnode.c
    main.c
    )

add_executable(${DISCOVERY_SVC_NAME} 
    ${DISCOVERY_SVC_SOURCES}
    )
target_link_libraries(${DISCOVERY_SVC_NAME}
    #random.a stdcrypto.a 
    datastruct.a unixonacid.a stddjb.a
    czmq zmq
    pthread

    )
    