# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 21:49:33 by rsiah             #+#    #+#              #
#    Updated: 2025/04/16 22:04:40 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -MMD
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_strcmp.c ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c \
ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
myputchar_fd.c myputhex.c myputnbr_fd.c myputptr.c myputstr_fd.c \
myputunbr_fd.c ft_dprintf.c \
get_next_line_bonus.c get_next_line_utils_bonus.c \
free_2darr.c ft_whitespace.c ft_clean.c ft_strjoinfree.c ft_strndup.c \
ft_count.c ft_realloc.c ft_split_to_c.c

OBJECTS = $(SRCS:.c=.o)
DEPS = $(OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar -rc $@ $^
	@printf "LIBFT: \e[38;5;81;1mCreated archive %s\n\e[0m" $(NAME)

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJECTS) $(DEPS)
	@printf "LIBFT: \e[38;5;82;1mclean\n\e[0m"

fclean: clean
	@rm -rf $(NAME)
	@printf "LIBFT: \e[38;5;81;1mfclean\n\e[0m"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re