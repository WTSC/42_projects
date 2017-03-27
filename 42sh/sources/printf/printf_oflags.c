/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 19:35:17 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:05:15 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <inttypes.h>
#include <sys/types.h>
#include <string.h>

void	printf_oputjustified(size_t len, uintmax_t o, int flag, char type)
{
	if (((flag % 100) / 10) == 1)
	{
		ft_putcount(0, ft_base(o, 8));
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
		ft_putcount(0, ft_base(o, 8));
	}
}

void	printf_ojustify(char *s, int flag, char type, uintmax_t o)
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
			ft_putcount(0, ft_base(o, 8));
		else
			printf_uputjustified(len, o, flag, type);
	}
	else
		ft_putcount(0, ft_base(o, 8));
}

void	printf_owidth(char *s, char type, uintmax_t o, int flag)
{
	size_t	len;
	size_t	size;

	size = ft_usize(o, type, 1, flag);
	if (printf_prec3(s) < printf_prec2(s, flag))
		printf_oprocess(o, type, flag, s);
	else
	{
		size = (printf_prec2(s, flag) > size) ? printf_prec2(s, flag) : size;
		len = printf_prec(s, flag);
		if (size >= len)
			printf_oprocess(o, type, flag, s);
		else
		{
			while (size != len)
			{
				char_putcount(' ');
				len--;
			}
			printf_oprocess(o, type, flag, s);
		}
	}
}
