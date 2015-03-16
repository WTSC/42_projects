/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:59:01 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 18:23:04 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

void *ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*src;

	if (!s1 || !s2 || n == 0)
		return (s1);
	src = (char *)malloc(n * sizeof(char));
	ft_memcpy(src, s2, n);
	ft_memcpy(s1, src, n);
	free(src);
	return (s1);
}
