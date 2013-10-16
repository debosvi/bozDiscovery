#!/bin/bash
# $HeadURL: http://forge-urd44.osn.sagem/svn/sc.stb-lib-opal/BO/branches/BO_sc.stb-lib-opal/scripts/kconfig/autoconf_tocmake.sh $
# $Id: autoconf_tocmake.sh 4479 2011-07-19 12:45:52Z g093246 $

sed -e "/^#/d" -e "s/\(.*\)=\(.*\)/set (\1 \2)/g" $1 > $2
