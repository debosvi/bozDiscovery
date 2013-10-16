
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON) 
include(${CMAKE_CURRENT_LIST_DIR}/boz-vars.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-doc.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-test-macros.cmake)

include_directories (${HEADER_INSTALL_DIR})
link_directories (${LIBRARY_INSTALL_DIR})

macro(add_s6service svc_name svc_proc_name)
  message(STATUS "No process to supervise with project component ${svc_name}")
endmacro()
