COMPILER = cc
CFLAGS = -g -Wall -Wextra -Werror -MMD
MLX_FLAGS = -lXext -lX11
NAME = so_long

SRCS = so_long.c sl_path.c sl_validate_map.c sl_validate_map_utils.c \
sl_cleanup.c sl_read.c sl_info.c sl_utils.c sl_map_errors.c sl_path_utils.c \
sl_path_read.c sl_init_game.c sl_run.c sl_movement.c sl_render.c sl_cleanup_utils.c

BONUS_NAME = so_long_bonus
BONUS_SRCS = $(addsuffix _bonus.c, $(basename $(SRCS)))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

DEPS = $(OBJS:.o=.d)
BONUS_DEPS = $(BONUS_OBJS:.o=.d)

LIBFT_DIR = sl_libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_URL = https://github.com/42Paris/minilibx-linux

all: $(NAME)

bonus: $(BONUS_NAME)

# Ensure MLX_DIR exists before compiling
$(OBJS): | $(MLX_DIR)
$(BONUS_OBJS): | $(MLX_DIR)

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR) && make --no-print-directory -C $(LIBFT_DIR) clean

$(MLX_DIR):
	git clone $(MLX_URL) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	make --no-print-directory -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(COMPILER) $(CFLAGS) -lm $(MLX_FLAGS) $(MLX_LIB) $^ -o $@

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(COMPILER) $(CFLAGS) -lm $(MLX_FLAGS) $(MLX_LIB) $^ -o $@

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS) $(LIBFT_LIB) $(MLX_LIB)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then \
		make --no-print-directory -C $(MLX_DIR) clean; \
	fi

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME) $(MLX_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

nice: $(NAME) $(BONUS_NAME) clean

re: fclean all

-include $(DEPS)
-include $(BONUS_DEPS)

.PHONY: all clean fclean nice re bonus
