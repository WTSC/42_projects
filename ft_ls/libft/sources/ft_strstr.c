/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:07:52 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/04 22:26:41 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int tmp;

	if (!(s2))
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
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
