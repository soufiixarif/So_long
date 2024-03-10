NAME = so_long
NAME_B = so_long_bonus
SRC_DIR = mandatory
SRC_B_DIR = bonus
SRC = $(SRC_DIR)/get_next_line_utils.c $(SRC_DIR)/get_next_line.c $(SRC_DIR)/libftfun.c \
$(SRC_DIR)/libftfun2.c $(SRC_DIR)/mapvalidityfun.c $(SRC_DIR)/mapvalidityfun2.c \
$(SRC_DIR)/so_long.c $(SRC_DIR)/mlxfun.c $(SRC_DIR)/tools.c $(SRC_DIR)/moves.c
SRC_B = $(SRC_B_DIR)/get_next_line_utils_bonus.c $(SRC_B_DIR)/get_next_line_bonus.c $(SRC_B_DIR)/libftfun_bonus.c \
$(SRC_B_DIR)/libftfun2_bonus.c $(SRC_B_DIR)/mapvalidityfun_bonus.c $(SRC_B_DIR)/mapvalidityfun2_bonus.c \
$(SRC_B_DIR)/so_long_bonus.c $(SRC_B_DIR)/mlxfun_bonus.c $(SRC_B_DIR)/tools_bonus.c $(SRC_B_DIR)/moves_bonus.c \
$(SRC_B_DIR)/mlxfun2_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
CC = cc
FLAGS = -g -Wall -Wextra -Werror -Imlx
MLX_FLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit

PRINTF_DIR = lib

all : $(PRINTF_DIR) $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(MLX_FLAGS) $(OBJ) -Lprintf -lftprintf -o $(NAME)
	rm -rf $(OBJ)
$(PRINTF_DIR) :
	make -C printf
$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(SRC_DIR)so_long.h printf/libftprintf.a Makefile
		$(CC) $(FLAGS) -c $< -o $@
$(SRC_B_DIR)/%.o : $(SRC_B_DIR)/%.c $(SRC_B_DIR)so_long_bonus.h printf/libftprintf.a Makefile
		$(CC) $(FLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ) $(OBJ_B)
	make clean -C printf 
fclean :
	rm -rf $(NAME) $(NAME_B)
	make fclean -C printf 
re : fclean all
bonus : $(OBJ_B)
	cc $(FLAGS) $(MLX_FLAGS) $(OBJ_B) -Lprintf -lftprintf -o $(NAME_B)
	rm -rf $(OBJ_B)