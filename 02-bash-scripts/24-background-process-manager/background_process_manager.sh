#!/bin/bash

if [ $# -lt 2 ] || [ ! -f $2 ]; then
    exit 1
fi

if [ $1=="start" ]; then
  
    while read cmd; do
      "$cmd" &
    done <$2

elif [ $1=="stop" ]; then

    while read cmd; do
        PID=$(ps -aux | grep -e "$cmd" | grep -v grep | tr -s " " | cut -d " " -f 2)
        kill -9 $PID
    done <$2

else
    exit 2
fi

exit 0
