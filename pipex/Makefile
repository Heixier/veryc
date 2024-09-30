# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 16:19:22 by rsiah             #+#    #+#              #
#    Updated: 2024/09/20 16:19:23 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = pipex.c px_cmd.c px_init_px.c px_debuggers.c px_cleanup.c px_main_components.c
OBJS = $(SRCS:.c=.o)

UTILS_DIR = px_libft/
UTILS_LIB = libft.a

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

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@
	@echo "Compiled$(LIGHT_CYAN) $@!$(END)"

$(UTILS_LIB):
	@make --no-print-directory -C $(UTILS_DIR) && make --no-print-directory -C $(UTILS_DIR) clean
	@mv $(UTILS_DIR)/$(UTILS_LIB) . 

$(PRINTF_LIB):
	@make --no-print-directory -C $(PRINTF_DIR) && make --no-print-directory -C $(PRINTF_DIR) clean
	@mv $(PRINTF_DIR)/$(PRINTF_LIB) . 

$(NAME): $(OBJS) $(UTILS_LIB) $(PRINTF_LIB)
	@$(COMPILER) $(CFLAGS) $^ -o $@
	@echo "$(LIGHT_GREEN)$(NAME) was compiled!$(END)"
	@echo "\n$(BLINK)🥳✨ $(END)$(LIGHT_GREEN)$(NAME) was successfully compiled!$(END)$(BLINK) ✨🥳$(END)\n"

clean:
	@echo "$(NAME): $(LIGHT_RED)Removed $(OBJS) $(UTILS_LIB) $(PRINTF_LIB) $(END)"
	@rm -rf $(OBJS) $(UTILS_LIB) $(PRINTF_LIB)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME): $(LIGHT_RED)Removed $(NAME)$(END)"

re: fclean all

.PHONY: all clean fclean re
