/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 04:18:59 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:53:10 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"

int		ft_setflags(char c, int *flag)
{
	if (c == '-')
		*flag += 10;
	if (c == '+')
		*flag += 100;
	if (c == '#')
		*flag += 1000;
	if (c == ' ')
		*flag += 1000000;
	return (*flag);
}

void	is_dot_valid(char *f, int *flag, int i)
{
	if (ft_atoi(&f[i + 1]) == 0)
	{
		if (f[i + 1] == '0' && id_chr("sSpdDioOuUxXcClqQyY", f[i + 2]) != -1)
			*flag += 10000;
		else if (id_chr("sSpdDioOuUxXcClqQyY", f[i + 1]) != -1)
			*flag += 10000;
	}
	else
	{
		i++;
		while (ft_isdigit(f[i]))
			i++;
		if (id_chr("sSpdDioOuUxXcClqQyY", f[i]) != -1)
			*flag += 10000;
	}
}

int		ft_is_binary(char *seq)
{
	int i;

	i = 0;
	while (seq[i] != '\0')
		if (seq[i] == '0' || seq[i] == '1')
			i++;
		else
			return (0);
	return (1);
}

char	ft_modifier(const char *o, char mod, int i)
{
	if (o[i + 1] == mod)
	{
		if (mod == 'h' && id_chr("diouxXDOUCS", o[i + 2]) != -1)
			return (o[i + 2]);
		else if (mod == 'l' && id_chr("diouxXDOUCS", o[i + 2]) != -1)
			return (o[i + 2]);
		else
			printf_error(-1);
	}
	else
	{
		if (id_chr("hjz", mod) != -1 && id_chr("diouxXDOUCS", o[i + 1]) != -1)
			return (o[i + 1]);
		else if (mod == 'l' && id_chr("scdDUOXiouxCSp", o[i + 1]) != -1)
			return ((o[i + 1] == 'x' || o[i + 1] == 'p') ?
			o[i + 1] : ft_toupper(o[i + 1]));
		else
			printf_error(-1);
	}
	return (mod);
}

int		ft_is_hjz(char *f)
{
	int i;

	i = id_chr(f, '%');
	while (id_chr("#0123456789 -+.", f[i + 1]) != -1)
		i++;
	if (f[i + 1] == 'h' && f[i + 2] == 'h')
	{
		if (id_chr("diouxXCcOU", f[i + 3]) != -1)
			return (2);
	}
	else if (f[i + 1] == 'l' && f[i + 2] == 'l')
	{
		if (id_chr("diouxXCcOU", f[i + 3]) != -1)
			return (5);
	}
	else if (f[i + 1] == 'h' && id_chr("diouxXCcOU", f[i + 2]) != -1)
		return (1);
	else if (f[i + 1] == 'j' && id_chr("diouxXCcOU", f[i + 2]) != -1)
		return (3);
	else if (f[i + 1] == 'z' && id_chr("diouxXCcOU", f[i + 2]) != -1)
		return (4);
	else
		return (0);
	return (0);
}
