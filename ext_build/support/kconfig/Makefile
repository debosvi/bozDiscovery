# $Id: Makefile 9417 2012-08-02 14:28:16Z g601456 $
#
# Makefile to install Intel SDK
# TODO: should be changed to platform independent...

SHELL=/bin/bash 

MAKEFLAGS=--no-print-directory

# -include $(DOT_CONFIG)
PROJECT_BASE_DIR?=$(shell pwd)

CC:=gcc
CXX:=g++
AR:=ar
GPERF:=gcc

CFLAGS=-Wall -O2

# used in internally Kconfig c files
CFLAGS+=-DCONFIG_PROJNAME=\"$(PROJECT_NAME)\"

CXXFLAGS=-Wall -O2
CXXFLAGS=-DCONFIG_PROJNAME=\"$(PROJECT_NAME)\"

FOUND_BISON=$(shell which bison)
FOUND_FLEX=$(shell which flex)
FOUND_GPERF=$(shell which gperf)

# Kconfig main variables
KCONFIG_DIR=$(PROJECT_BASE_DIR)/ext_build/support/kconfig
KCONFIG_OUT=$(BUILD_OUTPUT)/include/config
KCONFIG_GEN=$(BUILD_OUTPUT)/include/generated

KCONFIG_PARSER_GEN=y

KCONFIG_ZCONF_PARSER_FILE=$(KCONFIG_DIR)/zconf.tab.c
KCONFIG_ZCONF_FLEX_FILE=$(KCONFIG_DIR)/lex.zconf.c
KCONFIG_ZCONF_HASH_FILE=$(KCONFIG_DIR)/zconf.hash.c
KCONFIG_ZCONF_YACC=$(KCONFIG_DIR)/zconf.y
KCONFIG_ZCONF_FLEX=$(KCONFIG_DIR)/zconf.l
KCONFIG_ZCONF_GPERF=$(KCONFIG_DIR)/zconf.gperf

KCONFIG_TOOL_CONF=$(BUILD_OUTPUT)/conf
KCONFIG_TOOL_MCONF=$(BUILD_OUTPUT)/mconf
KCONFIG_TOOL_QCONF=$(BUILD_OUTPUT)/qconf
KCONFIG_TOOL_NCONF=$(BUILD_OUTPUT)/nconf

KCONFIG_LXDIALOG_LIST=$(wildcard $(KCONFIG_DIR)/lxdialog/*.c)

clean_files:=

all: help

-include $(BUILD_OUTPUT)/.kcclean

rebuild:
	@echo -e "Generates inbuild Kconfig copy (parsing internal KCFG_DIR_REPLACE variable)"
clean_files+=$(BUILD_OUTPUT)/.kcgen
clean_files+=$(BUILD_OUTPUT)/.kcclean

$(KCONFIG_OUT) $(KCONFIG_GEN):
	@mkdir -p $@

chk_err:=$(wildcard $(KCONFIG_OUT)/.tool_error)

ifeq ("$(KCONFIG_PARSER_GEN)", "y")

check: $(BUILD_OUTPUT)/include/config rebuild
ifeq ("$(FOUND_BISON)", "")
	@echo -e "Bison tool not installed!!"
	@touch $(KCONFIG_OUT)/.tool_error
endif
ifeq ("$(FOUND_FLEX)", "")
	@echo -e "Flex tool not installed!!"
	@touch $(KCONFIG_OUT)/.tool_error
endif
ifeq ("$(FOUND_GPERF)", "")
	@echo -e "GPerf tool not installed!!"
	@touch $(KCONFIG_OUT)/.tool_error
endif
ifneq ($(chk_err),)
	@echo -e "Please check missing tool(s)!"
	@rm $(KCONFIG_OUT)/.tool_error
	@exit 1
endif

$(KCONFIG_ZCONF_FLEX_FILE): $(KCONFIG_ZCONF_FLEX)
# 	@echo -e "Perform flex"
	@flex -o $@ $(KCONFIG_ZCONF_FLEX)

$(KCONFIG_ZCONF_PARSER_FILE): $(KCONFIG_ZCONF_YACC) $(KCONFIG_ZCONF_FLEX_FILE) $(KCONFIG_ZCONF_HASH_FILE)
# 	@echo -e "Perform bison"
	@bison -l -b zconf -p zconf $(KCONFIG_ZCONF_YACC) -o $@

$(KCONFIG_ZCONF_HASH_FILE): $(KCONFIG_ZCONF_GPERF)
# 	@echo -e "Perform gperf"
	@gperf < $(KCONFIG_ZCONF_GPERF) > $@

else

$(KCONFIG_ZCONF_PARSER_FILE):
	@cp -v $(KCONFIG_ZCONF_PARSER_FILE)_shipped $@

$(KCONFIG_ZCONF_FLEX_FILE):
	@cp -v $(KCONFIG_ZCONF_FLEX_FILE)_shipped $@

$(KCONFIG_ZCONF_HASH_FILE):
	@cp -v $(KCONFIG_ZCONF_HASH_FILE)_shipped $@

endif

# $(KCONFIG_TOOL_QCONF): $(BUILD_OUTPUT)/.tmp_qtcheck
-include $(BUILD_OUTPUT)/.tmp_qtcheck

ifeq ($(MAKECMDGOALS),xconfig)
$(BUILD_OUTPUT)/.tmp_qtcheck:
	@set -e; echo "  CHECK   qt"; dir=""; pkg=""; \
	if ! pkg-config --exists QtCore 2> /dev/null; then \
	    echo "* Unable to find the QT4 tool qmake. Trying to use QT3"; \
	    pkg-config --exists qt 2> /dev/null && pkg=qt; \
	    pkg-config --exists qt-mt 2> /dev/null && pkg=qt-mt; \
	    if [ -n "$$pkg" ]; then \
	      cflags="\$$(shell pkg-config $$pkg --cflags)"; \
	      libs="\$$(shell pkg-config $$pkg --libs)"; \
	      moc="\$$(shell pkg-config $$pkg --variable=prefix)/bin/moc"; \
	      dir="$$(pkg-config $$pkg --variable=prefix)"; \
	    else \
	      for d in $$QTDIR /usr/share/qt* /usr/lib/qt*; do \
	        if [ -f $$d/include/qconfig.h ]; then dir=$$d; break; fi; \
	      done; \
	      if [ -z "$$dir" ]; then \
	        echo >&2 "*"; \
	        echo >&2 "* Unable to find any QT installation. Please make sure that"; \
	        echo >&2 "* the QT4 or QT3 development package is correctly installed and"; \
	        echo >&2 "* either qmake can be found or install pkg-config or set"; \
	        echo >&2 "* the QTDIR environment variable to the correct location."; \
	        echo >&2 "*"; \
	        false; \
	      fi; \
	      libpath=$$dir/lib; lib=qt; osdir=""; \
	      $(HOSTCXX) -print-multi-os-directory > /dev/null 2>&1 && \
	        osdir=x$$($(HOSTCXX) -print-multi-os-directory); \
	      test -d $$libpath/$$osdir && libpath=$$libpath/$$osdir; \
	      test -f $$libpath/libqt-mt.so && lib=qt-mt; \
	      cflags="-I$$dir/include"; \
	      libs="-L$$libpath -Wl,-rpath,$$libpath -l$$lib"; \
	      moc="$$dir/bin/moc"; \
	    fi; \
	    if [ ! -x $$dir/bin/moc -a -x /usr/bin/moc ]; then \
	      echo "*"; \
	      echo "* Unable to find $$dir/bin/moc, using /usr/bin/moc instead."; \
	      echo "*"; \
	      moc="/usr/bin/moc"; \
	    fi; \
	else \
	  cflags="\$$(shell pkg-config QtCore QtGui Qt3Support --cflags)"; \
	  libs="\$$(shell pkg-config QtCore QtGui Qt3Support --libs)"; \
	  moc="\$$(shell pkg-config QtCore --variable=moc_location)"; \
	  [ -n "$$moc" ] || moc="\$$(shell pkg-config QtCore --variable=prefix)/bin/moc"; \
	fi; \
	echo "KC_QT_CFLAGS=$$cflags" > $@; \
	echo "KC_QT_LIBS=$$libs" >> $@; \
	echo "KC_QT_MOC=$$moc" >> $@

endif

clean_files+=$(BUILD_OUTPUT)/.tmp_qtcheck

%.moc: $(KCONFIG_DIR)/%.h
	@$(KC_QT_MOC) -i $< -o $@

$(BUILD_OUTPUT)/kconfig_load.o: kconfig_load.c
	@$(CC) $(CFLAGS) -o $@ -c  $<

$(BUILD_OUTPUT)/zconf.tab.o: $(KCONFIG_ZCONF_PARSER_FILE)
	@$(CC) $(CFLAGS) -o $@ -c  $<

clean_files+=$(BUILD_OUTPUT)/zconf.tab.o $(BUILD_OUTPUT)/kconfig_load.o qconf.moc

genconf: check $(KCONFIG_OUT) $(KCONFIG_TOOL)
ifeq ("$(BUILD_TYPE)", "")
	@echo "Please set a build type by running one of the following target : prepare, debug, release"
else
	@$(CURDIR)/createKconfig.sh $(BUILD_OUTPUT) $(PROJECT_BASE_DIR) $(PROJECT_BASE_DIR)/config/Config.in
#	@$(CURDIR)/genconf.sh $(BUILD_OUTPUT) $(BUILD_TYPE) Config.in
	@cd $(BUILD_OUTPUT) && mkdir -p config && BOZ_KCONFIG_AUTOCONFIG=$(BUILD_OUTPUT)/config/auto.conf	\
		BOZ_KCONFIG_AUTOHEADER=$(BUILD_OUTPUT)/config/autoconf.h	\
		$(KCONFIG_TOOL) $(KCONFIG_OPT) $(BUILD_OUTPUT)/Kconfig 
	@$(MAKE) translate
endif


$(KCONFIG_TOOL_CONF): $(KCONFIG_ZCONF_PARSER_FILE)
	@$(CC) $(CFLAGS) -o $@ $(KCONFIG_DIR)/conf.c $(KCONFIG_ZCONF_PARSER_FILE)

$(KCONFIG_TOOL_NCONF): $(KCONFIG_ZCONF_PARSER_FILE)
	@$(CC) $(CFLAGS) -o $@ $(KCONFIG_DIR)/nconf.c $(KCONFIG_ZCONF_PARSER_FILE)

$(KCONFIG_TOOL_MCONF): $(KCONFIG_ZCONF_PARSER_FILE) $(KCONFIG_ZCONF_FLEX_FILE) $(KCONFIG_ZCONF_HASH_FILE)
	@$(CC) $(CFLAGS) -DCURSES_LOC="<ncurses.h>" -o $@ $(KCONFIG_DIR)/mconf.c $(KCONFIG_ZCONF_PARSER_FILE) $(KCONFIG_LXDIALOG_LIST) -lncurses

$(KCONFIG_TOOL_QCONF): $(BUILD_OUTPUT)/.tmp_qtcheck qconf.moc $(KCONFIG_DIR)/lkc_defs.h $(BUILD_OUTPUT)/kconfig_load.o $(BUILD_OUTPUT)/zconf.tab.o
	$(CXX) $(CXXFLAGS) $(KC_QT_CFLAGS) -o $@ qconf.cc  $(BUILD_OUTPUT)/kconfig_load.o $(BUILD_OUTPUT)/zconf.tab.o -DLKC_DIRECT_LINK $(KC_QT_LIBS) -ldl

config:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) BUILD_TYPE=$(BUILD_TYPE) genconf

menuconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_MCONF) BUILD_TYPE=$(BUILD_TYPE) genconf

xconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_QCONF) BUILD_TYPE=$(BUILD_TYPE) genconf

defconfig:
ifeq ($(KBUILD_DEFCONFIG),)
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-d genconf
else
	@echo "*** Default configuration is based on '$(KBUILD_DEFCONFIG)'"
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT="-D $(KBUILD_DEFCONFIG)" genconf
endif

randconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-r genconf

allyesconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-y genconf

allnoconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-n genconf

allmodconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-m genconf

oldconfig:
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-o genconf

silentoldconfig: $(KCONFIG_GEN)
	@$(MAKE) KCONFIG_TOOL=$(KCONFIG_TOOL_CONF) KCONFIG_OPT=-s genconf

translate:
	@${KCONFIG_DIR}/autoconf_tocmake.sh ${BUILD_OUTPUT}/config/auto.conf ${BUILD_OUTPUT}/config/autoconf.cmake
	@${KCONFIG_DIR}/autoconf_todoxy.sh ${BUILD_OUTPUT}/config/auto.conf ${BUILD_OUTPUT}/config/autoconf.doxy
	@${KCONFIG_DIR}/autoconf_tostrconfig.sh ${BUILD_OUTPUT}/config/auto.conf ${BUILD_OUTPUT}/config/config.h
	@${KCONFIG_DIR}/autoconf_toprojectenv.sh ${BUILD_OUTPUT}/config/auto.conf ${BUILD_OUTPUT}/config/project_env.sh
	@${KCONFIG_DIR}/autoconf_tojson.sh ${BUILD_OUTPUT}/config/auto.conf ${KCONFIG_DIR}/doc2json.conf ${BUILD_OUTPUT}/config/pdfdocs.json

help:
	@echo -e "################################################################################"
	@echo -e "#\t[Help page]\t\e[0;32mKconfig tools\e[0m"
	@echo -e "#"
	@echo -e "#\t\e[0;31m--Build targets--\e[0m"
	@echo -e "#\tdefconfig      :   build with default settings"
	@echo -e "#\t                   (variable \e[0;32mKBUILD_DEFCONFIG MUST\e[0m be set to defaut configuration file)."
	@echo -e "#\tmenuconfig     :   allows to customize "$(PROJECT_NAME)" (Curses interface)."
	@echo -e "#\txconfig        :   allows to customize "$(PROJECT_NAME)" (QT interface)."
	@echo -e "#\tothers         :   must be reimplemented further."
	@echo -e "#\tclean          :   clean all files."
	@echo -e "#"
	@echo -e "################################################################################"

clean:
	@rm -rfv $(BUILD_OUTPUT)/include
	@rm -fv $(KCONFIG_ZCONF_PARSER_FILE) $(KCONFIG_ZCONF_FLEX_FILE) $(KCONFIG_ZCONF_HASH_FILE)
	@rm -fv $(KCONFIG_TOOL_CONF) $(KCONFIG_TOOL_MCONF) $(KCONFIG_TOOL_QCONF)
	@rm -fv $(BUILD_OUTPUT)/kconfig/autoconf.* $(BUILD_OUTPUT)/kconfig/auto.conf
	@rm -rfv $(clean_files)
