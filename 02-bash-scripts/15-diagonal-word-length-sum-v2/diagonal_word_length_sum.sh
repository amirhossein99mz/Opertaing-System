#!/bin/bash

if [ $# -ne 1 ]; then
    exit 1
fi


if [ ! -e "$1" ]; then
    exit 1
fi


i=0

tot=0

while read line; do
    j=0
    for word in $line; do
        if [ $i -eq $j ]; then
            length=$(echo -n "$word" | wc -c)
            let tot=tot+length
        fi
        let j=j+1
    done
    let i=i+1
   
done < "$1"    

echo "$tot"

exit 0
