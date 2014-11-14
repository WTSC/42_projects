/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:59:45 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/06 17:33:34 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(size * sizeof(char));
	ft_bzero(str, size);
	if (!str)
		return (NULL);
	return (str);
}
