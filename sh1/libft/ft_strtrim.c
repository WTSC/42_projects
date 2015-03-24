/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:03:57 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/21 11:41:36 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		ft_is_empty(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s)
{
	char	*copy;
	size_t	i;
	size_t	j;
	size_t	k;

	if (ft_is_empty(s))
		return ("");
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
		j--;
	if (!(copy = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		copy[k++] = s[i++];
	copy[k] = '\0';
	return (copy);
}


char	*ft_supertrim(char const *s)
{
	char	*copy;
	size_t	i;
	size_t	j;
	int	onespace;

	i = 0;
	j = 0;

	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
		
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			if (onespace == 0)
			{
				copy[j++] = s[i];	
				onespace = 1;
			}
			i++;
		}
		else
		{
			copy[j++] = s[i++];
			onespace = 0;		
		}
	}
	copy[j] = '\0';
	return (copy);
}
