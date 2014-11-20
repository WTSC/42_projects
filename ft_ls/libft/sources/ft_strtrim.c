/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:03:57 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 16:25:39 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

char *ft_strtrim(char const *s)
{
	char	*copy;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	copy = (char *)malloc(ft_strlen(s) * sizeof(char));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
		j--;
	while (i <= j)
		copy[k++] = s[i++];
	return (copy);
}
