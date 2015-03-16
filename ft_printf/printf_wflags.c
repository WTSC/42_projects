/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 11:00:16 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:04:51 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <wchar.h>

void		printf_wputjustified(size_t size, size_t len, wchar_t *o, char pad)
{
	if (pad == '0')
	{
		while (size != len)
		{
			char_putcount('0');
			len--;
		}
		ft_putwcount(0, o);
	}
	else
	{
		ft_putwcount(0, o);
		while (size != len)
		{
			char_putcount(' ');
			len--;
		}
	}
}

void		printf_wjustify(char *s, int flag, char pad, wchar_t *o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_wstrbyte(o);
	if (((flag % 1000000) / 100000) == 1)
	{
		while (s[i] != '%')
			i++;
		while (ft_isdigit(s[i]) == 0 || s[i] == '0')
			i++;
		len = ft_atoi(&s[i]);
		if (size >= len)
			ft_putwcount(0, o);
		else
			printf_wputjustified(size, len, o, pad);
	}
	else
		ft_putwcount(0, o);
}

wchar_t		*printf_wprec(char *s, wchar_t *o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_wstrbyte(o);
	while (s[i] != '%')
		i++;
	while (s[i] != '.')
		i++;
	len = ft_atoi(&s[i + 1]);
	if (size <= len)
		return (o);
	else
	{
		o = ft_wstrsub(o, 0, len);
		return (o);
	}
}

void		printf_wwidth(char *s, wchar_t *o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_wstrbyte(o);
	while (s[i] != '%')
		i++;
	while (ft_isdigit(s[i]) != 1 && s[i] != '0')
		i++;
	len = ft_atoi(&s[i]);
	if (size >= len)
		ft_putwcount(0, o);
	else
	{
		while (size != len)
		{
			char_putcount(' ');
			len--;
		}
		ft_putwcount(0, o);
	}
}
