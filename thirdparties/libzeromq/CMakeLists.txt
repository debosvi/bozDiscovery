
set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build test)

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
ExternalProject_Add(${dirname}
    DEPENDS             libsodium
    STAMP_DIR           ${CMAKE_CURRENT_BINARY_DIR}/stamps
    DOWNLOAD_DIR        ${3RD_DL_DIR}
    URL                 http://download.zeromq.org/zeromq-4.0.1.tar.gz
    URL_MD5             e738c310d135e20fa48c5b348da18e22
    SOURCE_DIR          ${CMAKE_CURRENT_BINARY_DIR}/src
    BUILD_IN_SOURCE     1
    CONFIGURE_COMMAND   PKG_CONFIG_PATH=${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig && ./configure --prefix=${DEFAULT_INSTALL_DIR} --enable-static 
    )