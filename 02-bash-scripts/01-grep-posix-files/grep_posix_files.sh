#!/bin/bash

for file in $(find . -mindepth 1 -maxdepth 1 -type f -name "*.c"); do

    if grep -q "POSIX" "$file"; then    
        cat $file
    fi

done 

exit 0
