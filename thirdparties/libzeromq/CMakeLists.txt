
set_property(DIRECTORY PROPERTY EP_STEP_TARGETS download autogen configure build test)

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
ExternalProject_Add(${dirname}
    STAMP_DIR           ${CMAKE_BINARY_DIR}/.stamps
    DOWNLOAD_DIR        ${3RD_DL_DIR}
    URL                 http://download.zeromq.org/zeromq-4.0.1.tar.gz
    URL_MD5             e738c310d135e20fa48c5b348da18e22
    SOURCE_DIR          ${CMAKE_CURRENT_BINARY_DIR}/src
    BUILD_IN_SOURCE     1
    CONFIGURE_COMMAND   ./configure --prefix=${DEFAULT_INSTALL_DIR} --with-system-pgm --enable-static --enable-shared
)
    
ExternalProject_Add_Step(${dirname} autogen                 # Names of project and custom step
    COMMAND             ./autogen.sh                        # Command line invoked by this step
    COMMENT             "Performing autogen step for 'libzeromq'"           # Text printed when step executes
    DEPENDEES           download                            # Steps on which this step depends
    DEPENDERS           build                               # Steps that depend on this step
#     [DEPENDS files...]        # Files on which this step depends
#     [ALWAYS 1]                # No stamp file, step always runs
    WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}/src     # Working directory for command
#     [LOG 1]                   # Wrap step in script to log output
    )
