#!/bin/bash

echo -n "Enter your username:"
read username

times=$(who | grep "$username" | wc -l)

echo "User $username has $times login(s)"

exit 0
