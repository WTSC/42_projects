/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:08:09 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 17:21:07 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_atoi(const char *str)
{
	int i;
	int conv;
	int is_negative;

	if (str == NULL)
		return (0);
	i = 0;
	conv = 0;
	is_negative = 0;
	while ((str[i] >= 8 && str[i] <= 13)
		|| str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48))
		conv = (conv * 10) + (str[i++] - 48);
	if (is_negative)
		conv *= -1;
	return (conv);
}
