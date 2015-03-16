/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:54:04 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:37:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include <string.h>

int		ft_rgb(int r, int g, int b)
{
	int		dec;

	r = (r > 255) ? 255 : r + 0;
	g = (g > 255) ? 255 : g + 0;
	b = (b > 255) ? 255 : b + 0;
	dec = b + (g * 256) + (r * 65536);
	return (dec);
}

void	ft_pixel(t_f **f, int color, int x, int y)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		ft_memcpy(&(*f)->data[(x * 4) + (y * (*f)->ln)], &color, sizeof(int));
}
