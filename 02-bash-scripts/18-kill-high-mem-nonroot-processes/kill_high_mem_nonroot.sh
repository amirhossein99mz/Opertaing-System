#!/bin/bash

ps -aux | tail -n +2 > tmp.txt

while read line; do

    user=$(echo "$line" | tr -s " " | cut -d " " -f 1)
    pid=$(echo "$line" | tr -s " " | cut -d " " -f2)
    mem=$(echo "$line" | tr -s " " | cut -d "." -f 1)
        if [ $user != "root" ] && [ $mem -ge 25 ]; then
            kill -9 "$pid"
        fi

done < tmp.ext
rm tmp.txt

exit 0
