/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:17:30 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:30:17 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"

char	*ft_getzeros(char *f, char *s, int flag)
{
	size_t		prec;
	char		*zeros;

	zeros = NULL;
	prec = printf_prec2(f, flag);
	while (prec > ft_strlen(s))
	{
		zeros = ft_strjoin(zeros, "0");
		prec--;
	}
	zeros = ft_strjoin(zeros, s);
	return (zeros);
}

void	printf_putjustified(size_t size, size_t len, int flag, char *o)
{
	if (((flag % 100) / 10) == 1)
	{
		ft_putcount(0, o);
		while (size != len)
		{
			char_putcount(' ');
			len--;
		}
	}
	else
	{
		while (size != len)
		{
			char_putcount('0');
			len--;
		}
		ft_putcount(0, o);
	}
}

void	printf_justify(char *s, int flag, char type, char *o)
{
	int		i;
	size_t	len;

	i = 0;
	if (((flag % 1000000) / 100000) == 1)
	{
		while (s[i] != '%')
			i++;
		while (ft_isdigit(s[i]) == 0 || s[i] == '0')
			i++;
		len = ft_atoi(&s[i]);
		if ((((flag % 10000) / 1000) == 1 && ft_atoi(s) != 0
			&& (type == 'x' || type == 'X')) || type == 'p')
		{
			ft_putcount(0, "0x");
			len -= 2;
		}
		if (ft_strlen(o) >= len)
			ft_putcount(0, o);
		else
			printf_putjustified(ft_strlen(o), len, flag, o);
	}
	else
		ft_putcount(0, o);
}

void	printf_fdp(size_t len, int flag, char type, char *o)
{
	size_t size;

	size = ft_strlen(o);
	if ((((flag % 10000) / 1000) == 1 && ft_atoi(o) != 0) || type == 'p')
		len -= 2;
	while (size != len)
	{
		char_putcount(' ');
		len--;
	}
	if ((((flag % 10000) / 1000) == 1 && ft_atoi(o) != 0) || type == 'p')
		ft_putcount(0, "0x");
	ft_putcount(0, o);
}

void	printf_width(char *s, int flag, char type, char *o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_strlen(o);
	while (s[i] != '%')
		i++;
	while (ft_isdigit(s[i]) != 1 || s[i] == '0')
		i++;
	len = ft_atoi(&s[i]);
	if (size >= len)
	{
		if ((((flag % 10000) / 1000) == 1 && ft_atoi(o) != 0) || type == 'p')
			ft_putcount(0, "0x");
		ft_putcount(0, o);
	}
	else
		printf_fdp(len, flag, type, o);
}
