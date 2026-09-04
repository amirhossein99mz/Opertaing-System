#!/bin/bash

while read var1 var2; do
    echo "$var2 $var1"
done < "$1" > "temp.txt"
mv "temp.txt" "$1"

exit 0 
