# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:27:37 by cparadis          #+#    #+#              #
#    Updated: 2025/02/06 17:35:25 by cparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCES = pipex.c utils/ft_split.c utils/ft_strncmp.c utils/ft_strjoin.c \
		utils/ft_strlen.c utils/free_matrix.c src/children.c src/errors.c \
		src/pipes.c utils/ft_calloc.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJECTS)

fclean: clean
				$(RM) $(NAME)
				
re: fclean all

.PHONY: all clean fclean re