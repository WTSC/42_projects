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

#include <stdio.h>
void w3d_draw_slice(t_w3d *w3d, short int n, int d)
{
	short int y;
	(void)d;
	y = (HEIGHT / 2) - 1 - (w3d->slice / 2);
	while (y != HEIGHT / 2 + w3d->slice / 2 - 1)
	{
		ft_pixel(&w3d, w3d->color, n, y);
		y++;
	}
}

void w3d_draw_ceil(t_w3d *w3d, short int n)
{
	short int y;

	y = (HEIGHT / 2) - 1 - (w3d->slice / 2);
	while (y > 0)
	{
		ft_pixel(&w3d, 0x000000, n, y);
		y--;
	}
}

void w3d_draw_floor(t_w3d *w3d, short int n)
{
	short int y;

	y = HEIGHT / 2 + w3d->slice / 2 - 1;
	while (y < HEIGHT - 1)
	{
		ft_pixel(&w3d, 0xCCCCCC, n, y);
		y++;
	}
}
