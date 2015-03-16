/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:53:45 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:31:14 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char *printf_sprocess(char *s, char type, char *f)
{
	int		flag;
	char	*out;
	char	*next;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	if (s != NULL)
		if ((((flag % 10000) / 1000) == 1 && ft_atoi(s) != 0
			&& (type == 'x' || type == 'X')) || type == 'p')
			ft_putcount(0, (type == 'x' || type == 'p') ? "0x" : "0X");
	if (s == NULL)
	{
		if (((flag % 100000) / 10000) == 1
			|| ((flag % 1000000) / 100000) == 1)
			return (printf_int(f, 'd', 0));
		else
			ft_putcount(0, "(null)");
	}
	else
		ft_putcount(0, s);
	return (next);
}
