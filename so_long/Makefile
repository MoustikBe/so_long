NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx -Ilibft -c
RM			= rm -rf
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES		= sl_long_main sl_split sl_strjoin get_next_line/get_next_line get_next_line/get_next_line_utils sl_algo sl_free \
			  sl_map_init

OBJECTS     = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

all : $(NAME)

re: fclean all

.PHONY: all clean fclean re
