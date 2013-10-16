#!/bin/bash

BINDIR=$1
BUILDTYPE=$2

function findInFile()
{
	mod=$1
    while read line ; do
	    b=`echo BUILD_MODULE_$mod`
	    if [ "$line" == "$b" ]; then
	        return 1
	    fi
    done < $BINDIR/var
    return 0

}

if [ "$#" == 3 ]; then

    echo -e "\nconfig BUILD_MODE_debug \n\tbool\n " >> $BINDIR/Kconfig
    if [ "$BUILDTYPE" == "debug" ]; then
        echo -e "\t default y" >> $BINDIR/Kconfig
    else
        echo -e "\t default n" >> $BINDIR/Kconfig
    fi
else

	rm -f $BINDIR/Kconfig.opal.tmp

	echo -e "config BUILD_MODE_debug \n\tbool\n " > $BINDIR/Kconfig.opal.tmp
	if [ "$BUILDTYPE" == "debug" ]; then
		echo -e "\t default y" >> $BINDIR/Kconfig.opal.tmp
	else
	    echo -e "\t default n" >> $BINDIR/Kconfig.opal.tmp
	fi
	i=0
	while read line ; do
	    index1=`expr index "$line" = ;`
	    if [ $index1     -ne 0 ]; then
	        configname=`echo ${line:7:$index1 - 1 - 7}`
	        value=`echo ${line:$index1}`
	        if [ "$configname" == "ARCH_UPPER_STRING" ]; then
	        	ind=`expr length "$value"`
	        	val=${value:1:$ind - 2}
	        	echo -e "comment \"Platform is $val\"\n\n\n" >> $BINDIR/Kconfig.opal.tmp
	        fi
            if [ "$configname" == "INTEL_SDK_DIR" ]; then
                ind=`expr length "$value"`
                val=${value:1:$ind - 2}
                echo -e "comment \"Toolchain is $val\"\n\n\n" >> $BINDIR/Kconfig.opal.tmp
            fi
	        echo -e "$configname" >> $BINDIR/var
	        echo "config $configname" >> $BINDIR/Kconfig.opal.tmp
	        index=`expr index "$value" \" ;`
	        if [ $index -ne 0 ]; then
	            echo -e "\t string" >> $BINDIR/Kconfig.opal.tmp
	        else
	            echo -e "\t bool" >> $BINDIR/Kconfig.opal.tmp
	        fi
	        echo -e "\t default $value" >> $BINDIR/Kconfig.opal.tmp
	        echo  >> $BINDIR/Kconfig.opal.tmp
	        i=$(($i + 1))
	    fi
	done < $BINDIR/auto_plt.conf

	for value in $tab
	do
		echo $value
	done

	while read line ; do
		if [[ "$line" =~ .*src/.* ]]; then
	        index=`expr index "$line" /`
	        index2=`expr index "${line:$index}" /`
	        mod=`echo ${line:$index:$index2-1}| tr a-z A-Z`
	        save=$line
		    findInFile $mod
	        ret=`echo $?`
	        if [ "$ret" == 1 ]; then
	        	echo $save >> $BINDIR/Kconfig.opal.tmp
	        fi
	     else
	        echo $line >> $BINDIR/Kconfig.opal.tmp
		fi
	done < $BINDIR/Kconfig.opal
	rm $BINDIR/var

fi