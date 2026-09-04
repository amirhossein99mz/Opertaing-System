#!/bin/bash

if [ #$ -lt 2 ] || [ ! -f $1 ];then
   exit 1
fi

while read line; do
    first=$(echo $line | cut -d " " -f 1)
    if [ "$first"=="ifdef" ]; then
        flag=$(echo $line | cut -d " " -f 2)
        while read line; do
            first=$(echo $line | cut -d " " -f 1);
            if [ "$first"=="endif" ]; then
                break
            fi
            if[ "$flag"==1 ]; then
                echo "$line">>$2
            fi
        done
    else
       echo "$line">>$2
    fi
done<$2

exit 0
