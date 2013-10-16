#!/bin/bash

# find defined docs in configuration file
selected_ids=$(sed -nr 's/BOZ_DOC_([[:alnum:]]+)=y/\1/p' $1 | tr '\n' ' ')

# write header of output file
rm -f $3
echo -e '{\n\t"doccollection": [' >> $3

# match selected docs with json table
i=0
while read line  
do 
   for id in $selected_ids
   do
      if [[ "$line" == *"$id"* ]]
      then
        echo -e "\t\t$line," >> $3
      fi
   done
done < $2

echo -e '\t]\n}' >> $3
