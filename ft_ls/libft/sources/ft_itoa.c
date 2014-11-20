/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:53:21 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 18:24:33 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		ft_int_len(int num)
{
	int len;

	len = 0;
	if (num < 10 && num > -10)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*out;
	int		len;
	int		tmp;

	len = ft_int_len(n);
	out = (char *)malloc((len * sizeof(char)));
	if (!out)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
	}
	else
		len--;
	while (len != -1)
	{
		if (len == 0 && out[len] == '-')
			break ;
		tmp = n % 10;
		out[len] = (tmp + 48);
		n /= 10;
		len--;
	}
	return (out);
}
