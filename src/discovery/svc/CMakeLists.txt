
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DISCOVERY_SVC_SOURCES
    global.c
    main.c
    )

add_executable(${DISCOVERY_SVC_NAME} 
    ${DISCOVERY_SVC_SOURCES}
    )
target_link_libraries(${DISCOVERY_SVC_NAME}
    #datastruct.a random.a stdcrypto.a 
    unixonacid.a stddjb.a
    czmq zmq
    pthread

    )
    