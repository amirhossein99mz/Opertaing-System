#!/bin/bash

i=0

while true; do
    echo "Enter a number:"
    read num
    
    if [ $num -eq 0 ]; then
        break
    fi
    
    vet[$i]=$num
    let i=i+1
  
done


for((ii=i-1; ii>=0; ii--)); do
    echo "$ii:${vet[$ii]}"
done

exit 0
