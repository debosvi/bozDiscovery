SHELL=/bin/bash -x
DOC_ROOT=$(shell pwd)
export DOC_OUTPUT=$(BUILD_OUTPUT)/doc
BOZ_DOXY_TEMPLATE:=$(BUILD_OUTPUT)/config/Doxyfile
#BOZ_DOXY_TEMPLATE:=boz_api.doxy
BOZ_DIR=$(CURDIR)/../..
BOZ_DOXY_SCRIPT=$(BOZ_DIR)/ext_build/doc/boz_doxy.sh
BOZ_PROJECT_NAME:=$(shell grep "project\?\s" ${BOZ_DIR}/CMakeLists.txt | \
		sed 's/project (\(.*\))/\1/g')
BOZ_DOXYFILE_PATTERN:=doc/Doxyfile
BOZ_DOXYFILES:=$(shell find $(BOZ_DIR) -wholename '*${BOZ_DOXYFILE_PATTERN}' | \
		tr '\n' ' ')
PHONY = ""

doc:
	@echo -e "Generating document [$(DOXY_CONFIG)] in $(DOC_OUTPUT) ..."	
	@make -C $(DOC_ROOT)/doxygen \
	DOXY_CONFIG=$(DOXY_CONFIG) \
	DOXY_TEMPLATE=$(BOZ_DOXY_TEMPLATE) \
	BOZ_DIR=$(shell echo $(DOXY_CONFIG) | sed -e s:$(BOZ_DOXYFILE_PATTERN)::) \
	OUTPUT_PATH=$(OUTPUT_PATH) \
	html

# all commands
all:    
	@echo -e "Doxyfiles $(BOZ_DOXYFILES)"
	@$(foreach doxyfile, $(BOZ_DOXYFILES), echo $(doxyfile); make OUTPUT_PATH=$(shell bash $(BOZ_DOXY_SCRIPT) $(doxyfile) $(DOC_OUTPUT)) DOXY_CONFIG=$(doxyfile) doc;)

clean:
	@echo -e "Removing doxygen doc files..."
	@rm -rf $(DOC_OUTPUT)

help:
	@echo ""
	@echo "================== MAKE DOC HELP ==================================="
	@echo "- make doc:       generate all documentation."
	@echo "- make doc_help:  show this help"
	@echo "===================================================================="
	@echo ""

PHONY: $(PHONY)
