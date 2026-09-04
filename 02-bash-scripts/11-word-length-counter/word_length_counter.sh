#!/bin/bash

echo -n "Enter one word:"
read word

length=$(echo -n "$word" | wc -c)

echo "String $word is $length characters long!"

exit 0
