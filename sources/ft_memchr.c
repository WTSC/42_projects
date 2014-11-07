/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:52:32 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/04 23:02:34 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char			*data;
	unsigned int	i;

	data = (char *)s;
	while (i < n)
	{
		if (data[i] == c)
			return ((char*)&data[i]);
		i++;
	}
	return (NULL);
}
