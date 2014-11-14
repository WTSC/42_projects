#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:50:09 by jantiope          #+#    #+#              #
#    Updated: 2014/11/07 18:09:30 by jantiope         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o

SRC = ./sources/ft_atoi.c ./sources/ft_bzero.c ./sources/ft_isalnum.c ./sources/ft_isalpha.c ./sources/ft_isascii.c ./sources/ft_isdigit.c ./sources/ft_isprint.c ./sources/ft_itoa.c ./sources/ft_memalloc.c ./sources/ft_memccpy.c ./sources/ft_memchr.c ./sources/ft_memcmp.c ./sources/ft_memcpy.c ./sources/ft_memdel.c ./sources/ft_memmove.c ./sources/ft_memset.c ./sources/ft_putchar.c ./sources/ft_putchar_fd.c ./sources/ft_putendl.c ./sources/ft_putendl_fd.c ./sources/ft_putnbr.c ./sources/ft_putnbr_fd.c ./sources/ft_putstr.c ./sources/ft_putstr_fd.c ./sources/ft_strcat.c ./sources/ft_strchr.c ./sources/ft_strclr.c ./sources/ft_strcmp.c ./sources/ft_strcpy.c ./sources/ft_strdel.c ./sources/ft_strdup.c ./sources/ft_strequ.c ./sources/ft_striter.c ./sources/ft_striteri.c ./sources/ft_strjoin.c ./sources/ft_strlcat.c ./sources/ft_strlen.c ./sources/ft_strmap.c ./sources/ft_strmapi.c ./sources/ft_strncat.c ./sources/ft_strncmp.c ./sources/ft_strncpy.c ./sources/ft_strnequ.c ./sources/ft_strnew.c ./sources/ft_strnstr.c ./sources/ft_strrchr.c ./sources/ft_strsplit.c ./sources/ft_strstr.c ./sources/ft_strsub.c ./sources/ft_strtrim.c ./sources/ft_tolower.c ./sources/ft_toupper.c

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
			gcc -c $(FLAGS) $(SRC)
			ar rc $(NAME) $(OBJ)

clean:
			/bin/rm -f $(OBJ)

fclean:	clean
			/bin/rm -f $(NAME)

re: fclean all