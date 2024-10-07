#!/bin/bash

CHECKS=250
SIZE=100
NAME="ps_gen"

if [ "$1" == "--help" ] || [ "$1" == "-h" ]
	then
		echo  -e "Usage: $0 size times FLAGS\nGenerates random numbers for push_swap\n\n\
OPTIONS (note: flags go at the back!):\n\n\
	v-, --valgrind		checks for memory leaks (warning: takes more time!)\n
Example: ./$NAME 100 250 -v\n
Default: Tests $SIZE numbers $CHECKS times."
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

MEMTEST=false
if [[ "$3" == "--valgrind" ]] || [[ "$3" == "-v" ]]
	then
		MEMTEST=true
fi

RESULT=() # Initialise RESULT as an array
tput sc
for i in $(seq 1 "$CHECKS");
do
	ARGS=$(shuf -i 0-2147483648 -n "$SIZE" | while read line; do echo "$((line * (1 - 2 * (RANDOM % 2))))"; done | tr '\n' ' ') # "random" because seed is fixed
	if $MEMTEST
		then
			echo -en "$(tput rc; tput el)"
			echo -en "Processing... $i/$CHECKS (note: valgrind can take a while)"
			out=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "$ARGS" 2>&1) # Redirect stderr to stdout
			if echo "$out" | grep -E "definitely lost|indirectly lost|possibly lost|ERROR SUMMARY: [^0]|Invalid" > /dev/null
				then
					echo -e "\n\e[1;91m$out\e[0m"
					exit 1
			fi
		else
			echo -en "\r\e[KProcessing... $i/$CHECKS"
			out=$(./push_swap "$ARGS")
    fi

	count=$(echo "$out" | grep -vc "==")
	RESULT+=("$count")
done

echo -en "$(tput rc; tput el)"

printf "%s\n" "${RESULT[@]}" | sort -n | \
awk -v size="$SIZE" -v checks="$CHECKS" 'NR==1 {min = $1} END \
{printf("\\e[1;92mTest complete!\\e[0m\\nSize: %d | Times tested: %d\\nMax: %d | Min: %d", size, checks, $1, min)}' | \
echo -e "$(cat)"