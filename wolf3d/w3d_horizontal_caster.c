/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_horizontal_caster.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 19:55:29 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:28:07 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "w3d.h"
#include "libft/libft.h"
#include <limits.h>

void 				get_horizontal(t_coor *pt, t_coor *grid, t_w3d *w3d)
{
	if (w3d->ray != PI && w3d->ray != 0)
	{
		if (w3d->ray < PI)
			pt->y = (floor(w3d->pos.y / 64) * 64) - 1;
		else
			pt->y = (floor(w3d->pos.y / 64) * 64) + 64;
		pt->x = w3d->pos.x + floor((w3d->pos.y - pt->y) / tan(w3d->ray));
		grid->x = floor(pt->x / 64);
		grid->y = floor(pt->y / 64);
	}
}

int					 horizontal_wall(t_w3d *w3d, t_coor *grid, t_coor *pt, double x)
{
	pt->x += x;
	pt->y += (w3d->ray <= PI) ? -64 : 64;
	grid->x = floor(pt->x/ 64);
	grid->y = floor(pt->y/ 64);
	if (w3d->map[grid->y][grid->x][0] == '1' || grid->y < 0 || grid->x < 0
		|| grid->y >= w3d->height || grid->x >= w3d->width)
		return (1);
	else
		return (0);
}


#include <stdio.h>
double		w3d_cast_horizontal(t_w3d *w3d)
{
	t_coor pt;
	t_coor grid;
	double x;

	if (w3d->ray == PI && w3d->ray == 0)
		return (0);
	get_horizontal(&pt, &grid, w3d);
	if (grid.x < 0 || grid.x >= w3d->width)
		return (0);
	if (w3d->map[grid.y][grid.x][0] == '1')
	{
		return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
	}	
	else
	{
		x = floor(64 / tan(w3d->ray));
		if (pt.x + x < 0 || pt.x + x >= WIDTH)
			return (0);
		while (42)
			if (horizontal_wall(w3d, &grid, &pt, x) == 1)
				break ;
	}
		return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
}
