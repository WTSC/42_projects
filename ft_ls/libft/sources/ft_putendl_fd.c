/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:57:07 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/07 15:57:12 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putendl_fd(const char *s, int fd)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	write(1, "\n", 1);
}