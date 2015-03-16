#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:50:09 by jantiope          #+#    #+#              #
#    Updated: 2015/01/15 01:13:22 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

LIBFT_DIR = libft/

INCLUDES_DIR = libft/includes

SRC = ft_file_info.c ft_ls.c ft_special_flags.c main.c ft_flags_control.c ft_io.c \
ft_lst2.c niquelanorminette.c ls_trad.c ft_recursive.c ls_folders.c ft_uidgid_exceptions.c ft_special_bits.c ft_exceptions.c

FLAGS = -Werror -Wextra -Wall -o $(NAME)

all: $(NAME)

$(NAME):
			make -C $(LIBFT_DIR)
			gcc -L $(LIBFT_DIR) -lft -I $(INCLUDES_DIR) $(FLAGS) $(SRC)

clean:
			make -C $(LIBFT_DIR) clean

fclean:	clean
			make -C $(LIBFT_DIR) fclean
			/bin/rm -f $(NAME)

re: fclean all
