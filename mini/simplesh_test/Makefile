COMPILER = cc
CFLAGS = -g -Wall -Wextra -Werror -MMD
LINKS = -lreadline
NAME = simplesh

SRCS = simple.c ms_signals.c ms_cmds.c ms_info.c ms_cleanup.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT_DIR = ms_libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

%.o: %.c
	@$(COMPILER) -c $(CFLAGS) $< -o $@

all: $(NAME)
debug_all: $(OBJS) $(LIBFT_LIB)
	$(COMPILER) $(CFLAGS) $^ $(LINKS) -D DEBUG -o $(NAME)

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(COMPILER) $(CFLAGS) $^ $(LINKS) -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(LIBFT_LIB)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

nice: $(NAME) clean

debug: fclean debug_all

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean nice re debug