/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:53:21 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/02 03:12:48 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../includes/libft.h"
#include <inttypes.h>
#include <sys/types.h>

char			*ft_itoa(intmax_t n)
{
	char	*out;
	int		len;
	int		tmp;

	if (n == -2147483648)
		return ("-2147483648");
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
		tmp = n % 10;
		out[len--] = (tmp + 48);
		n /= 10;
	}
	return (out);
}
