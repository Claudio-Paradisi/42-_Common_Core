# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 11:26:03 by cparadis          #+#    #+#              #
#    Updated: 2025/04/04 18:15:26 by cparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
    ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
    ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
    ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
    ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	ft_printf/ft_printf.c ft_printf/ft_condition.c \
	ft_printf/ft_putchar_count.c ft_printf/ft_puthex_low_count.c \
	ft_printf/ft_puthex_up_count.c ft_printf/ft_putint_count.c \
	ft_printf/ft_putnbr_base_count.c ft_printf/ft_putptr_count.c \
	ft_printf/ft_putstr_count.c ft_printf/ft_putuns_int_count.c ft_printf/ft_strlen.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_matrix/ft_matrixlen.c ft_matrix/ft_freematrix.c ft_matrix/ft_floodfill.c \
	ft_matrix/ft_matrixdup.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	@$(AR) $@ $^
	@printf "\n\033[1A\033[K"
	@printf "$(NAME) compiled!\n"

%.o: %.c
	@printf "\033[32m Generating $(NAME) objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@
	

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@printf "\033[0;31m$(NAME) deleted!\033[0m\n"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
