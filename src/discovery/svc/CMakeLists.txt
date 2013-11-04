
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DISCOVERY_SVC_SOURCES
    main.c
    )

add_executable(${DISCOVERY_SVC_NAME} 
    ${DISCOVERY_SVC_SOURCES}
    )
target_link_libraries(${DISCOVERY_SVC_NAME}
    unixonacid.a stddjb.a
    #datastruct.a random.a stdcrypto.a stddjb.a

    )


