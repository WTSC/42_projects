/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 04:11:31 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/02 00:56:46 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <inttypes.h>
#include <sys/types.h>

int ft_int_len(intmax_t num)
{
	int len;

	len = 0;
	if (num < 10 && num > -10)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
