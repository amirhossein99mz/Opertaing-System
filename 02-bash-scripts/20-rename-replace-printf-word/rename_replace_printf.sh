#!/bin/bash

find . -maxdepth 1 -type f -name "*.$1" >"list.tmp"

while read file; do

    new_filename=${file%.$1}.new

    while read line; do
        for word in $line; do
            if[ "$word"=="printf" ]; then
                echo -n "write"
            else
                echo n "$word"
            fi
        done    
    done<$file>$new_filename
    rm $file
done<"list.tmp"
rm list.tmp
exit 0
