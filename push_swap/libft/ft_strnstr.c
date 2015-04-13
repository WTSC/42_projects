/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:44:13 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/21 10:15:01 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				c[2];

	if (!(s2) || ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		c[0] = 0;
		c[1] = i;
		while (c[0] >= 0 && s2[c[0]] != '\0' && i < n)
		{
			if (s1[i++] == s2[c[0]])
			{
				if (s2[++c[0]] == '\0' && i - 1 < n)
					return ((char *)&s1[c[1]]);
			}
			else
			{
				i = c[1] + 1;
				c[0] = -1;
			}
		}
	}
	return (NULL);
}
