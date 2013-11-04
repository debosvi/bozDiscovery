
set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build test)

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
ExternalProject_Add(${dirname}
    DEPENDS             libzeromq
    STAMP_DIR           ${CMAKE_CURRENT_BINARY_DIR}/stamps
    DOWNLOAD_DIR        ${3RD_DL_DIR}
    URL                 http://download.zeromq.org/czmq-2.0.2.tar.gz
    URL_MD5             8077f31d50eb8490c8a1bc2860a9e69e
    SOURCE_DIR          ${CMAKE_CURRENT_BINARY_DIR}/src
    BUILD_IN_SOURCE     1
    CONFIGURE_COMMAND   ./configure --prefix=${DEFAULT_INSTALL_DIR} --with-libzmq=${DEFAULT_INSTALL_DIR} --enable-static --disable-shared
    )