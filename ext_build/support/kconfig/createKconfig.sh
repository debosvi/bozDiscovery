#!/bin/bash

ECHO_DEBUG=1

if [ $# != 3 ]; then
    echo "Need 3 parameters :"
    echo "  - \$1 is build directory"
    echo "  - \$2 is source directory"
    echo "  - \$3 is start Kconfig file"
    exit 1
fi

BINDIR="$1"
SRCDIR="$2"

#source "$2/scripts/kconfig/inbuild.sh"

function debug {
    if [ ${ECHO_DEBUG} -eq 1 ]; then
        echo -e $1 >> "$BINDIR/Kconfig"
    fi
}

function parseBaseFolder {
    echo -n "."
    sed -i s:KCFG_DIR_REPLACE:$2: $1
}

function parseGeneric {
    sed s:MOD_UPPER:$2: $1 >> $3
}


# $1 -> line source ( Ex: $1=source "Kconfig.plt" )
function getFile() {

    MATCHED=`echo $1 | sed -n "s/^[ \t]*source *\"*\([a-zA-Z0-9\.\/]*\)\"*/\1/p"`

    if [[ -n ${MATCHED} ]]; then
        echo "$MATCHED"
    fi
}

function writeLine() {
    line="$1"
    pattern="^[ \t]*#.*"

    if ! [[ $line =~ $pattern ]] && [[ "$line" != "" ]]; then
        echo -e $line >> "$BINDIR/Kconfig"
    fi
}

# $1 -> line source ( Ex: $1=source "Kconfig.plt" )
function writeFileConfig() {
    if [ $# != 1 ]; then
        echo "Missing parameter"
        exit
    fi

    local file=`getFile "$1"`
    local dir=`dirname "${file#$SRCDIR/}"`
    local kcFile=`basename "$file"`
    if [ "$file" != "" ] && [ -f "$SRCDIR/$file" ]; then

        read_file="$SRCDIR/$file.tmp"
        cp "$SRCDIR/$file" "$read_file"
        echo -e "$read_file" >> "$BINDIR/.to_clean"
        parseBaseFolder "$read_file" "$dir"
        debug "# Start to write from $file" 
        IFS=$'\n'     # new field separator, the end of line
        while read line; do
            if [[ "$line" =~ .*source.* ]]; then
                writeFileConfig "$line"
            else
                writeLine "$line"
            fi
        done < "$read_file"
        IFS=$old_IFS     # restore default field separator
        debug "# Stop to write from $file" 
    elif ! [[ "$file" =~ src/.* ]] &&
	 ! [[ "$file" =~ config.* ]] ; then 
         echo -e "$1" >> "$BINDIR/Kconfig"
    fi
}


cp $3 $3.save

echo "" > $BINDIR/Kconfig

parseBaseFolder "$3.save" "config"
old_IFS=$IFS      # save the field separator
IFS=$'\n'     # new field separator, the end of line
while read line; do

    if [[ "$line" =~ .*source.* ]]; then
        writeFileConfig "$line"
    else
        writeLine "$line"
    fi
done < "$3.save"

[[ -f $BINDIR/.to_clean ]] && while read line; do
    rm -f "$line"
done < "$BINDIR/.to_clean"
rm -f "$BINDIR/.to_clean"

IFS=$old_IFS     # restore default field separator

rm $3.save

