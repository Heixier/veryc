# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 17:33:19 by rsiah             #+#    #+#              #
#    Updated: 2024/06/19 17:33:24 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c pf_putaddr.c pf_putchar.c pf_puthex.c \
pf_putnbr.c pf_putnbr_u.c pf_putstring.c

OBJECTS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^

%.o: %.c
	@$(COMPILER) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re