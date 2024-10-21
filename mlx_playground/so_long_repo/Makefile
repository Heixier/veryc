COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -MMD
NAME = a.out #temp name

SRCS = so_long.c sl_path.c sl_validate_map.c sl_validate_map_2.c \
sl_cleanup.c sl_read.c sl_info.c sl_utils.c sl_map_errors.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT_DIR = sl_libft
LIBFT_LIB = libft.a

all : $(NAME)

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR) && make --no-print-directory -C $(LIBFT_DIR) clean
	@mv $(LIBFT_DIR)/$(LIBFT_LIB) .

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(COMPILER) $(CFLAGS) $^ $(LIB) -o $@

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(LIBFT_LIB)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

nice: $(NAME) clean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean nice re
