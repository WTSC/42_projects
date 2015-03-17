/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:01:27 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:29:09 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "w3d.h"

double to_rad(double deg)
{
	return (deg * (PI / 180));
}

double to_deg(double rad)
{
	return (rad * (180 / PI));
}

unsigned int w3d_shortest(double h_wall, double v_wall, t_w3d *w3d)
{
	if ((v_wall < h_wall && v_wall != 0) || h_wall == 0)
	{
		if (w3d->ray > PI / 2 && w3d->ray < (3 * PI) / 2)
			w3d->color = 0xFF0000;
		else
			w3d->color = 0x00FF00;
		return (v_wall);
	}
	else
	{
		if (w3d->ray > PI)
			w3d->color = 0x0000FF;
		else
			w3d->color = 0xFFFF00;
		return (h_wall);
	}
	if (v_wall < h_wall)
		return ((v_wall == 0) ? h_wall : v_wall);
	else
		return ((h_wall == 0) ? v_wall : h_wall);
}

#include <stdio.h>
unsigned int w3d_calc(double h, double v, short type, t_w3d **w3d, int n)
{
	double s;
	double s2;
	
	s = w3d_shortest(h, v, *w3d);
	s2 = (*w3d)->pos.a - (PI / 6) + (WIDTH - 1 - n) * 0.99 * (PI / 3 ) / WIDTH;
	s = s * cos(s2 - (*w3d)->pos.a);

	(*w3d)->slice = (64 / s) * 277;
	return (s);
}
