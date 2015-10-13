/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 01:27:17 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:00:45 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	ft_putarray(char **array, char s)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i++]);
		if (array[i] != NULL)
		{
			if (s != 32 && s != 10)
				ft_putchar(' ');
			ft_putchar(s);
			if (s != 32 && s != 10)
				ft_putchar(' ');
		}
	}
}

char	**ft_arrcat(char **arr1, const char **arr2)
{
	unsigned int i;
	unsigned int j;

	i = array_size(arr1);
	j = 0;
	while (arr2[j] != NULL)
	{
		arr1[i] = ft_strdup(arr2[j]);
		i++;
		j++;
	}
	arr1[i] = NULL;
	return (arr1);
}

char	**ft_arrcpy(char **dst, const char **src)
{
	unsigned int i;

	i = 0;
	while (src[i] != NULL)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	return (dst);
}

char	**ft_arrdup(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	dst = (char **)malloc((sizeof(char *) * array_size(src)) + 1);
	while (src[i] != NULL)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

char	**ft_arrjoin(char **dst, char **src)
{
	char	**join;
	int		len;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == NULL)
		return (src);
	if (src == NULL)
		return (dst);
	len = array_size(dst) + array_size(src);
	join = (char **)malloc((sizeof(char *) * len) + 1);
	join = ft_arrcpy(join, (const char **)dst);
	join = ft_arrcat(join, (const char **)src);
	return (join);
}
