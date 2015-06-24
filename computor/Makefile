#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 15:36:37 by jantiope          #+#    #+#              #
#    Updated: 2015/06/24 15:36:53 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = computor

OBJ = computor_check.o grossenorme.o computor_math.o main.o

SRC = computor_check.c grossenorme.c computor_math.c main.c

LIB = -L libft/ -lft

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
			make -C libft
			gcc -c $(FLAGS) $(SRC)
			gcc $(LIB) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			make -C libft clean
			/bin/rm -f $(OBJ)

fclean:	clean
			make -C libft fclean
			/bin/rm -f $(NAME)

re: fclean all
