#!/bin/bash

echo "Welcome to the password guesser"

echo "How long do you want your password to be"

read pass_length

if ! [[ $pass_length =~ ^[0-9]+$ ]];
then
	echo "Enter a valid length"
	exit 1
fi

password=()

for p in $(seq 1 3);
do 
	password+=("$(openssl rand -base64 48 | cut -c1-$pass_length)")
done 

echo "here is the generated password"
printf "%s\n" "${password[@]}"
