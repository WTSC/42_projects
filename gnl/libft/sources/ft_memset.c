/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:20:17 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/04 23:36:06 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*data;

	i = 0;
	data = (char *)b;
	while (i < len)
	{
		data[i] = (char)c;
		i++;
	}
	return (b);
}
