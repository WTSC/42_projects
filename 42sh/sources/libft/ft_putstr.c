/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:56:26 by jantiope          #+#    #+#             */
/*   Updated: 2015/09/22 19:30:06 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}
