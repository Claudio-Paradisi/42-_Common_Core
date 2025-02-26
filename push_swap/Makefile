# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:27:37 by cparadis          #+#    #+#              #
#    Updated: 2025/02/25 16:44:33 by cparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c \
ft_printf/ft_printf.c ft_printf/ft_condition.c \
ft_printf/ft_putchar_count.c ft_printf/ft_puthex_low_count.c \
ft_printf/ft_puthex_up_count.c ft_printf/ft_putint_count.c \
ft_printf/ft_putnbr_base_count.c ft_printf/ft_putptr_count.c \
ft_printf/ft_putstr_count.c ft_printf/ft_putuns_int_count.c ft_printf/ft_strlen.c \
utils/ft_split.c utils/ft_lstsize.c utils/ft_lstlast.c utils/ft_atol.c utils/ft_is.c \
utils/ft_calloc.c \
errors/error.c errors/free.c \
commands/push.c commands/swap.c commands/rotate.c commands/reverse_rotate.c \


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