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
#include <stdio.h>
#include "libft/libft.h"

void 			get_vertical(t_coor *pt, t_coor *grid, t_w3d *w3d)
{
	if (w3d->ray != (3 * PI) / 2 || w3d->ray != PI / 2)
	{
		if (w3d->ray > PI / 2 && w3d->ray < (3 * PI) / 2)
			pt->x = (floor(w3d->pos.x / 64) * 64) - 1;
		else
			pt->x = (floor(w3d->pos.x / 64) * 64) + 64;
		pt->y = w3d->pos.y + (w3d->pos.x - pt->x) * tan(w3d->ray);
		grid->x = floor(pt->x / 64);
		grid->y = floor(pt->y / 64);
	}
}

int		 		vertical_wall(t_w3d *w3d, t_coor *grid, t_coor *pt, double y)
{
	printf("en incrémentant %d de %f on obtient", pt->y, y);
    pt->y += (w3d->ray > 0 && w3d->ray < PI) ? -y : y;
	printf(" %d\n", pt->y);
    pt->x += (w3d->ray > PI / 2 && w3d->ray < (3 * PI) / 2) ? -64 : 64;
    grid->x = floor(pt->x/ 64);
    grid->y = floor(pt->y/ 64);
			
    if (grid->y >= w3d->height || grid->x >= w3d->width || grid->y < 0 || grid->x < 0
	|| w3d->map[grid->y][grid->x][0] == '1')
	{
		pt->y = (pt->y >= (w3d->height * 64) - 1) ? (w3d->height * 64) - 1 : pt->y + 0;
		pt->x = (pt->x >= (w3d->width * 64) - 1) ? (w3d->width * 64) - 1 : pt->x + 0;
		pt->y = (pt->y < 0) ? 0 : pt->y + 0;
		pt->x = (pt->x < 0) ? 0 : pt->x + 0;
		grid->x = floor(pt->x/ 64);
    		grid->y = floor(pt->y/ 64);
		return (1);
	}    
	else
		return (0);
}

double 	w3d_cast_vertical(t_w3d *w3d)
{
	t_coor pt;
	t_coor grid;
	double y;

	if (w3d->ray == (3 * PI) / 2 || w3d->ray == PI / 2)
		return (0);
	get_vertical(&pt, &grid, w3d);
	if (grid.y < 0 || grid.y >= w3d->height)
		return (0);
	if (w3d->map[grid.y][grid.x][0] == '1')
	{
		printf("C'EST TA FAUTE\n");
		return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
	}
	else
	{
		y = fabs(64 * tan(w3d->ray));
		if (pt.y + y < 0 || pt.y + y >= w3d->height * 64)
			return (0);
		while (42)
			if (vertical_wall(w3d, &grid, &pt, y) == 1)
				break ;
	}
		printf("NON c'est ta faute a TOI! pis les coordonnées du mur sont %d ; %d soit %d ; %d et angle %f\n", pt.x, pt.y, grid.x, grid.y, w3d->ray);
	return ((unsigned int)(sqrt(pow(w3d->pos.x - pt.x, 2) + pow(w3d->pos.y - pt.y, 2))));
}
