# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 16:40:06 by rsiah             #+#    #+#              #
#    Updated: 2024/08/22 16:48:25 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
header_files = push_swap.h 
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap

SRCS = push_swap.c ps_utils.c ps_utils_2.c ps_node_utils.c ps_list_utils.c \
ps_lib_utils.c ps_errors.c ps_sort.c ps_main_sort.c ps_instr.c ps_instr_utils.c \
ps_sort_utils.c ps_cleanup.c ps_split.c ps_libft.c

PRINTF_DIR = ft_printf/
PRINTF_LIB = libftprintf.a

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
LIGHT_GRAY = \033[0;37m
DARK_GRAY = \033[1;30m
LIGHT_RED = \033[1;31m
LIGHT_GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;34m
LIGHT_PURPLE = \033[1;35m
LIGHT_CYAN = \033[1;36m
LIGHT_WHITE = \033[1;37m
BOLD = \033[1m
FAINT = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
NEGATIVE = \033[7m
CROSSED = \033[9m
END = \033[0m
HIDE = \u001B[?25l
SHOW = \u001B[?25h 

all: $(NAME)

$(PRINTF_LIB):
	@make --no-print-directory -C $(PRINTF_DIR) && make --no-print-directory -C $(PRINTF_DIR) clean
	@mv $(PRINTF_DIR)/$(PRINTF_LIB) . 

$(NAME): $(SRCS) $(PRINTF_LIB)
	@$(COMPILER) $(CFLAGS) $^ $(PRINTF_LIB) -o $@
	@echo "$(LIGHT_GREEN)$(NAME) was compiled!$(END)"

clean:
	@rm -rf $(PRINTF_LIB)
	@echo "$(LIGHT_RED)Removed $(PRINTF_LIB)$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(LIGHT_RED)Removed $(NAME)$(END)"

re: fclean all

.PHONY: all clean fclean re
