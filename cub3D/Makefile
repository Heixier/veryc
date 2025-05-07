# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 17:02:03 by rsiah             #+#    #+#              #
#    Updated: 2025/05/06 17:55:14 by rsiah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
OPT_FLAGS = -lXext -lX11 -lm
CFLAGS = -g -Wall -Wextra -Werror -MMD

SRCS = ./minishell.c $(CLEANUP)

CLEANUP = $(addprefix srcs/cleanup/, cleanup.c)

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_URL = https://github.com/42Paris/minilibx-linux

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

# Require MLX dir before compiling objects
$(OBJS): | $(MLX_DIR)
$(BONUS_OBJS): | $(MLX_DIR)

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR) && make --no-print-directory -C $(LIBFT_DIR) clean

$(MLX_DIR):
	git clone $(MLX_URL) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	make --no-print-directory -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -lm $(OPT_FLAGS) $(MLX_LIB) $^ -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS) $(LIBFT_LIB) $(MLX_LIB)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then \
		make --no-print-directory -C $(MLX_DIR) clean; \
	fi

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME) $(MLX_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

neat: all clean

re: fclean all

val: all
	valgrind --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes --show-error-list=yes ./$(NAME)

-include $(DEPS)

.PHONY: clean fclean re all neat val
