#!/bin/bash

while read line; do
    words=$(echo "$line" | wc -w)
    rem=$((words % 2))

    if [ "$rem" -eq 0 ]; then
        echo "$line" | tr 'a-z' 'A-Z'
    else
        echo "$line" | tr 'A-Z' 'a-z'
    fi
done < "$1"

exit 0
