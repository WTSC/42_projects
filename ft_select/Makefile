#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/07 07:18:51 by jantiope          #+#    #+#              #
#    Updated: 2015/08/07 07:18:51 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

LIBFT_DIR = libft/

INCLUDES_DIR = libft/includes

SRC = chainlist.c ft_select.c ft_signals.c select_edit.c select_keys.c chainlist2.c select_format.c select_move.c

FLAGS = -Werror -Wextra -Wall -o $(NAME)

all: $(NAME)

$(NAME):
			make -C $(LIBFT_DIR)
			gcc -L $(LIBFT_DIR) -lft -I $(INCLUDES_DIR) $(FLAGS) $(SRC) -lncurses

clean:
			make -C $(LIBFT_DIR) clean

fclean:	clean
			make -C $(LIBFT_DIR) fclean
			/bin/rm -f $(NAME)

re: fclean all
