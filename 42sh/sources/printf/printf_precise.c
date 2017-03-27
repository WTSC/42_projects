/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 13:21:59 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 19:35:03 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <inttypes.h>
#include <sys/types.h>

char			*printf_cprec(char *s, char *o)
{
	int		i;
	size_t	len;
	size_t	size;

	i = 0;
	size = ft_strlen(o);
	while (s[i] != '%')
		i++;
	while (s[i] != '.')
		i++;
	len = ft_atoi(&s[i + 1]);
	if (size <= len)
		return (o);
	else
	{
		o = ft_strsub(o, 0, len);
		return (o);
	}
}

int				printf_iprec(char *s, int flag, char type)
{
	size_t		i;
	size_t		len;
	size_t		prec;

	i = 0;
	(void)type;
	while (s[i] != '%')
		i++;
	while (ft_isdigit(s[i]) != 1 || s[i] == '0')
		i++;
	len = ft_atoi(&s[i]);
	if (((flag % 100000) / 10000) == 0)
		return (len);
	while (s[i] != '.')
		i++;
	prec = ft_atoi(&s[i + 1]);
	i = 0;
	while (i < len - prec)
	{
		char_putcount('0');
		i++;
	}
	if (prec < len)
		len = prec;
	return (len);
}

size_t			printf_prec(char *s, int flag)
{
	size_t		i;
	size_t		len;
	size_t		prec;

	i = 0;
	while (s[i] != '%')
		i++;
	while (ft_isdigit(s[i]) != 1 || s[i] == '0')
		i++;
	len = ft_atoi(&s[i]);
	if (((flag % 100000) / 10000) == 0)
		return (len);
	while (s[i] != '.')
		i++;
	prec = ft_atoi(&s[i + 1]);
	i = 0;
	while (i < len - prec && prec != 0)
	{
		char_putcount(' ');
		i++;
	}
	if (prec < len && prec != 0)
		len = prec;
	return (len);
}
