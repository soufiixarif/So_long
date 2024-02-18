NAME = lib_so_long.a
SRC = get_next_line_utils.c get_next_line.c libftfun.c libftfun2.c mapvalidityfun.c mapvalidityfun2.c so_long.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	rm -rf $(OBJ)

%.o : %.c so_long.h
		$(CC) $(FLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean :
	rm -rf $(NAME)
re : fclean all