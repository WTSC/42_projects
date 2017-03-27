/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:11:40 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:33:50 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	map = (char *)malloc(ft_strlen(s) * sizeof(char));
	if (map == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = (*f)(s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
