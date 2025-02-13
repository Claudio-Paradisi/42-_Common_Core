# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:27:37 by cparadis          #+#    #+#              #
#    Updated: 2025/02/12 16:46:45 by cparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCES = pipex.c utils/ft_split.c utils/ft_strncmp.c utils/ft_strjoin.c \
		utils/ft_strlen.c utils/free_matrix.c src/children.c src/errors.c \
		src/pipes.c utils/ft_calloc.c utils/ft_putstr_fd.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		here_doc/here_doc.c here_doc/here_doc_utils.c

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