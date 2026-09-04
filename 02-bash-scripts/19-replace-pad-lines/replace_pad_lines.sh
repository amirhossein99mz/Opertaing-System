#!/bin/bash

if [ $# -ne 6 ]; then
    exit 1
fi

if [ ! -e $1 ]; then 
    exit 1
fi

fileIn=$1
str1=$2
str2=$3
N=$4
str3=$5
fileOut=$6


while read line; do

    for((i=0; i<N; i++)); do
        echo -n "$str3 "
    done

    

    for word in $line; do
   
        if [ "$word" = "$str1" ]; then
            echo -n "$str2 "
        else
            echo -n "$word "
        fi
    done

    

    for((i=0; i<N; i++)); do
        echo -n "$str3 "
    done

    echo # go to next line
    
done < "$fileIn" > "$fileOut"
exit 0
