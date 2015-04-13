/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:45:34 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/14 23:06:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int both_neg(const char *s1, const char *s2)
{
	if (s1[0] == '-' && s2[0] == '-')
		return (3);
	else if (s1[0] == '-')
		return (1);
	else if (s2[0] == '-')
		return (2);
	else
		return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_nbrcmp(const char *s1, const char *s2)
{
	if (both_neg(s1, s2) == 3 && ft_strlen(s1) == ft_strlen(s2)
	&& ft_strcmp(s1, s2) > 0)
		return (-1);
	else if (both_neg(s1, s2) == 3 && ft_strlen(s1) == ft_strlen(s2)
	&& ft_strcmp(s1, s2) < 0)
		return (1);
	else if (both_neg(s1, s2) == 3 && ft_strlen(s1) > ft_strlen(s2))
		return (-1);
	else if (both_neg(s1, s2) == 3 && ft_strlen(s1) < ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) == ft_strlen(s2) && ft_strcmp(s1, s2) > 0)
		return (1);
	else if (ft_strlen(s1) == ft_strlen(s2) && ft_strcmp(s1, s2) < 0)
		return (-1);
	else if (ft_strlen(s1) == ft_strlen(s2) && ft_strcmp(s1, s2) == 0)
		return (0);
	else if (ft_strlen(s1) == ft_strlen(s2) && ft_strcmp(s1, s2) == 0)
		return (0);	
	else if (ft_strlen(s1) > ft_strlen(s2))
		return ((both_neg(s1, s2) == 1) ? -1 : 1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return ((both_neg(s1, s2) == 2) ? 1 : -1);
}
