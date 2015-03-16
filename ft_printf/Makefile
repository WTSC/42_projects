#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:50:09 by jantiope          #+#    #+#              #
#    Updated: 2015/02/01 16:56:03 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

DIR = libft/

SRC = printf_iflags.c printf_wflags.c ft_printf.c printf_core.c printf_precise.c printf_core2.c printf_sflags.c ft_verif.c printf_core3.c printf_types.c printf_wcore.c printf_icore.c printf_ucore.c printf_uflags.c printf_ocore.c printf_oflags.c printf_score.c

OBJ = printf_iflags.o printf_wflags.o ft_printf.o printf_core.o printf_precise.o printf_core2.o printf_sflags.o ft_verif.o printf_core3.o printf_types.o printf_wcore.o printf_icore.o printf_ucore.o printf_uflags.o printf_ocore.o printf_oflags.o printf_score.o

LIBFT = $(DIR)ft_atoi.o $(DIR)ft_bzero.o $(DIR)ft_isalnum.o $(DIR)ft_isalpha.o $(DIR)ft_isascii.o $(DIR)ft_isdigit.o $(DIR)ft_isprint.o $(DIR)ft_itoa.o $(DIR)ft_memalloc.o $(DIR)ft_memccpy.o $(DIR)ft_memchr.o $(DIR)ft_memcmp.o $(DIR)ft_memcpy.o $(DIR)ft_memdel.o $(DIR)ft_memmove.o $(DIR)ft_memset.o $(DIR)ft_putchar.o $(DIR)ft_putchar_fd.o $(DIR)ft_putendl.o $(DIR)ft_putendl_fd.o $(DIR)ft_putnbr.o $(DIR)ft_putnbr_fd.o $(DIR)ft_putstr.o $(DIR)ft_putstr_fd.o $(DIR)ft_strcat.o $(DIR)ft_strchr.o $(DIR)ft_strclr.o $(DIR)ft_strcmp.o $(DIR)ft_strcpy.o $(DIR)ft_strdel.o $(DIR)ft_strdup.o $(DIR)ft_strequ.o $(DIR)ft_striter.o $(DIR)ft_striteri.o $(DIR)ft_strjoin.o $(DIR)ft_strlcat.o $(DIR)ft_strlen.o $(DIR)ft_strmap.o $(DIR)ft_strmapi.o $(DIR)ft_strncat.o $(DIR)ft_strncmp.o $(DIR)ft_strncpy.o $(DIR)ft_strnequ.o $(DIR)ft_strnew.o $(DIR)ft_strnstr.o $(DIR)ft_strrchr.o $(DIR)ft_strsplit.o $(DIR)ft_strstr.o $(DIR)ft_strsub.o $(DIR)ft_strtrim.o $(DIR)ft_tolower.o $(DIR)ft_toupper.o $(DIR)array_size.o $(DIR)get_next_line.o $(DIR)ft_strichr.o $(DIR)ft_int_len.o $(DIR)ft_base.o $(DIR)ft_power.o $(DIR)ft_strtolower.o $(DIR)ft_strtoupper.o $(DIR)ft_putwstr.o $(DIR)ft_putwchar.o $(DIR)ft_strrev.o $(DIR)ft_wstrlen.o $(DIR)ft_wstrsub.o $(DIR)ft_putunbr.o

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
			make -C $(DIR) re
			gcc -c $(FLAGS) $(SRC)
			ar rc $(NAME) $(OBJ) $(LIBFT)

clean:
			/bin/rm -f $(OBJ) $(LIBFT)

fclean:	clean
			/bin/rm -f $(NAME)

re: fclean all
