/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_icore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:19:43 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:59:59 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <inttypes.h>

size_t		printf_prec3(char *s)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (s[i] != '%')
		i++;
	while (ft_isdigit(s[i]) != 1 || s[i] == '0')
		i++;
	len = ft_atoi(&s[i]);
	return (len);
}

size_t		printf_prec2(char *s, int flag)
{
	size_t		i;
	size_t		prec;

	if (((flag % 100000) / 10000) == 1)
	{
		i = 0;
		while (s[i] != '%')
			i++;
		while (s[i] != '.')
			i++;
		prec = ft_atoi(&s[i + 1]);
		return (prec);
	}
	else
		return (0);
}

void		printf_iprocess(intmax_t o, char type, int flag, char *f)
{
	size_t len;
	size_t size;

	if (((flag % 100000) / 10000) == 1 && type != 'c')
	{
		len = printf_prec2(f, flag);
		size = ft_size(o, type, 1, flag);
		if (o < 0)
			len++;
		if (size < len)
			printf_iputjustified(len, o, flag, type);
	}
	else
	{
		if (id_chr("sSpdDioOuUxXlhjz", type) != -1)
			ft_putcount(0, ft_itoa(o));
		else
			char_putcount((char)o);
	}
}
