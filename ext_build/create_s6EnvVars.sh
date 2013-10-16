#!/bin/bash 

INPUT=$1
WHERE=$2

if [ -d ${WHERE}/.envvars ]; then
    echo "Remove old content of ${WHERE}";
    rm -rf ${WHERE};
fi
    
mkdir -p ${WHERE}
touch ${WHERE}/.envvars


LISTVAR=`cat ${INPUT} | sed -e '/^#/d;/^$/d'`
for IN in ${LISTVAR}; do
    VAR=`echo ${IN} | cut -d= -f1`;
    VAL=`echo ${IN} | cut -d= -f2 | sed -e 's/^"//g;s/"$//g' `;
    echo ${VAL} >  ${WHERE}/${VAR};
done
