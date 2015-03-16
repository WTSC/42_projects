/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:57:33 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 18:22:28 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_putnbr_fd(int n, int fd)
{
	int	tmp;
	int	power;

	power = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd((char)((n / power)) + 48, fd);
		n %= power;
		power /= 10;
	}
}
