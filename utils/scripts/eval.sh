#!/bin/bash

# Colours
LIGHT_GREEN=$'\033[38;5;46;1m'
LIGHT_BLUE=$'\033[38;5;75;1m'
RED=$'\033[38;5;160;1m'
YELLOW=$'\033[38;5;184;1m'
RESET=$'\033[0m'

norm_check () {
	printf "%sRunning norminette...%s" "$LIGHT_BLUE" "$RESET"
	local norm_errors="$(norminette 2>&1 | grep -v ': OK!')"
	local ko_errors="$(echo "$norm_errors" | grep -E ': Error!|Error: ')"
	printf "\r"; tput el
	if ! [[ $norm_errors ]]; then
		printf "%sNorminette OK!\n%s" "$LIGHT_GREEN" "$RESET"
	else
		if echo "$norm_errors" | grep -q "Traceback"; then
			printf "%sNorminette crashed!...??? (are you in the correct directory?)%s\n" "$RED" "$RESET"
		else
			if [[ $ko_errors ]]; then
				printf "%sNorminette errors found!%s\n%s\n" "$RED" "$RESET" "$ko_errors"
			else
				printf "%sNorminette OK, but warnings were found:%s\n%s\n" "$YELLOW" "$RESET" "$norm_errors"
			fi
		fi
	fi
}

norm_check
