COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11
NAME = a.out #temp name

MLX_DIR = minilibx-linux
MLX_LIB = libmlx.a

SRCS = playground.c

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS) $(MLX_LIB)
	$(COMPILER) $(CFLAGS) $^ -lm $(MLX_FLAGS) -o $@

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

$(MLX_LIB):
	make --no-print-directory -C $(MLX_DIR)
	mv $(MLX_DIR)/$(MLX_LIB) .

clean:
	rm -rf $(OBJECTS) $(MLX_LIB)
	make --no-print-directory -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
