/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:18:05 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 19:32:42 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "w3d.h"
#include <math.h>
#include "libft/libft.h"

void ft_pixel(t_w3d **w3d, int color, int x, int y)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		ft_memcpy(&(*w3d)->data[(x * 4) + (y * (*w3d)->ln)], &color, sizeof(int));
}

void w3d_draw_slice(t_w3d *w3d, short int n)
{
	short int y;
	short int y2;

	y = 100;
	y = 100 - (w3d->slice / 2);
	y2 = y;
	while (y2 != y + w3d->slice)
	{
		ft_pixel(&w3d, 0xFFFFFF, n, y2);
		y2++;
	}
}
