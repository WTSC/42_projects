/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:44:13 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/04 22:44:15 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;
	int				tmp;

	if (!(s2))
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		tmp = i;
		while (j >= 0 && s2[j] != '\0')
		{
			if (s1[i++] == s2[j])
			{
				j++;
				if (s2[j] == '\0')
					return ((char *)&s1[tmp]);
			}
			else
				j = -1;
		}
	}
	return (NULL);
}
