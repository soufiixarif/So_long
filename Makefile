NAME = so_long
SRC = get_next_line_utils.c get_next_line.c libftfun.c libftfun2.c mapvalidityfun.c mapvalidityfun2.c so_long.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)
	rm -rf $(OBJ)

%.o : %.c so_long.h
		$(CC) $(FLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean :
	rm -rf $(NAME)
re : fclean all