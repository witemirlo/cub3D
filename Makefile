NAME = cub3D

CC = cc

CFLAGS  =-Wall -Wextra -Werror -pedantic -O0 -g3 #-fanalyzer
CPPFLAGS =-I include/ -I lib/libft/ -I lib/minilibx-linux/
LIBRARY =-L lib/libft/ -lft -L lib/minilibx-linux/ -lmlx -lXext -lX11 -lm

OBJ      = $(SRC:.c=.o)
LIBFT    = libft.a
MINILIBX = libmlx.a

SRC = src/main.c\
	  src/parser/check_file_type.c\
	  src/parser/check_file_content.c\
	  src/parser/get_texture_paths.c\
	  src/parser/read_file.c

# COLORS -----------------------------------------------------------------------
BLACK  	= \033[1;30m
RED    	= \033[1;31m
GREEN  	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE    = \033[1;34m
MAGENTA = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m
NC      = \033[0m

#-------------------------------------------------------------------------------

all: $(NAME)

re: fclean all

leaks: $(NAME)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose --log-file="leaks.log" ./$(NAME)

norm:
	norminette include/ lib/libft/ src | grep -v OK

clean:
	rm -f $(OBJ)
	rm -f leaks.log
	make -C lib/libft clean
	make -C lib/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C lib/libft fclean
	make -C lib/minilibx-linux clean

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CPPFLAGS) $(CFLAGS)  -c $< -o $@

$(LIBFT):
	cd lib/libft/; make

$(MINILIBX):
	cd lib/minilibx-linux; make

.SECONDARY: $(OBJ) $(LIBFT) $(MINILIBX)
.PHONY: all clean fclean re leaks
