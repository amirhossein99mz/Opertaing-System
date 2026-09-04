#!/bin/bash

FILE="file.txt"

wword=""
longest=0

while read -r line; do

    for word in $line; do
        len=${#word}
        if [[ "$len" -gt "$longest" ]]; then
            longest=$len
            wword=$word
        fi
    done

done < "$FILE"

echo -n "$wword"

exit 0

