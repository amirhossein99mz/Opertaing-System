#!/bin/bash

if [[ $# -lt 1 ]]; then
    exit 1
fi

for path in "$@"; do

    if [[ -f $path ]]; then
        name=$(ls -l "$path" | tr -s " " | cut -d " " -f 9)
        dime=$(ls -l "$path" | tr -s " " | cut -d " " -f 5)
        read_perm=$(ls -l "$path" | tr -s " " | cut -d " " -f 1 | cut -c 2)
        write_perm=$(ls -l "$path" | tr -s " " | cut -d " " -f 1 | cut -c 3)

        echo "$name $dime $read_perm $write_perm"

    elif [[ -d $path ]]; then

        name=$(basename "$path")
        sub=$(ls -l "$path" | grep "^d" | wc -l)

        echo "$name $sub"

    else
        continue
    fi

done

exit 0 0
