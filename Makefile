NAME = so_long

NAME_B = so_long_bonus

OBJ_M = main_mondat.o

OBJ_B = main_bonus.o

SRC = $(wildcard *.c)

OBJ = $(filter-out $(OBJ_B) $(OBJ_M),$(SRC:.c=.o))

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

.c.o:
	@$(CC) $(FLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(OBJ_M)
	@$(MAKE) -C ./ft_printf
	@cp ./ft_printf/libftprintf.a .
	@$(MAKE) -C ./ft_printf fclean
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_M) -lftprintf -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo DONE!

$(NAME_B): $(OBJ) $(OBJ_B)
	@$(MAKE) -C ./ft_printf
	@cp ./ft_printf/libftprintf.a .
	@$(MAKE) -C ./ft_printf fclean
	@$(CC)  $(FLAGS) $(OBJ) $(OBJ_B) -lftprintf -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	@echo DONE!

bonus: $(NAME_B)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ_B) $(OBJ_M)

fclean: clean
	@$(RM) $(NAME) $(NAME_B) libftprintf.a

re:	fclean all

.PHONY: NAME all clean fclean re
