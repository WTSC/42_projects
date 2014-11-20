/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:08:43 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/06 22:17:12 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = start;
	j = 0;
	sub = (char *)malloc(len * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[i] != '\0')
		sub[j++] = s[i++];
	return (sub);
}
