/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:28:39 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:27:47 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*test;

	test = (unsigned char *)s2;
	str = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (str[i] == test[i])
			i++;
		else
			return (str[i] - test[i]);
	}
	return (0);
}
