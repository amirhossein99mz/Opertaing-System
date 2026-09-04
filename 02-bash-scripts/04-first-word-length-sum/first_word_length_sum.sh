#!/bin/bash

if [[ $# -ne 1 ]] || [[ ! -e $1 ]]; then

    exit 1
fi

i=0
tot=0

while read -r line; do
    j=0
    for word in $line; do
        if [[ $i -eq $j ]]; then
            len=${#word}
            tot=$((tot+len))
        fi
        ((j++))
    done
    ((i++))
done < "$1"
echo "$tot"

exit 0
