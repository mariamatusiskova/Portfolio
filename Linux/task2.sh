#!/bin/bash

read -p "Enter number of the sequence of Used: " x
read -p "Enter boolean operator: " y
lsmod | sort -k 2,2n | awk -v a="$x" -v b="$y" '{
	if (b == "-gt") {	
		if ($3 > a) {printf $0; printf "\n";}
	}
	else if (b == "-lt") {
		if ($3 < a) {printf $0; printf "\n";}
	}
	else if (b == "-eq") {
		if ($3 == a) {printf $0; printf "\n";}
	}
	else if (b == "-ne") {
		if ($3 != a) {printf $0; printf "\n";}
	}
	else if (b == "-le") {
		if ($3 <= a) {printf $0; printf "\n";}
	}
	else if (b == "-ge") {
		if ($3 >= a) {printf $0; printf "\n";}
	}
	else {
		exit 0
	}
	}'
