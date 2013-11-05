
set(PUBLISH_TOOL_NAME tool_publish)

set(PUBLISH_TOOL_SOURCES
    publish.c
    )
    
add_executable(${PUBLISH_TOOL_NAME} 
    ${PUBLISH_TOOL_SOURCES}
    )
target_link_libraries(${PUBLISH_TOOL_NAME}
    czmq
    )