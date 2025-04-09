NAME = minishell
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCES = src/main.c src/execute/custom_func.c src/execute/exec_cmd.c \
src/execute/path_finder.c src/execute/free_lists.c


OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
			@$(MAKE) -s -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
			@printf "\n\033[1A\033[K"
			@printf "$(NAME) compiled!\n"

%.o: %.c
			@printf "\033[32mGenerating $(NAME) objects... %-33.33s\033[0m\r" $@
			@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
			@$(MAKE) -s -C $(LIBFT_DIR) clean
			@$(RM) $(OBJECTS)
			@printf "\033[0;31m$(NAME) deleted!\033[0m\n"

fclean: clean
			@$(RM) $(NAME)
                                
re: fclean all

.PHONY: all clean fclean re bonus