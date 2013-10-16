#!/bin/bash

# check if component is hmis
if [ "$(echo $1 | grep -s hmis)" != "" ]
then
  hmipath=$(echo $1 | sed -e s:doc/Doxyfile::g)
  # remove every .h files previously generated
  for cpp in `find $hmipath/content -type f -name "*.cpp" | tr '\n' ' '`
  do
    rm -fv $h
  done
  
  # then call js2doxy.pl to generate new .h files
  for js in `find $hmipath/content -type f -name "*.js" | grep -v pdf | tr '\n' ' '`
  do
    cpp=${js%.js}.cpp
    perl js2doxy.pl $js > $cpp
  done
fi

# if script is called by boz-wide
if [ "$(echo $1 | grep -s comps)" == "" ]
then 
  echo $2
else 
  echo $2/$(basename `echo $1 | sed -e s:doc/Doxyfile::g`)
fi
