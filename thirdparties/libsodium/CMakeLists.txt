
set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build test)

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
ExternalProject_Add(${dirname}
    STAMP_DIR           ${CMAKE_CURRENT_BINARY_DIR}/stamps
    DOWNLOAD_DIR        ${3RD_DL_DIR}
    URL                 http://download.libsodium.org/libsodium/releases/libsodium-0.4.5.tar.gz
    URL_MD5             3a97d2c29ec0133e334036e3f19d0741
    SOURCE_DIR          ${CMAKE_CURRENT_BINARY_DIR}/src
    BUILD_IN_SOURCE     1
    CONFIGURE_COMMAND   ./configure --prefix=${DEFAULT_INSTALL_DIR} --enable-static --disable-shared
    )