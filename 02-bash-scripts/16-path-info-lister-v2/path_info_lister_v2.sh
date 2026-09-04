#!/bin/bash

for path in $*; do
  
    if [ -f "$path" ]; then
        dim=$(ls -l "$path" | tr -s " " | cut -d " " -f 5)
        read_perm=""
        if [ -r "$path" ]; then
            read_perm=R
        fi
         
        write_perm=""
        if [ -w "$path" ]; then
            write_perm=W
        fi

        echo "FILE:$path,$dim,$read_perm,$write_perm"
    
    elif    [ -d "$path" ]; then
        subdirs=$(find "$path" -mindepth 1 -maxdepth 1 -type d | wc -l)
        echo "$path:$subdirs"
    fi
done
exit 0
