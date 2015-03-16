/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 20:30:38 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:22:45 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include <wchar.h>

void	printf_error(int id)
{
	(void)id;
}

int		write_null(void)
{
	ft_putcount(0, "(null)");
	return (ft_putcount(-1, NULL));
}

char	printf_get_flag(const char *o)
{
	int		i;
	char	*t;

	i = 0;
	t = ft_strdup("sSpdDioOuUxXcClhjz");
	while (o[i] != '\0')
	{
		if (o[i] == '%')
		{
			while (o[i + 1] && id_chr("#0123456789 -+.", o[i + 1]) != -1)
				i++;
			if (o[i + 1] && id_chr(t, o[i + 1]) != -1)
			{
				if (id_chr("lhjz", o[i + 1]) != -1)
					return (ft_modifier(o, o[i + 1], i + 1));
				else
					return (o[i + 1]);
			}
			else
				return (o[i + 1]);
		}
		i++;
	}
	return ('\0');
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	f;
	char	*out;

	if (format == NULL)
		return (write_null());
	out = ft_strdup(format);
	va_start(ap, format);
	while ((f = printf_get_flag(out)) != '\0')
		if (id_chr("ouxyOUXY", f) != -1)
			out = printf_ud(out, f, va_arg(ap, long unsigned int));
		else if (id_chr("DIdicp", f) != -1)
			out = printf_d(out, f, va_arg(ap, intmax_t));
		else if (f == 'C')
			out = printf_wchar(out, va_arg(ap, wchar_t));
		else if (id_chr("sS", f) != -1)
			out = printf_s(out, f, va_arg(ap, void *));
		else
			out = printf_percent(out, f);
	if (ft_strlen(out) > 1 || (ft_strlen(out) == 1 && out[0] != '%'))
		ft_putcount(0, out);
	free(out);
	va_end(ap);
	return (ft_putcount(-1, out) + ft_putwcount(-1, L"blob"));
}
