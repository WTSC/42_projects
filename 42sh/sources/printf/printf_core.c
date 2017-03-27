/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 00:11:59 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 12:51:35 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

char	*printf_clean(char **f, int *flag)
{
	int		i;
	char	*next;
	char	*sub;
	int		j;

	i = 0;
	while ((*f)[i] != '%' && (*f)[i] != '\0')
		i++;
	*flag = 0;
	j = printf_flags(*f, flag, i + 1, i);
	while (id_chr("#0123456789 -+.lhjz", (*f)[j + 1]) != -1)
		j++;
	sub = ft_strsub(*f, 0, i);
	if (ft_is_binary(ft_itoa(*flag)) == 0)
		printf_error(2);
	if ((*f)[i + 1] == 'l')
		i = j + 2;
	else
		i = j + 2;
	j = ft_strlen(*f);
	j -= i;
	next = ft_strsub(*f, i, j);
	*f = sub;
	return (next);
}

char	*printf_wstring(char *f, wchar_t *s)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	if (s == NULL)
		ft_putcount(0, "(null)");
	else
	{
		if (((flag % 100000) / 10000) == 1)
			s = printf_wprec(f, s);
		if (((flag % 100) / 10) == 1)
			printf_wjustify(f, flag, ' ', s);
		else if (((flag % 10) / 1) == 1)
			printf_wjustify(f, flag, '0', s);
		else if (((flag % 1000000) / 100000) == 1)
			printf_wwidth(f, s);
		else
			ft_putwcount(0, s);
	}
	out = NULL;
	return (next);
}

char	*printf_string(char *f, char *s, char type)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	if (s != NULL
		|| (s == NULL
		&& (flag % 100000) / 10000 != 1 && (flag % 1000000) / 100000 != 1))
		ft_putcount(0, out);
	if (s != NULL && ((flag % 100000) / 10000) == 1)
		s = printf_cprec(f, s);
	if (s != NULL && ((flag % 100) / 10) == 1)
		printf_justify(f, flag, type, s);
	else if (s != NULL && ((flag % 10) / 1) == 1)
		printf_justify(f, flag, type, s);
	else if (s != NULL && ((flag % 1000000) / 100000) == 1)
		printf_width(f, flag, type, s);
	else
		printf_sprocess(s, type, f);
	out = NULL;
	return (next);
}

char	*printf_int(char *f, char type, intmax_t i)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	ft_putcount(0, out);
	if (((flag % 100) / 10) == 1)
		printf_ijustify(f, flag, type, i);
	else if (((flag % 10) / 1) == 1)
		printf_ijustify(f, flag, type, i);
	else if (((flag % 1000000) / 100000) == 1)
		printf_iwidth(f, type, i, flag);
	else
	{
		if (((flag % 1000) / 100) == 1 && type != 'c')
			char_putcount((i > 0) ? '+' : -42);
		else if (((flag % 10000000) / 1000000) == 1 && type != 'c')
			char_putcount((i > 0) ? ' ' : -42);
		printf_iprocess(i, type, flag, f);
	}
	return (next);
}

char	*printf_percent(char *f, char type)
{
	char	*out;
	char	*next;
	int		flag;

	out = ft_strdup(f);
	next = printf_clean(&out, &flag);
	if (ft_strlen(f) == 1)
		return (next);
	ft_putcount(0, out);
	if (((flag % 100) / 10) == 1)
		printf_ijustify(f, flag, ' ', type);
	else if (((flag % 10) / 1) == 1)
		printf_ijustify(f, flag, '0', type);
	else if (((flag % 1000000) / 100000) == 1)
		printf_iwidth(f, type, type, flag);
	else
		char_putcount(type);
	free(out);
	out = NULL;
	return (next);
}
