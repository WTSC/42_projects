/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 13:47:00 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:03:01 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	wchar_t	*sub;

	i = start;
	j = 0;
	if (s == NULL || (start + len) > ft_wstrlen((wchar_t *)s))
		return (NULL);
	sub = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
	if (!sub)
		return (NULL);
	while (j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
