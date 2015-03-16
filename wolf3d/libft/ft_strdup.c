/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:14:46 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:49:06 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char *ft_freedup(char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = NULL;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(copy))
	{
		write(2, "Memory allocation error\n", 25);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	free(s1);
	s1 = NULL;
	return (copy);
}

char *ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = NULL;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(copy))
	{
		write(2, "Memory allocation error\n", 25);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
