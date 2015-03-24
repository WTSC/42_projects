/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:48:02 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/03 18:16:23 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (!s1 || s1 == NULL)
		return (NULL);
	if (!s2 || s2 == NULL)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
