#!/bin/bash

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -e "$1" ]; then
   exit 1
fi


while read line; do
    n=$(echo "$line"|wc -w)
    if [ $((n%2)) -eq 1 ] ; then
        echo "$line" | tr '[:upper:]' '[:lower:]'
    else
        echo "$line" | tr '[:lower:]' '[:upper:]'
    fi
done < "$1"

exit 0
