# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 21:49:33 by rsiah             #+#    #+#              #
#    Updated: 2024/05/24 21:49:33 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
rz_strxcmp.c

BONUSES = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c \
ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUSES:.c=.o)

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[0;33m
BLUE = "033[0;34m
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

$(NAME): $(OBJECTS)
	@ar -rc $@ $^

%.o: %.c
	@$(COMPILER) $(CFLAGS) $< -o $@

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	@ar -rc $(NAME) $^
	@echo "\n$(BLINK)🥳✨ $(END)$(LIGHT_GREEN)$(NAME) (bonus ver.) was successfully created!$(END)$(BLINK) ✨🥳$(END)\n"

clean:
	@rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re