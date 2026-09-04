#!/bin/bash

echo -n "Inter two integers:"
read i j

let s=i+j
let p=i*j

echo "Numbers are $i and $j,thus their sum is $s and their product $p"

exit 0
