/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:11:40 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 18:21:25 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	i = 0;
	map = (char *)malloc(ft_strlen(s) * sizeof(char));
	while (s[i] != '\0')
	{
		map[i] = (*f)(s[i]);
		i++;
	}
	return (map);
}
