/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:59:45 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/14 23:33:10 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char *ft_strnew(size_t size)
{
	char *str;

	if (size == 0)
		return (NULL);
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
