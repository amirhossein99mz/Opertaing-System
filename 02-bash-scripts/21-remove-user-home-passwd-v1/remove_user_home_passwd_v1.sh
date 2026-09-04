!/bin/bash

if [ $# -lt 1 ];then
    exit 1
fi

username=$1
FILE="etc/passwd"

line=$(echo $FILE|grep -e $username)

if [ $? -eq 1 ]; then
    exit 1
fi

home=$(echo $line|tr -d ":" -f 6)
rm -rf home

cat $file | grep -v $username > tmp.txt
mv tmp.txt $file
