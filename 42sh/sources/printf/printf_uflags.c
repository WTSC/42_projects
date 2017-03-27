/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 19:06:08 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:04:58 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <inttypes.h>
#include <sys/types.h>
#include <string.h>

void	ft_uputorchar(uintmax_t o, char type)
{
	if (id_chr("dDioOuU", type) == -1)
		char_putcount((char)o);
	else
		ft_putcount(0, ft_uitoa(o));
}

size_t	ft_usize(uintmax_t o, char type, int mode, int flag)
{
	size_t	size;

	(void)mode;
	(void)flag;
	size = (id_chr("dDioOuU", type) == -1) ? 1 : ft_int_len(o);
	return (size);
}

void	printf_uputjustified(size_t len, uintmax_t o, int flag, char type)
{
	if (((flag % 100) / 10) == 1)
	{
		ft_uputorchar(o, type);
		while (ft_usize(o, type, 0, flag) != len)
		{
			char_putcount(' ');
			len--;
		}
	}
	else
	{
		while (ft_size(o, type, 0, flag) != len)
		{
			char_putcount('0');
			len--;
		}
		ft_uputorchar(o, type);
	}
}

void	printf_ujustify(char *s, int flag, char type, uintmax_t o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_usize(o, type, 1, flag);
	if (((flag % 1000000) / 100000) == 1)
	{
		while (s[i] != '%')
			i++;
		while (ft_isdigit(s[i]) == 0 || s[i] == '0')
			i++;
		len = printf_prec(s, flag);
		if (size >= len)
			ft_uputorchar(o, type);
		else
			printf_uputjustified(len, o, flag, type);
	}
	else
		ft_uputorchar(o, type);
}

void	printf_uwidth(char *s, char type, uintmax_t o, int flag)
{
	size_t	len;
	size_t	size;

	size = ft_usize(o, type, 1, flag);
	if (printf_prec3(s) < printf_prec2(s, flag))
		printf_uprocess(o, type, flag, s);
	else
	{
		size = (printf_prec2(s, flag) > size) ? printf_prec2(s, flag) : size;
		len = printf_prec(s, flag);
		if (size >= len)
			printf_uprocess(o, type, flag, s);
		else
		{
			while (size != len)
			{
				char_putcount(' ');
				len--;
			}
			printf_uprocess(o, type, flag, s);
		}
	}
}
