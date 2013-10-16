#
# The boz-doc.cmake file contains macros used to ease the generation of
# doxygen documentation through the gendoc target.
#

# Plantuml is a tool used to generate images from sources files.
set (PLANTUML_JAR ${PROJECT_SOURCE_DIR}/ext_build/doc/tools/plantuml.jar )
# Path where the plantuml images will be genrated.
set (BOZ_IMAGES_PATH ${CMAKE_BINARY_DIR}/images)
# BOZ Logo path.
set (BOZ_LOGO_IMAGE ${PROJECT_SOURCE_DIR}/ext_build/doc/res/bozlogo.png )

# Parse the template doxyfile to integrate cmake variables.
configure_file(ext_build/doc/doxygen/config/boz_api.doxy
	${CMAKE_BINARY_DIR}/config/Doxyfile 
        @ONLY
)

# gendoc target.
add_custom_target(gendoc
	COMMAND echo "make api to doc"
)

# TARGET-doc target.
macro (BOZ_DOC_DECL TARGET DOXYFILE)
        find_package(Java)
	add_custom_target(${TARGET}-doc
		COMMAND echo "MAKE DOC"
		COMMAND echo " ${JAVA_RUNTIME} -Djava.awt.headless=true -jar ${PLANTUML_JAR} -v -o ${BOZ_IMAGES_PATH} '${CMAKE_CURRENT_SOURCE_DIR}/../**.(c|h|cpp|hpp|uml)' "
		COMMAND ${JAVA_RUNTIME} -Djava.awt.headless=true -jar ${PLANTUML_JAR} -v -o ${BOZ_IMAGES_PATH} '${CMAKE_CURRENT_SOURCE_DIR}/../**.\(c|h|cpp|hpp|uml\)'
		COMMAND echo "DOXY_TEMPLATE=${CMAKE_BINARY_DIR}/config/Doxyfile doxygen ${CMAKE_CURRENT_SOURCE_DIR}/${DOXYFILE}"
		COMMAND DOXY_TEMPLATE=${CMAKE_BINARY_DIR}/config/Doxyfile BOZ_DIR=${CMAKE_CURRENT_SOURCE_DIR}/.. DOC_OUTPUT=${CMAKE_CURRENT_BINARY_DIR} doxygen  ${CMAKE_CURRENT_SOURCE_DIR}/${DOXYFILE}
		)
	add_dependencies(gendoc ${TARGET}-doc)
endmacro(BOZ_DOC_DECL)


