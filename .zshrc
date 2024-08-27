export USER=rsiah
export MAIL=rsiah@student.42singapore.sg

PROMPT='%B%F{cyan}%n>%f%b %F{yellow}%c%f $ '
unsetopt BEEP
export LESS="-Q"

export BLACK="\033[0;30m"
export RED="\033[0;31m"
export GREEN="\033[0;32m"
export BROWN="\033[0;33m"
export BLUE="\033[0;34m"
export PURPLE="\033[0;35m"
export CYAN="\033[0;36m"
export LIGHT_GRAY="\033[0;37m"
export DARK_GRAY="\033[1;30m"
export LIGHT_RED="\033[1;31m"
export LIGHT_GREEN="\033[1;32m"
export YELLOW="\033[1;33m"
export LIGHT_BLUE="\033[1;34m"
export LIGHT_PURPLE="\033[1;35m"
export LIGHT_CYAN="\033[1;36m"
export LIGHT_WHITE="\033[1;37m"
export BOLD="\033[1m"
export FAINT="\033[2m"
export ITALIC="\033[3m"
export UNDERLINE="\033[4m"
export BLINK="\033[5m"
export NEGATIVE="\033[7m"
export CROSSED="\033[9m"
export END="\033[0m"
export HIDE="\u001B[?25l"
export SHOW="\u001B[?25h"

alias ..="cd .."
alias ...="cd ../.."
alias 3..="cd ../../.."

alias gc="gcc -Wall -Wextra -Werror"
alias cg="gcc -Wall -Wextra -Werror *.c ; nm -u a.out"

alias oknorm='norminette -v; output=$(norminette); if [ $(echo "$output" | grep -vc OK) -eq 0 ]; then echo "${LIGHT_GREEN}ALL OK!${END}"; else echo -n "${LIGHT_RED}"; echo -n "$output" | grep -v OK; echo -n "${END}"; fi'
alias nu="nm -u | grep U | grep -v '__' | awk -F'@' '{print \$1}'"
alias oknormu='norminette -v; output=$(norminette); if [ $(echo "$output" | grep -vc OK) -eq 0 ]; then echo "${LIGHT_GREEN}ALL OK!${END}"; else echo -n "${LIGHT_RED}"; echo -n "$output" | grep -v OK; echo "${END}"; fi ; echo "${LIGHT_CYAN}FUNCTIONS USED:${END}"; nm -u | grep U | grep -v "__" | awk -F"@" '\''{printf("%s\n", $1)}'\'''

alias norm="norminette -R CheckForbiddenSourceHeader"
alias normdef="norminette -R CheckDefine"
alias mini='~/mini-moulinette/mini-moul.sh'
alias ldb="gcc -Wall -Wextra -Werror -g -o debug"
alias debug="lldb ./debug"
alias crun="gcc -Wall -Wextra -Werror *.c ; ./a.out"
alias run="./a.out"

alias francinette=/home/rsiah/francinette/tester.sh

alias paco=/home/rsiah/francinette/tester.sh

# Oh you've found my computer unlocked and are trying to mess with my config?
# Here's some commands to make it quicker before you get caught

# curl parrot.live
# curl ascii.live/rick
