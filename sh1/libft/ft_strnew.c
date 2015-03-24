/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:59:45 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/21 11:33:05 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
