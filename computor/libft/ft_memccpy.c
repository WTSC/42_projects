/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:57:34 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:02:18 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*data;
	char			*source;
	unsigned int	i;

	data = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		data[i] = source[i];
		if (source[i] == (char)c)
			return (&data[i + 1]);
		i++;
	}
	return (NULL);
}
