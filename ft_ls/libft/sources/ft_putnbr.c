/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:56:41 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 18:22:46 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_putnbr(int n)
{
	int	tmp;
	int	power;

	power = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	tmp = n;
	while (tmp > 1)
	{
		tmp /= 10;
		power *= 10;
	}
	while (power)
	{
		ft_putchar((char)((n / power)) + 48);
		n %= power;
		power /= 10;
	}
}
