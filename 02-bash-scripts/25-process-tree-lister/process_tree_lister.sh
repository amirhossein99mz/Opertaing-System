#!\bin\bash

if [ $# -ne 1 ]; then
  exit 1;
fi

if [ ! -e $1 ]; then
   exit 1;
fi


while read pid; do
    
    line=$(ps -ef|tr -s " "|cut -d " " -f 1,2|grep -e "$pid$")
 
    if [ $? -eq 0 ];then
        owner=$(echo $line|cut -d " " -f 1)
        children=$(ps -ef|tr -s " " |cut -d " " -f 2,3|grep -e "$pid$"|cut -d " " -f 1|tr "\n" " ")
        echo "$pid [$owner]: $ children"
    fi
done < $1

exit 0
