/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_iflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:20:35 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:02:46 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <inttypes.h>
#include <sys/types.h>
#include <string.h>

void	ft_putorchar(intmax_t o, char type)
{
	if (id_chr("dDioOuU", type) == -1)
		char_putcount((char)o);
	else
		ft_putcount(0, ft_itoa(o));
}

size_t	ft_size(intmax_t o, char type, int mode, int flag)
{
	size_t	size;

	size = (id_chr("dDioOuU", type) == -1) ? 1 : ft_int_len(o);
	if (o < 0)
		size++;
	if (((flag % 1000) / 100) == 1 && type != 'c')
	{
		if (mode == 1)
			char_putcount((o >= 0) ? '+' : -42);
		size++;
	}
	else if (((flag % 10000000) / 1000000) == 1 && type != 'c')
	{
		if (mode == 1)
			char_putcount((o >= 0) ? ' ' : -42);
		size++;
	}
	return (size);
}

void	printf_iputjustified(size_t len, intmax_t o, int flag, char type)
{
	if (((flag % 100) / 10) == 1)
	{
		ft_putorchar(o, type);
		while (ft_size(o, type, 0, flag) != len)
		{
			char_putcount(' ');
			len--;
		}
	}
	else
	{
		if (o < 0 && id_chr("dDioOuU", type) != -1)
		{
			char_putcount('-');
			o *= -1;
			len--;
		}
		while (ft_size(o, type, 0, flag) != len)
		{
			char_putcount('0');
			len--;
		}
		ft_putorchar(o, type);
	}
}

void	printf_ijustify(char *s, int flag, char type, intmax_t o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_size(o, type, 1, flag);
	if (((flag % 1000000) / 100000) == 1)
	{
		while (s[i] != '%')
			i++;
		while (ft_isdigit(s[i]) == 0 || s[i] == '0')
			i++;
		len = printf_prec(s, flag);
		if (size >= len)
			ft_putorchar(o, type);
		else
			printf_iputjustified(len, o, flag, type);
	}
	else
		ft_putorchar(o, type);
}

void	printf_iwidth(char *s, char type, intmax_t o, int flag)
{
	size_t	len;
	size_t	size;

	size = ft_size(o, type, 1, flag);
	if (printf_prec3(s) < printf_prec2(s, flag))
		printf_iprocess(o, type, flag, s);
	else
	{
		size = (printf_prec2(s, flag) > size) ? printf_prec2(s, flag) : size;
		len = printf_prec(s, flag);
		if (size >= len)
			printf_iprocess(o, type, flag, s);
		else
		{
			while (size != len)
			{
				char_putcount(' ');
				len--;
			}
			printf_iprocess(o, type, flag, s);
		}
	}
}
