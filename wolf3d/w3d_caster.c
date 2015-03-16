/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:25:25 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:30:39 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "w3d.h"
#include "libft/libft.h"

void 			get_vertical(t_coor *pt, t_coor *grid, t_w3d *w3d)
{
	if (floor(to_deg(w3d->ray)) != 270 || floor(to_deg(w3d->ray)) != 90)
	{
		if (to_deg(w3d->ray) > 90 && to_deg(w3d->ray) < 270)
			pt->x = (floor(w3d->pos.x / 64) * 64) - 1;
		else
			pt->x = (floor(w3d->pos.x / 64) * 64) + 64;
		printf("%d\n", pt->x);
		pt->y = w3d->pos.y + (w3d->pos.x - pt->x) * tan(w3d->ray);
		grid->x = floor(pt->x / 64);
		grid->y = floor(pt->y / 64);
	}
}

int		 		vertical_wall(t_w3d *w3d, t_coor *grid, t_coor *pt, double y)
{
    pt->y += y;
    pt->x += (to_deg(w3d->ray) > 90 && to_deg(w3d->ray) < 270) ? -64 : 64;
    grid->x = floor(pt->x/ 64);
    grid->y = floor(pt->y/ 64);
    if (w3d->map[grid->y][grid->x][0] == '1' || grid->y < 0 || grid->x < 0
		|| grid->y >= w3d->height || grid->x >= w3d->width)
		return (1);
    else
		return (0);
}

unsigned int 	w3d_cast_vertical(t_w3d *w3d)
{
	t_coor pt;
	t_coor grid;
	double y;

	if (floor(to_deg(w3d->ray)) == 270 || floor(to_deg(w3d->ray)) == 90)
		return (0);
	printf("get vertical\n");
	get_vertical(&pt, &grid, w3d);
	printf("passed : %d %d\n", grid.x, grid.y);
	if (w3d->map[grid.y][grid.x][0] == '1')
	{
		printf("TA FAUTE point foint at coordinates (%d %d)\n", grid.x, grid.y);
		return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
	}
	else
	{
		printf("get vertical2\n");
		y = floor(64 * tan(w3d->ray));
		if (pt.y + y < 0 || pt.y + y >= HEIGHT)
			return (0);
		while (42)
			if (vertical_wall(w3d, &grid, &pt, y) == 1)
				break ;
	}
	printf("vertical point foint at coordinates (%d %d)\n", grid.x, grid.y);
	return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
}
