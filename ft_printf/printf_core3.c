/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:32:59 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:59:50 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

int		ft_putcount(int type, char *s)
{
	static int	c;
	int			c_;

	c_ = c;
	if (type == 0 || type == 1)
	{
		c += (type == 1) ? 1 : ft_strlen(s);
		ft_putstr(s);
	}
	if (type == -1)
		c = 0;
	return ((type == -1) ? c_ : c);
}

void	char_putcount(char c)
{
	char *s;

	s = (char *)malloc(sizeof(char) * 2);
	if (s && c != -42)
	{
		s[0] = c;
		s[1] = '\0';
		if (!ft_isprint(c))
			ft_putcount(1, s);
		else
			ft_putcount(0, s);
		free(s);
		s = NULL;
	}
}

char	*ft_puthex(char *s, char type, int flag, char *f)
{
	if (((flag % 100000) / 10000) == 1)
		s = ft_getzeros(f, s, flag);
	if (type == 'x' || type == 'p')
		s = ft_strtolower(s);
	if (((flag % 100) / 10) == 1 || ((flag % 10) / 1) == 1)
	{
		return (printf_string(f, s, type));
	}
	else if (((flag % 1000000) / 100000) == 1)
	{
		return (printf_string(f, s, type));
	}
	else
	{
		return (printf_string(f, s, type));
	}
}

char	*printf_wchar(char *f, wchar_t c)
{
	char	*out;
	char	*next;
	int		flag;
	int		hjz;

	hjz = ft_is_hjz(f);
	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	if (hjz == 2 && c <= 127)
		char_putwcount((signed char)c);
	else
		char_putwcount(c);
	return (next);
}
