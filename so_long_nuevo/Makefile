NAME = so_long
CC = gcc
CFLAGS = -I./include -Wall -Wextra -Werror
SRCS = ./src/check_map_closed.c \
		./src/check_map_collectable.c \
		./src/check_map_connectivity.c \
		./src/check_map_empty_line.c \
		./src/check_map_exit.c \
		./src/check_map_file_extension.c \
		./src/check_map_invalid_character.c \
		./src/check_map_one_player.c \
		./src/check_map_rectangle.c \
		./src/delete_state.c \
		./src/find_collectable_count.c \
		./src/find_exit_position.c \
		./src/find_player_position.c \
		./src/ft_bzero.c \
		./src/ft_calloc.c \
		./src/ft_split.c \
		./src/init_state_variables.c \
		./src/main.c \
		./src/readmap.c \
		./src/render_map.c \
		./src/validate_arguments.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean 


re: fclean all

