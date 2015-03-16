/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 03:14:05 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/18 03:23:27 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_power(int n, int power)
{
	int result;

	if (power < 0 || n == 0)
		return (0);
	if (power == 0)
		return (1);
	result = n;
	while (power != 1)
	{
		result *= n;
		power--;
	}
	return (result);
}
