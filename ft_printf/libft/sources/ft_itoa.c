/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:53:21 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/26 20:03:13 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../includes/libft.h"
#include <inttypes.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>

char			*ft_limits(intmax_t n)
{
	if (n == -1)
		return (NULL);
	if (n == LONG_MIN || n == LLONG_MIN)
		return ("-9223372036854775808");
	if (n == LONG_MAX || n == LLONG_MAX)
		return ("9223372036854775807");
	if (n == INT_MIN || n == INT_MAX)
		return ((n == INT_MIN) ? "-2147483648" : "2147483647");
	if (n == SHRT_MIN || n == SHRT_MAX)
		return ((n == SHRT_MIN) ? "-32768" : "32767");
	return (NULL);
}

char			*ft_itoa(intmax_t n)
{
	char		*out;
	int			len;
	intmax_t	tmp;

	if (ft_limits(n) != NULL)
		return (ft_limits(n));
	len = ft_int_len(n);
	out = ft_strnew(len + 1);
	if (!out)
		return (NULL);
	if (n < 0)
		n *= (out[0] = '-') - 46;
	else
		len--;
	while (len != -1)
	{
		if (len == 0 && out[len] == '-')
			break ;
		tmp = (long int)n % 10;
		out[len--] = (tmp + 48);
		n /= 10;
	}
	return (out);
}

char			*ft_ulimits(intmax_t n)
{
	if (n == LONG_MAX || n == LLONG_MAX)
		return ("9223372036854775807");
	if (n == INT_MAX)
		return ("2147483647");
	if (n == SHRT_MAX)
		return ("32767");
	if ((unsigned long)n == ULONG_MAX || (unsigned long)n == ULLONG_MAX)
		return ("18446744073709551615");
	if ((unsigned int)n == UINT_MAX)
		return ("4294967295");
	if ((unsigned short)n == USHRT_MAX)
		return ("65535");
	return (NULL);
}

char			*ft_uitoa(uintmax_t n)
{
	char		*out;
	int			len;
	intmax_t	tmp;

	if (ft_ulimits(n) != NULL)
		return (ft_ulimits(n));
	len = ft_int_len(n);
	out = ft_strnew(len + 1);
	if (!out)
		return (NULL);
	len--;
	while (len != -1)
	{
		tmp = (long int)n % 10;
		out[len--] = (tmp + 48);
		n /= 10;
	}
	return (out);
}
