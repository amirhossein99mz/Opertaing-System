#!/bin/bash

if [ $# -ne 1 ] || [ ! -ne $1 ]; then
    exit 1
fi


USER=$1

FILE="/etc/passwd"

line=$(cat $FILE | grep -e "$USER")

if [ $? -eq 1 ]; then
    exit 2
fi

HOME=$(echo $line | cut -d ":" -f 6)

rm -rf $HOME

cat $FILE | grep -v "$USER" > "tmp.txt"

mv "tmp.txt" $FILE


exit 0
