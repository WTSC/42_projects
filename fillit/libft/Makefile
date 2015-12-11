#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:50:09 by jantiope          #+#    #+#              #
#    Updated: 2015/02/03 17:12:59 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

DIR = ./

OBJ = array_size.o ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_strichr.o ft_power.o ft_int_len.o ft_base.o ft_strtoupper.o ft_strtolower.o ft_putwstr.o ft_putwchar.o ft_strrev.o ft_wstrlen.o ft_wstrsub.o ft_putunbr.o ft_capitalize.o ft_arrays.o get_next_line.o

SRC = $(DIR)ft_atoi.c $(DIR)ft_bzero.c $(DIR)ft_isalnum.c $(DIR)ft_isalpha.c $(DIR)ft_isascii.c $(DIR)ft_isdigit.c $(DIR)ft_isprint.c $(DIR)ft_itoa.c $(DIR)ft_memalloc.c $(DIR)ft_memccpy.c $(DIR)ft_memchr.c $(DIR)ft_memcmp.c $(DIR)ft_memcpy.c $(DIR)ft_memdel.c $(DIR)ft_memmove.c $(DIR)ft_memset.c $(DIR)ft_putchar.c $(DIR)ft_putchar_fd.c $(DIR)ft_putendl.c $(DIR)ft_putendl_fd.c $(DIR)ft_putnbr.c $(DIR)ft_putnbr_fd.c $(DIR)ft_putstr.c $(DIR)ft_putstr_fd.c $(DIR)ft_strcat.c $(DIR)ft_strchr.c $(DIR)ft_strclr.c $(DIR)ft_strcmp.c $(DIR)ft_strcpy.c $(DIR)ft_strdel.c $(DIR)ft_strdup.c $(DIR)ft_strequ.c $(DIR)ft_striter.c $(DIR)ft_striteri.c $(DIR)ft_strjoin.c $(DIR)ft_strlcat.c $(DIR)ft_strlen.c $(DIR)ft_strmap.c $(DIR)ft_strmapi.c $(DIR)ft_strncat.c $(DIR)ft_strncmp.c $(DIR)ft_strncpy.c $(DIR)ft_strnequ.c $(DIR)ft_strnew.c $(DIR)ft_strnstr.c $(DIR)ft_strrchr.c $(DIR)ft_strsplit.c $(DIR)ft_strstr.c $(DIR)ft_strsub.c $(DIR)ft_strtrim.c $(DIR)ft_tolower.c $(DIR)ft_toupper.c $(DIR)array_size.c $(DIR)ft_strichr.c $(DIR)ft_int_len.c $(DIR)ft_base.c $(DIR)ft_power.c $(DIR)ft_strtolower.c $(DIR)ft_strtoupper.c $(DIR)ft_putwstr.c $(DIR)ft_putwchar.c $(DIR)ft_strrev.c $(DIR)ft_wstrlen.c $(DIR)ft_wstrsub.c $(DIR)ft_putunbr.c $(DIR)ft_capitalize.c $(DIR)ft_arrays.c $(DIR)get_next_line.c

all: $(NAME)

$(NAME):
			gcc -c $(SRC)
			ar rc $(NAME) $(OBJ)

clean:
			/bin/rm -f $(OBJ)

fclean:	clean
			/bin/rm -f $(NAME)

re: fclean all
