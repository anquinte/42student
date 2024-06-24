# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 14:34:57 by anquinte          #+#    #+#              #
#    Updated: 2024/06/15 21:44:46 by anquinte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = \
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_strrchr.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_itoa.c\
		ft_split.c\
		
SOURCES_BONUS = \
		ft_lstsize_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstnew_bonus.c\

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES:.c=.o) $(SOURCES_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR	= ar

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@ 

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS_BONUS)
	$(AR) rcs $(NAME) $(OBJECTS_BONUS)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re