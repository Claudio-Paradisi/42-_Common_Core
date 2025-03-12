NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCES = so_long.c \
utils/ft_calloc.c \


OBJECTS = $(SOURCES:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11
MLX_INC = -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
			$(MAKE) -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) -o $(NAME)
			@printf "\n\033[1A\033[K"
			@printf "$(NAME) compiled!\n"

%.o: %.c
			@printf "\033; Generating $(NAME) objects... %-33.33s\r" $@
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(MAKE) -C $(MLX_DIR) clean
			@$(RM) $(OBJECTS)
			@printf "$(NAME) deleted!\n"

fclean: clean
			@$(RM) $(NAME)
                                
re: fclean all

.PHONY: all clean fclean re
