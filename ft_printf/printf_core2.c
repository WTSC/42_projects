/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 04:47:31 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:59:37 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <limits.h>

char *printf_uint(char *f, char type, uintmax_t ld)
{
	int					hjz;

	hjz = ft_is_hjz(f);
	if (hjz == 1)
		return (printf_int(f, type, (unsigned short)ld));
	else if (hjz == 2 && type != 'U')
		return (printf_int(f, type, (unsigned char)ld));
	else if (hjz == 3)
		return (printf_uint2(f, type, ld));
	else if (hjz == 4)
		return (printf_uint2(f, type, (size_t)ld));
	else if (hjz == 5)
		return (printf_uint2(f, type, (unsigned long long int)ld));
	else
		return (printf_uint2(f, type, (type == 'U') ? ld : (unsigned int)ld));
	return (NULL);
}

char *printf_lint(char *f, long int d)
{
	char				*out;
	char				*next;
	int					flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	ft_putcount(0, ft_itoa(d));
	out = NULL;
	return (next);
}

char *printf_octal(char *f, char type, uintmax_t ld)
{
	int		hjz;
	char	*out;
	int		flag;

	out = ft_strdup(f);
	printf_clean(&out, &flag);
	hjz = ft_is_hjz(f);
	if (((flag % 10000) / 1000) == 1 && ld != 0)
		char_putcount('0');
	if (hjz == 1)
		return (printf_octal2(f, type, (unsigned short)ld));
	else if (hjz == 2 && type == 'o')
		return (printf_octal2(f, type, (unsigned char)ld));
	else if (hjz == 3)
		return (printf_octal2(f, type, ld));
	else if (hjz == 4)
		return (printf_octal2(f, type, (size_t)ld));
	else if (hjz == 5)
		return (printf_octal2(f, type, (unsigned long long int)ld));
	else
		return (printf_octal2(f, type, (type == 'O') ? ld : (unsigned int)ld));
	return (NULL);
}

char *printf_hexa(char *f, char type, unsigned long long int ld)
{
	int		hjz;
	char	*out;
	int		flag;

	out = ft_strdup(f);
	printf_clean(&out, &flag);
	hjz = ft_is_hjz(f);
	if (hjz == 1)
		return (ft_puthex(ft_base16((unsigned short)ld), type, flag, f));
	else if (hjz == 2)
		return (ft_puthex(ft_base16((unsigned char)ld), type, flag, f));
	else if (hjz == 3)
		return (ft_puthex(ft_base16((unsigned long int)ld), type, flag, f));
	else if (hjz == 4)
		return (ft_puthex(ft_base16((size_t)ld), type, flag, f));
	else if (hjz == 5 || type == 'p')
		return (ft_puthex(ft_base16(ld), type, flag, f));
	else
		return (ft_puthex(ft_base16(ld), type, flag, f));
	out = NULL;
	return (NULL);
}
