COMPILER = cc
CFLAGS = -g -Wall -Wextra -Werror -MMD
MLX_FLAGS = -lXext -lX11
NAME = so_long

SRCS = so_long.c sl_path.c sl_validate_map.c sl_validate_map_utils.c \
sl_cleanup.c sl_read.c sl_info.c sl_utils.c sl_map_errors.c sl_path_utils.c \
sl_path_read.c sl_init_game.c sl_run.c sl_movement.c sl_render.c sl_cleanup_utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT_DIR = sl_libft
LIBFT_LIB = libft.a

MLX_DIR = minilibx-linux
MLX_LIB = libmlx.a

all : $(NAME)

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR) && make --no-print-directory -C $(LIBFT_DIR) clean
	@mv $(LIBFT_DIR)/$(LIBFT_LIB) .

$(MLX_LIB):
	make --no-print-directory -C $(MLX_DIR)
	mv $(MLX_DIR)/$(MLX_LIB) .

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(COMPILER) $(CFLAGS) -lm $(MLX_FLAGS) $(MLX_LIB) $^ -o $@

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(LIBFT_LIB) $(MLX_LIB)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

nice: $(NAME) clean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean nice re
