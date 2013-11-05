set(DEFAULT_INSTALL_DIR ${CMAKE_BINARY_DIR}/.built)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEFAULT_INSTALL_DIR}/lib)
#     set(LINK_FLAGS -Xlinker -rpath-link -Xlinker ${DEFAULT_INSTALL_DIR}/lib )
set (EXECUTABLE_OUTPUT_PATH ${DEFAULT_INSTALL_DIR}/bin)

include_directories (${DEFAULT_INSTALL_DIR}/include)
link_directories (${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON) 
include(${CMAKE_CURRENT_LIST_DIR}/boz-vars.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-doc.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-test-macros.cmake)

include_directories (${HEADER_INSTALL_DIR})
link_directories (${LIBRARY_INSTALL_DIR})

macro(add_s6service svc_name svc_proc_name)
  message(STATUS "No process to supervise with project component ${svc_name}")
endmacro()

# if(${CMAKE_BUILD_TYPE} EQUAL RELEASE)
    ADD_CUSTOM_TARGET(strip
        COMMAND ${CMAKE_STRIP} *.so
        WORKING_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        COMMENT "Strip libs")
# endif()

