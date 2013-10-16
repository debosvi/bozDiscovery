SHELL=/bin/bash -x
DOC_ROOT=$(shell pwd)
export DOC_OUTPUT=$(BUILD_OUTPUT)/doc
RTD_DOXY_TEMPLATE:=$(BUILD_OUTPUT)/config/Doxyfile
#RTD_DOXY_TEMPLATE:=boz_api.doxy
RTD_DIR=$(CURDIR)/../..
RTD_DOXY_SCRIPT=$(RTD_DIR)/ext_build/doc/boz_doxy.sh
RTD_PROJECT_NAME:=$(shell grep "project\?\s" ${RTD_DIR}/CMakeLists.txt | \
		sed 's/project (\(.*\))/\1/g')
RTD_DOXYFILE_PATTERN:=doc/Doxyfile
RTD_DOXYFILES:=$(shell find $(RTD_DIR) -wholename '*${RTD_DOXYFILE_PATTERN}' | \
		tr '\n' ' ')
PHONY = ""

doc:
	@echo -e "Generating document [$(DOXY_CONFIG)] in $(DOC_OUTPUT) ..."	
	@make -C $(DOC_ROOT)/doxygen \
	DOXY_CONFIG=$(DOXY_CONFIG) \
	DOXY_TEMPLATE=$(RTD_DOXY_TEMPLATE) \
	RTD_DIR=$(shell echo $(DOXY_CONFIG) | sed -e s:$(RTD_DOXYFILE_PATTERN)::) \
	OUTPUT_PATH=$(OUTPUT_PATH) \
	html

# all commands
all:    
	@echo -e "Doxyfiles $(RTD_DOXYFILES)"
	@$(foreach doxyfile, $(RTD_DOXYFILES), echo $(doxyfile); make OUTPUT_PATH=$(shell bash $(RTD_DOXY_SCRIPT) $(doxyfile) $(DOC_OUTPUT)) DOXY_CONFIG=$(doxyfile) doc;)

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
