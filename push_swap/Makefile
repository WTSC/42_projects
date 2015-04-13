
NAME = push_swap
SRC = main.c swap_tools.c swap_check.c operations.c ins_del.c swap_sort.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -I libft/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
