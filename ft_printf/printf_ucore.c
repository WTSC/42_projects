/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ucore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 19:30:21 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:17:45 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "ft_printf.h"

void printf_uprocess(uintmax_t o, char type, int flag, char *f)
{
	size_t len;
	size_t size;

	if (((flag % 100000) / 10000) == 1)
	{
		len = printf_prec2(f, flag);
		size = ft_usize(o, type, 1, flag);
		if (((flag % 10000) / 1000) == 1 && o != 0)
			len--;
		if (size < len)
			printf_uputjustified(len, o, flag, type);
	}
	else
	{
		if (type != 'c')
			ft_putcount(0, ft_uitoa(o));
		else if (type == 'c' || id_chr("sSpdDioOuUxXcClhjz", type) == -1)
			char_putcount((char)o);
	}
}

char *printf_uint2(char *f, char type, uintmax_t i)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	if (((flag % 100) / 10) == 1)
		printf_ujustify(f, flag, type, i);
	else if (((flag % 10) / 1) == 1)
		printf_ujustify(f, flag, type, i);
	else if (((flag % 1000000) / 100000) == 1)
		printf_uwidth(f, type, i, flag);
	else
	{
		printf_uprocess(i, type, flag, f);
	}
	return (next);
}
