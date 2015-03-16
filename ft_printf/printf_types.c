/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 20:51:03 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:04:42 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <wchar.h>

int		printf_flags(char *f, int *flag, int i, int j)
{
	while (id_chr("0123456789 -+#.", f[i]) != -1)
	{
		if (ft_isdigit(f[i]))
		{
			if (f[i] == '0')
				*flag += 1;
			else
			{
				while (ft_isdigit(f[i + 1]))
					i++;
				*flag += 100000;
			}
		}
		*flag = ft_setflags(f[i], flag);
		if (f[i] == '.')
		{
			is_dot_valid(f, flag, i);
			return (j);
		}
		i++;
	}
	return (j);
}

int		ft_has_mod(char *f)
{
	int i;

	i = id_chr(f, '%');
	if (f[i + 1] == 'l')
		return (1);
	return (0);
}

char	*printf_ud(char *f, char type, uintmax_t ld)
{
	unsigned int	d;
	int				l;

	d = ld;
	l = ft_has_mod(f);
	if (type == 'o')
		return (printf_octal(f, type, ld));
	if (type == 'O')
		return (printf_octal(f, type, (ft_is_hjz(f) > 0)
		? ld : (long unsigned int)ld));
	if (type == 'u')
		return (printf_uint(f, type, ld));
	if (type == 'U')
		return (printf_uint(f, type, (ft_is_hjz(f) > 0)
		? ld : (long unsigned int)ld));
	if (type == 'x' || 'X')
	{
		if (l == 1)
			return (printf_hexa(f, type, (long unsigned int)ld));
		else
			return (printf_hexa(f, type, (ft_is_hjz(f) > 0)
			? ld : d));
	}
	return (f);
}

char	*printf_d(char *f, char type, intmax_t ld)
{
	int d;
	int hjz;

	d = ld;
	hjz = ft_is_hjz(f);
	if (type == 'D' || type == 'I')
		return (printf_lint(f, (long int)ld));
	if (type == 'd' || type == 'i' || type == 'c')
	{
		if (hjz == 1 && type != 'c')
			return (printf_int(f, type, (short int)d));
		else if (hjz == 3 && type != 'c')
			return (printf_int(f, type, ld));
		else if (hjz == 4 && type != 'c')
			return (printf_int(f, type, (size_t)ld));
		else if (hjz == 2 && type != 'c')
			return (printf_int(f, type, (signed char)d));
		else if (hjz == 5 && type != 'c')
			return (printf_int(f, type, (long long int)ld));
		else
			return (printf_int(f, type, d));
	}
	if (type == 'p')
		return (printf_hexa(f, 'p', ld));
	return (f);
}

char	*printf_s(char *f, char type, void *s)
{
	if (type == 'p')
		return (printf_hexa(f, type, ft_atoi(s)));
	else if (type == 'S')
		return (printf_wstring(f, (wchar_t *)s));
	else if (type == 's')
		return (printf_string(f, (char *)s, type));
	return (f);
}
