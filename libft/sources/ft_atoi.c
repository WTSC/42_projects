/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:08:09 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/06 22:50:06 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int i;
	int conv;
	int is_negative;

	i = 0;
	conv = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48))
	{
		conv = (conv * 10) + (str[i] - 48);
		i++;
	}
	if (is_negative)
		conv *= -1;
	return (conv);
}
