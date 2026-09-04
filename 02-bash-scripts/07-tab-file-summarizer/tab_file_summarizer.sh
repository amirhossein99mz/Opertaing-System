#!/bin/bash

if [[ $# -ne 1 ]] || [[ ! -d $1 ]]; then
    exit 1
fi

dir=$1

for file in $(find "$dir" -type f -name "*.tab" -size -100M); do

    new_name=${file%.tab}.sum
    declare -A dict

    while read -r product quantity unit_price; do
        pro=$((quantity*unit_price))
        dict[$product]=$((dict[$product]+pro))
    done < < (tail -n +2 "$file")

    for name in "${!dict[@]}"; do
        echo "$name ${dict[$name]}"
    done > "$new_name"

done

exit 0
