#!/bin/bash

longest_word=""
longest_length=0

for word in $(cat file.txt); do
    
    length=$(echo -n "$word" | wc -c)
  
    if [ $length -gt $longest_length ]; then
        longest_length=$length
        longest_word=$word
    fi
done

echo "$longest_word is $longest_length characters long!"

exit 0
