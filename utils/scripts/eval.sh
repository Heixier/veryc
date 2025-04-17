#!/bin/bash

# Colours
LIGHT_GREEN=$'\033[38;5;46;1m'
LIGHT_BLUE=$'\033[38;5;75;1m'
RED=$'\033[38;5;160;1m'
YELLOW=$'\033[38;5;184;1m'
LIGHT_GREY=$'\033[38;5;242;1m'
UNDERLINE=$'\033[4m'
RESET=$'\033[0m'

prog_name="$1"
allowed_funcs=( "${@:2}" )

norm_check () {
	printf "%sRunning norminette...%s" "$LIGHT_BLUE" "$RESET"
	local norm_errors="$(norminette 2>&1 | grep -v ': OK!')"
	local ko_errors="$(echo "$norm_errors" | grep -E ': Error!|Error: ')"
	printf "\r%s"; tput el
	if ! [[ $norm_errors ]]; then
		printf "%sNorminette OK!\n%s\n" "$LIGHT_GREEN" "$RESET"
	else
		if echo "$norm_errors" | grep -q "Traceback"; then
			printf "%sNorminette crashed!...??? (are you in the correct directory?)%s\n\n" "$RED" "$RESET"
		else
			if [[ $ko_errors ]]; then
				printf "%sNorminette errors found!%s\n%s\n\n" "$RED" "$RESET" "$ko_errors"
			else
				printf "%sNorminette OK, but warnings were found:%s\n%s\n\n" "$YELLOW" "$RESET" "$norm_errors"
			fi
		fi
	fi
}

header_check() {
	printf "%sChecking header authors...%s" "$LIGHT_BLUE" "$RESET"
	local authors="$(find . -name "*.c" -o -name "*.h" -type f | 
	xargs -I {} awk 'FNR==6 { print $3 } FNR==8 { print $6 } FNR==9 { print $6;nextfile }' {} | sort -u)"
	local emails="$(find . -name '*.c' -o -name '*.c' -type f | xargs -I {} awk 'FNR == 6 { print $4 }' {} | sort -u)"
	printf "\r"; tput el
	printf "%sHeader author ID list (check for additional names)\n%s%s\n\n" "$LIGHT_GREY" "$RESET" "$authors"
	# printf "%s%sHeader author email list\n%s%s\n\n" "$UNDERLINE" "$LIGHT_BLUE" "$RESET" "$emails"
}

nm_check() {
	printf "%sChecking for forbidden functions...%s" "$LIGHT_BLUE" "$RESET"
	printf "\r"; tput el
	if [[ $1 ]]; then
		local used_functions=($(nm -u $1 | awk '{$1=$1};1' | awk -vORS="" -F"[ @]" '/U/ && !/__/{ if (NR>1) printf ", ";print $2 } END { printf "\n" }'))
		if [[ $2 ]]; then
			local sorted_used=($(
			for function in "${used_functions[@]}"
			do
				echo "${function//,}"
			done | sort
			))

			local sorted=($(
			for arg in "${@:2}"
			do
				echo "${arg//,}"
			done | sort
			))

			local mismatches="$(comm -23 <(printf "%s\n" "${sorted_used[@]}") <(printf "%s\n" "${sorted[@]}"))"
		fi
		if [[ $mismatches ]]; then
			printf "%sForbidden functions found!\n%s%s\n%s\nThere may be false positives; search the source code manually.%s\n\n" "$RED" "$RESET" "$mismatches" "$LIGHT_BLUE" "$RESET"
		# else
			# printf "%sFunctions used (manual check):\n%s%s\n\n" "$LIGHT_BLUE" "$RESET" ${sorted_used[@]} THIS NO WORK
		fi
	else
		printf "No program name provided, skipping forbidden function check\n"
	fi

}

norm_check
header_check
nm_check $@