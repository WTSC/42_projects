/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:59:34 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/12 21:01:52 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char **ft_arradd(char **a1, char *a2)
{
	char	**join;
	int		i;

	i = 0;
	join = (char **)malloc(sizeof(char *) * (array_size(a1) + 1));
	while (a1[i] != NULL)
	{
		join[i] = ft_strdup(a1[i]);
		i++;
	}
	join[i] = ft_strdup(a2);
	i++;
	join[i] = NULL;
	return (join);
}
