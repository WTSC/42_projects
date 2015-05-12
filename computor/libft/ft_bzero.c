/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:37:58 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/04 23:45:00 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*data;

	i = 0;
	data = (char *)s;
	while (i < n)
	{
		data[i] = '\0';
		i++;
	}
}