
set_property(DIRECTORY PROPERTY EP_STEP_TARGETS configure build install test)

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(SKALIBS_PACKAGE skalibs-1.4.2)
set(SKALIBS_CONF_COMPILE ${SKA_PKG_DIR}/prog/${SKALIBS_PACKAGE}/conf-compile)
set(SKALIBS_OUTPUT_DIR ${SKARNET_STAGING_DIR}/skalibs)

ExternalProject_Add(${dirname}
#    DEPENDS             zeromq
    STAMP_DIR           ${CMAKE_CURRENT_BINARY_DIR}/stamps
    DOWNLOAD_DIR        ${3RD_DL_DIR}
    URL                 http://www.skarnet.org/software/skalibs/skalibs-1.4.2.tar.gz
    URL_MD5             e2bfa4447977024e1f2f91e9eb880baa
    SOURCE_DIR          "${SKA_PKG_DIR}/prog"
    BUILD_IN_SOURCE     0
    CONFIGURE_COMMAND  
        echo "${SKA_PKG_DIR}" > ${SKALIBS_CONF_COMPILE}/conf-sp_root &&
        echo "${DEFAULT_INSTALL_DIR}/command" >  ${SKALIBS_CONF_COMPILE}/conf-install-command &&
        echo "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/" >  ${SKALIBS_CONF_COMPILE}/conf-install-library &&
        echo "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/" >  ${SKALIBS_CONF_COMPILE}/conf-install-library.so &&
        echo "${DEFAULT_INSTALL_DIR}/include/skarnet" >  ${SKALIBS_CONF_COMPILE}/conf-install-include &&
        echo "${DEFAULT_INSTALL_DIR}/etc" >  ${SKALIBS_CONF_COMPILE}/conf-etc &&
        echo "${SKARNET_SYSDEPS_DIR}" >  ${SKALIBS_CONF_COMPILE}/conf-install-sysdeps &&
        rm -f ${SKALIBS_CONF_COMPILE}/flag-slashpackage
    BUILD_COMMAND
        mkdir -p ${DEFAULT_INSTALL_DIR}/etc &&
        make -C ${SKA_PKG_DIR}/prog/${SKALIBS_PACKAGE} 
    INSTALL_COMMAND make -C ${SKA_PKG_DIR}/prog/${SKALIBS_PACKAGE} install
    )
