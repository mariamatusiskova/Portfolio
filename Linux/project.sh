#!/bin/bash

lsmod | sort -k 2,2n | awk '$3 >= 1 {printf $0; printf "\n";}'
