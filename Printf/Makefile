# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:51:06 by anquinte          #+#    #+#              #
#    Updated: 2024/06/26 11:11:53 by anquinte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
NAME = libftprintf.a
SRC = ft_printf.c ft_printchar.c ft_printnbr.c ft_printstr.c ft_printuns.c \
		ft_printhex.c ft_printpointer.c

OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(SRC) $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $?

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re		
