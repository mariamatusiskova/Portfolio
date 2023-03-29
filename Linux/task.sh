#!/bin/bash

read -p "Enter number of the sequence of Size: " x
lsmod | sort -k 2,2n | awk -v a="$x" '($3 >= 1 && $2 >= a) {printf $0; printf "\n";}'
