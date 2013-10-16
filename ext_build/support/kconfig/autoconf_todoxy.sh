#!/bin/bash
# $HeadURL: http://forge-urd44.osn.sagem/svn/sc.stb-lib-opal/BO/branches/BO_sc.stb-lib-opal/scripts/kconfig/autoconf_todoxy.sh $
# $Id: autoconf_todoxy.sh 4479 2011-07-19 12:45:52Z g093246 $

sed -e "/^#/d" -e "s/^/PREDEFINED += /g" $1 > $2
