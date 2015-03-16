/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 13:47:00 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/27 20:54:57 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

int			ft_wchb(wchar_t c)
{
	char	*bin;
	int		len;

	bin = ft_base(c, 2);
	len = ft_strlen(bin);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	else
		return (4);
}

size_t		ft_wstrb(wchar_t *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
		count += ft_wchb(s[i++]);
	return (count);
}

wchar_t		*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tot;
	wchar_t	*sub;

	i = start;
	j = 0;
	tot = 0;
	if (s == NULL || (start + len) > ft_wstrb((wchar_t *)s))
		return (NULL);
	sub = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
	if (!sub)
		return (NULL);
	while (tot + ft_wchb(s[i]) <= len)
	{
		tot += ft_wchb(s[i]);
		sub[j++] = s[i++];
	}
	sub[j] = '\0';
	return (sub);
}
