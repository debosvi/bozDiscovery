# boz-web main makefile
#
SHELL=/bin/bash

export PROJECT_BASE_DIR=$(CURDIR)

export BUILD_OUTPUT:=$(PROJECT_BASE_DIR)/build

export BUILD_TYPE:=release

-include $(PROJECT_BASE_DIR)/.cmakebuilt
-include $(BUILD_OUTPUT)/.config
RM_OUTPUT:=0

ifdef O
  ifeq ("$(origin O)", "command line")
    BUILD_OUTPUT:=$(O)
    RM_OUTPUT:=1
  endif
endif

ifdef V
  ifeq ("$(origin V)", "command line")
     ifeq ("$(V)", "1")
	    VERBOSE:="VERBOSE=$(V)"
     endif
  endif
endif

export DOT_CONFIG:=$(BUILD_OUTPUT)/.config

MAKEFLAGS=--no-print-directory
BUILD_MAKEFILE=$(BUILD_OUTPUT)/Makefile

AUTOCONF:=$(BUILD_OUTPUT)/auto.conf
#AUTOCONF2:=$(BUILD_OUTPUT)/autoconf.h

default: help

debug release : prepare
	@cd $(BUILD_OUTPUT) && cmake -DBUILD_TYPE="$@" \
	-G"Unix Makefiles" $(PROJECT_BASE_DIR)
	@$(MAKE) $(VERBOSE)  all

include ext_build/Makefile.kc

ifeq ($(wildcard $(BUILD_OUTPUT)/Makefile),)

all : prepare
	@$(MAKE) $(VERBOSE)  build

prepare: $(BUILD_MAKEFILE)

.PHONY: build
build:
	@echo -e "Mandatory to use first 'make prepare'"

$(BUILD_OUTPUT):
	@mkdir -p $@
	@echo -e "BUILD_OUTPUT=$(BUILD_OUTPUT)" >> .cmakebuilt

$(BUILD_MAKEFILE): $(BUILD_OUTPUT)
	@cd $(BUILD_OUTPUT) && cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
	-G"Unix Makefiles" $(PROJECT_BASE_DIR)
	
.PHONY: clean
clean:
	@-rm -f $(BUILD_OUTPUT)/.config

else
# Cmake generated
all: build

prepare:
	@echo -e "Nothing to do, Cmake already generated"

.PHONY: clean
clean:
	@$(MAKE) $(VERBOSE) -C $(BUILD_OUTPUT) $@
	@-rm -f $(BUILD_OUTPUT)/.config

.PHONY: build
build:
ifeq ($(wildcard $(BUILD_OUTPUT)/config/autoconf.cmake),)
	@$(MAKE) $(VERBOSE) loadconfig
endif
	@$(MAKE) $(VERBOSE) -C $(BUILD_OUTPUT) all

endif

install:
	@$(MAKE) $(VERBOSE) -C $(BUILD_OUTPUT) install

help:
	@echo -e "################################################################################"
	@echo -e "#\t[Help page]"
	@echo -e "#"
	@echo -e "#\t\e[0;31m--Build targets--\e[0m"
	@echo -e "#\tall              :   build all libraries and tests."
	@echo -e "#\tclean            :   remove all built files (output build folder unset implicitly)."
	@echo -e "#"
	@echo -e "#\t\e[0;31m--Config targets--\e[0m"
	@echo -e "#\tmenuconfig       :   allows to customize $(PROJECT_NAME) (Curses interface). You have different mode see IMPORTANT REMARKS"
	@echo -e "#\txconfig          :   allows to customize $(PROJECT_NAME) (QT interface). You have different mode see IMPORTANT REMARKS"
	@echo -e "#\tloadconfig       :   allows load a prebuilt configuration file (see IMPORTANT REMARKS)."
	@echo -e "#\tstoreconfig      :   allows store a prebuilt configuration file (see IMPORTANT REMARKS)."
	@echo -e "#"
	@echo -e "#\t\e[0;31m--Build type targets--\e[0m"
	@echo -e "#\tdebug            :   compile $(PROJECT_NAME) in debug mode, you have debug option to configure with menuconfig or xconfig."
	@echo -e "#\trelease          :   compile $(PROJECT_NAME) in release mode, you can configure, with menuconfig or xconfig, release information."
	@echo -e "#"
	@echo -e "#\t\e[0;31m--Help and Doc targets--\e[0m"
	@echo -e "#\thelp             :   this help (\e[0;1;31mdefault target\e[0m)."
	@echo -e "#\tdoc_help         :   print help about all the make doc_* commands."
	@echo -e "#"
	@echo -e "#-------------------------------------------------------------------------------"
	@echo -e "#"
	@make help_kc
	@echo -e "#"
	@echo -e "#-------------------------------------------------------------------------------"
	@echo -e "#"
	@echo -e "#\t\e[0;1;31mIMPORTANT REMARKS :\e[0m"
	@echo -e "#"
	@echo -e "#\tYou can use \e[0;32mBOZ_KCONFIG\e[0m environment variable to select the current configuration file."
	@echo -e "#\tOtherwise your default '\e[0;32m.config\e[0m' file will be used."
	@echo -e "#"
	@echo -e "#\tYou can use command like \e[0;32m'make 0=<absolute somewhere> all'\e[0m to set the "
	@echo -e "#\toutput build directory. This is afterwards persistent until \e[0;32m'make clean'"
	@echo -e "#\tor 'make distclean'\e[0m has been performed"
	@echo -e "#"
	@echo -e "#\tBOZ_KCONFIG is currently set to: "
	@echo -e "#\t\t\e[0;36m$(BOZ_KCONFIG)\e[0m"
	@echo -e "#\tOutput build directory is currently set to: "
	@echo -e "#\t\t\e[0;36m$(BUILD_OUTPUT)\e[0m"
	@echo -e "#"
	@echo -e "#\tWhen you are using \e[0;32m'menuconfig'\e[0m or \e[0;32m'xconfig'\e[0m you can choose a mode"
	@echo -e "#\tby put a \e[0;32m'MODE'\e[0m parameter. You can just configure plateform information with \e[0;32m'MODE=PLT'\e[0m"
	@echo -e "#\tor just $(PROJECT_NAME) information with \e[0;32m'MODE=$(PROJECT_NAME)'\e[0m or both in one menu that is the default "
	@echo -e "#\tvalue or you can run \e[0;32m'MODE=BOTH'\e[0m"
	@echo -e "#\t\e[0;1;31mNB :\e[0m You have to run almost one PLT mode before running in $(PROJECT_NAME) mode"
	@echo -e "################################################################################"

cleanup:
	@find . -name '*~' -exec rm -rf {} \;

distclean:
	@-$(MAKE) $(VERBOSE) clean
	@$(MAKE) $(VERBOSE) kc-clean
	@rm -rf $(BUILD_OUTPUT)/* $(BUILD_OUTPUT)/.built
	@rm -f .cmakebuilt
	@rm -f $(BUILD_OUTPUT)/.config

.PHONY: doc
doc:
	@$(MAKE) -C ext_build/doc/ all

api:
	@echo "Make documentation" 
	@$(MAKE) $(VERBOSE) -C $(BUILD_OUTPUT) gendoc

%-doc :
	@$(MAKE) ${VERBOSE} -C $(BUILD_OUTPUT) $@


.PHONY: doc_%
doc_%:
	@$(MAKE) -C doc/ $(subst doc_,,$@)
