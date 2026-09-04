#!/bin/bash

if [[ $# -lt 1 ]]; then
    exit 1
fi

for file in $@; do
    max=-999999
    n1=0
    n2=0
    file_name=$(basename $file)

    while read -r line; do
        array=()
        len=0

        for num in $line; do
            array[$len]=$num
            ((len++))
        done

        for((i=0; i<len-1; i++)); do
            for((j=i+1; j<len; j++)); do
                pro=$((array[$i]*array[$j]))

                if [[ $pro -gt $max ]]; then
                    max=$pro
                    n1=${array[$i]}
                    n2=${array[$j]}
                fi
            done
        done

    done < "$file"

    echo "$file_name $n1 $n2 $max"
done

exit 0
