/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ocore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 15:00:01 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:38:19 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "ft_printf.h"

void printf_oprocess(uintmax_t o, char type, int flag, char *f)
{
	size_t len;
	size_t size;

	if (((flag % 100000) / 10000) == 1)
	{
		len = printf_prec2(f, flag);
		size = ft_usize(o, type, 1, flag);
		if (((flag % 10000) / 1000) == 1 && o != 0 && len != 0)
			len--;
		if (size < len && len != 0)
			printf_oputjustified(len, o, flag, type);
		else if (len != 0 || (len == 0 && ((flag % 10000) / 1000) == 1))
			ft_putcount(0, ft_base(o, 8));
	}
	else
		ft_putcount(0, ft_base(o, 8));
}

char *printf_octal2(char *f, char type, uintmax_t i)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	if (((flag % 100) / 10) == 1)
		printf_ojustify(f, flag, type, i);
	else if (((flag % 10) / 1) == 1)
		printf_ojustify(f, flag, type, i);
	else if (((flag % 1000000) / 100000) == 1)
		printf_owidth(f, type, i, flag);
	else
	{
		printf_oprocess(i, type, flag, f);
	}
	return (next);
}
