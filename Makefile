NAME = cub3D

CC = cc

CFLAGS  = -Wall -Wextra -Werror -pedantic -O0 -g3 #-fsanitize=leak,address#-fanalyzer
CPPFLAGS = -I include/ -I lib/libft/ -I lib/MLX42/include/MLX42/
LIBRARY = -L lib/libft/ -lft -L lib/MLX42/build/ -lmlx42 -ldl -lglfw -pthread -lm

OBJ      = $(SRC:.c=.o)
LIBFT    = libft.a
MLX42    = libmlx42.a

SRC = src/main.c\
	  src/parser/checker/check_correct_data.c\
	  src/parser/checker/check_file_content.c\
	  src/parser/checker/check_file_type.c\
	  src/parser/checker/check_map.c\
	  src/parser/checker/check_map_closed.c\
	  src/parser/checker/print_parse_error.c\
	  src/parser/file/close_file.c\
	  src/parser/file/generate_map.c\
	  src/parser/file/get_player.c\
	  src/parser/file/goto_map.c\
	  src/parser/file/read_file.c\
	  src/parser/texture_path/get_colors_map.c\
	  src/parser/texture_path/get_texture_paths.c\
	  src/parser/clear_parser.c\
	  src/parser/parser.c\
	  src/texturer/clear_texturer.c\
	  src/texturer/print_texturer_error.c\
	  src/texturer/texturer.c\
	  src/raycaster/raycaster.c

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
	--track-origins=yes --log-file="leaks.log" \
	./$(NAME) map/debug.cub

norm:
	norminette include/ lib/libft/ src | grep -v OK

clean:
	@rm -f $(OBJ) && printf "$(RED)Objects files deleted\n$(NC)"
	@rm -f leaks.log && printf "$(RED)Leaks report deleted\n$(NC)"
	@make -C lib/libft fclean
	@rm -rf lib/MLX42/build && printf "$(RED)MLX42 deleted\n$(NC)"

fclean: clean
	@rm -f $(NAME) && printf "$(RED)Program deleted$(NC)\n"

$(NAME): $(MLX42) $(LIBFT) $(OBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBRARY) && printf "$(GREEN)Program linked\n$(NC)"

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ && printf "Compiled: $(notdir $<)\n" 

$(LIBFT):
	@make -C lib/libft/

$(MLX42):
	@cmake lib/MLX42/ -B lib/MLX42/build/ && make -C lib/MLX42/build/

.SECONDARY: $(OBJ) $(LIBFT) $(MLX42)
.PHONY: all clean fclean re leaks

