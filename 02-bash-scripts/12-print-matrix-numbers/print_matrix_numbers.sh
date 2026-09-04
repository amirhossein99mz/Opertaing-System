#!/bin/bash

if [ $# -lt 2 ]; then
   echo -n "Inter 2 integers:"
   read r c
else
   r=$1
   c=$2
fi

num=0

for((i=0; i<r; i++)); do
    for((j=0; j<c; j++)); do
        echo -n "$num"
        let num=num+1
    done
done

exit 0
