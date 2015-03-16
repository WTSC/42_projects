/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 03:02:17 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/02 02:26:35 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"
#include "string.h"
#include <inttypes.h>
#include <sys/types.h>

char			*ft_base16(uintmax_t n)
{
	long unsigned int	div;
	int					mod;
	char				*convert;
	int					i;

	i = 0;
	convert = ft_strnew(11);
	div = n;
	while (div != 0)
	{
		div = n / 16;
		mod = n % 16;
		n = div;
		if (mod > 9)
			convert[i++] = mod + 55;
		else
			convert[i++] = mod + 48;
	}
	convert = ft_strrev(convert);
	return (convert);
}

uintmax_t		ft_tobase10(char *n, int base)
{
	int i;
	int conv;
	int power;

	conv = 0;
	power = 0;
	i = ft_strlen(n);
	i--;
	while (i != -1)
	{
		if (base == 16
			&& ((n[i] >= 65 && n[i] <= 70) || (n[i] >= 97 && n[i] <= 102)))
			conv += (n[i--] - 55) * ft_power(base, power);
		else
			conv += (n[i--] - 48) * ft_power(base, power);
		power++;
	}
	return (conv);
}

char			*ft_base(uintmax_t n, unsigned int base)
{
	int		div;
	int		mod;
	char	*convert;
	int		i;

	i = 0;
	convert = ft_strnew(17);
	div = n;
	if (base > 10)
		return (0);
	while (div != 0)
	{
		div = n / base;
		mod = n % base;
		n = div;
		convert[i++] = mod + 48;
	}
	convert = ft_strrev(convert);
	return (convert);
}
