# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 13:29:18 by cparadis          #+#    #+#              #
#    Updated: 2024/12/29 13:40:01 by cparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = CC
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_printf.c ft_condition.c ft_putchar_count.c ft_puthex_low_count.c \
	ft_puthex_up_count.c ft_putint_count.c ft_putnbr_base_count.c ft_putptr_count.c \
	ft_putstr_count.c ft_putuns_int_count.c ft_strlen.c

OBJECTS = $(SOURCES: .c=.o)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re