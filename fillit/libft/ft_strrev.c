/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 04:10:22 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/21 09:26:53 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char *ft_strrev(char *s)
{
	char	*rev;
	int		i;
	int		size;

	if (s == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	rev = (char *)malloc(sizeof(char) * size + 1);
	if (rev == NULL)
		return (NULL);
	size--;
	while (size != -1)
		rev[i++] = s[size--];
	rev[i] = '\0';
	return (rev);
}
