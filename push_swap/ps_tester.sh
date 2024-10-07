#!/bin/bash

CHECKS=250
SIZE=100

if [ "$1" == "--help" ] || [ "$1" == "-h" ]
	then
		echo  -e "Usage: \t $0 size_of_checks num_of_checks\n\nTests push_swap against random numbersCurrent defaults (internal):\n$CHECKS tests with $SIZE random numbers each."
		exit 0
fi

if [ -n "$1" ]
	then
		if [[ $1 =~ ^[-+]?[0-9]+$ ]] && (( $1 >= 0 ))
			then SIZE=$1
		else
			echo -e "$0: invalid option -- '$1'"
			echo "Try '-h' for more information."
			exit 22
		fi
fi

if [ -n "$2" ]
	then
		if [[ $2 =~ ^[-+]?[0-9]+$ ]] && (( $2 >= 0 ))
			then CHECKS=$2
		else
			echo -e "$0: invalid option -- '$2'"
			echo "Try '-h' for more information."
			exit 22
		fi
fi

RESULT=()

for i in $(seq 1 $CHECKS);
do
	ARGS=$(shuf -i 0-2147483648 -n $SIZE | while read line; do echo "$((line * (1 - 2 * (RANDOM % 2))))"; done)
	RESULT+=$(./push_swap $ARGS | wc -l)
	RESULT+=' '
done

printf "%s\n" ${RESULT[@]} | sort -n | \
awk -v size="$SIZE" -v checks="$CHECKS" 'NR==1 {min = $1} END {printf("\\e[1;92mTest complete!\\e[0m\\nTimes tested: %d | Size tested: %d\\nMax: %d | Min: %d", checks, size, $1, min)}' | \
echo -e $(cat)