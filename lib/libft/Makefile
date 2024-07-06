#-------------------------------------NAME--------------------------------------
NAME    := libft.a
#------------------------------------COLORS-------------------------------------
RED     := \033[1;31m
GREEN   := \033[1;32m
EC      := \033[0m
#-----------------------------------SOURCES-------------------------------------
SRCS    := var_strjoin.c\
           size_2d_array.c\
           strisnum.c\
           clear_2d_array.c\
           get_next_line.c\
           ft_isalpha.c\
           ft_isdigit.c\
           ft_isalnum.c\
           ft_isascii.c\
           ft_isprint.c\
		   ft_isspace.c\
           ft_strlen.c\
           ft_memset.c\
           ft_bzero.c\
           ft_memcpy.c\
           ft_memmove.c\
           ft_strlcpy.c\
           ft_strlcat.c\
           ft_toupper.c\
           ft_tolower.c\
           ft_strchr.c\
           ft_strrchr.c\
           ft_strcmp.c\
           ft_strncmp.c\
           ft_memchr.c\
           ft_memcmp.c\
           ft_strnstr.c\
           ft_atoi.c\
           ft_calloc.c\
           ft_strdup.c\
           ft_substr.c\
           ft_strjoin.c\
           ft_strtrim.c\
           ft_split.c\
           ft_itoa.c\
           ft_strmapi.c\
           ft_striteri.c\
           ft_putchar_fd.c\
           ft_putstr_fd.c\
           ft_putendl_fd.c\
           ft_putnbr_fd.c\
           ft_lstnew.c\
           ft_lstadd_front.c\
           ft_lstsize.c\
           ft_lstlast.c\
           ft_lstadd_back.c\
           ft_lstdelone.c\
           ft_lstclear.c\
           ft_lstiter.c\
           ft_lstmap.c
#------------------------------------OBJETS-------------------------------------
OBJS    := $(SRCS:.c=.o)
#------------------------------------FLAGS--------------------------------------
CFLAGS  := -Wall -Wextra -Werror
LFLAGS  := -c -r -s
#----------------------------------INSTRUCIONS----------------------------------
all: $(NAME)
re: fclean all

$(NAME): $(OBJS) libft.h
	@ar $(LFLAGS) $(NAME) $(OBJS) && printf "Linking: $(NAME)\n"
	@printf "$(GREEN)Libft compiled$(EC)\n"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -f $(OBJS) && printf "$(RED)Libft objects deleted$(EC)\n"

fclean: clean
	@rm -f $(NAME) && printf "$(RED)Libft deleted$(EC)\n"

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re bonus
