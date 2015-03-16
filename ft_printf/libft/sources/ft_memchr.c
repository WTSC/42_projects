/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:52:32 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/14 22:55:17 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char			*data;
	unsigned int	i;

	i = 0;
	data = (char *)s;
	while (i < n)
	{
		if (data[i] == c)
			return (&data[i]);
		i++;
	}
	return (NULL);
}
