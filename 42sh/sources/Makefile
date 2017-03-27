NAME = ft_minishell
SRC = ft_sh1.c ft_parser.c sh1_core.c sh1_core2.c sh1_core3.c sh1_fork.c select_home.c sh_lvl.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make -C libft re
	make -C printf re
	gcc $(FLAGS) -I libft/includes -c $(FOLDER)$(SRC)
	gcc $(OBJ) -L libft -lft -L printf -lftprintf -o ../$(NAME)

clean :
	make -C libft clean
	rm -f $(FOLDER)$(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
