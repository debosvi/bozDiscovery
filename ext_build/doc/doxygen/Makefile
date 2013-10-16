# Makefile -- 
#
# Copyright (c) 2010 Sagemcom Broadband
#
# The computer program contained herein contains proprietary
# information which is the property of Sagemcom Broadband.
# The program may be used and/or copied only with the written 
# permission of Sagemcom Broadband or in accordance with the
# terms and conditions stipulated in the agreement/contract under
# which the programs have been supplied.
#

# Input of this Makefile
# ======================
#
# Path of the *.doxy or *.dox file
# DOXY_CONFIG =
#
# List of HTML images to include into the output html path
# HTML_IMG = 
#
# List of HTML images to include into the output html path
# LATEX_IMG = 
#
# List of HTML images to include into the output html path
# RTF_IMG =
#
# Output Absolute Path
# OUTPUT_PATH =
#
# Name of the HTML directory (relative)
# HTML_DIR = (default is html)
# The HTML Output directory will be OUTPUT_PATH/HTML_DIR
#
# Name of the LATEX directory (relative)
# LATEX_DIR = (default is latex)
# The LATEX Output directory will be OUTPUT_PATH/LATEX_DIR
#
# Name of the RTF directory (relative)
# RTF_DIR = (default is rtf)
# The RTF Output directory will be OUTPUT_PATH/RTF_DIR
#
#
# Rules
# =====
#
# doxygen: generate the html/latex/rtf code without images and style installation
# html: execute doxygen rules and install html images and styles
# latex: execute doxygen rules and install latex images and styles
# pdf: generate the latex code and compile to generate the pdf file
# rtf:  execute doxygen rules and install rtf images and styles
# all: execute all stuff
#
# no clean: in charge of the caller

ifeq ($(HTML_DIR),)
  HTML_DIR=html
endif

HTML_PATH=$(OUTPUT_PATH)/$(HTML_DIR)
TOPDIR=$(shell echo `pwd`)

DOXYGEN=doxygen

all: doxygen html

doxygen:
	@if [ -f $(DOXY_CONFIG) ]; then \
    TOPDIR=$(TOPDIR) $(DOXYGEN) $(DOXY_CONFIG) || exit 1; \
  fi;

$(HTML_PATH):
	@if [ -f $(DOXY_CONFIG) ]; then \
    mkdir -p $(HTML_PATH); \
  fi;

html:$(HTML_PATH) doxygen
#	@if [ -f $(DOXY_CONFIG) ]; then \
#    cp $(TOPDIR)/img/sc_*.png $(HTML_PATH); \
#    cp $(TOPDIR)/img/tab_*.png $(HTML_PATH); \
#    cp $(TOPDIR)/img/nav_*.png $(HTML_PATH); \
#    cp $(TOPDIR)/html/tabs.css $(HTML_PATH); \
#    if [ "$(HTML_IMG)" != "" ]; then \
#      cp $(HTML_IMG) $(HTML_PATH); \
#    fi; \
#  fi;

PHONY: $(PHONY)
