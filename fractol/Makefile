#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:50:09 by jantiope          #+#    #+#              #
#    Updated: 2015/02/26 18:06:58 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

OBJ = fractol_check.o fractol_color.o fractol_draw.o fractol_hook.o fractol_julia.o fractol_mandel.o fractol_monitor.o fractol_ship.o fractol_tools.o main.o

SRC = fractol_check.c fractol_color.c fractol_draw.c fractol_hook.c fractol_julia.c fractol_mandel.c fractol_monitor.c fractol_ship.c fractol_tools.c main.c

LIB = -L libft/ -lft -L /usr/X11/lib -lmlx -lXext -lX11

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
