/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 19:56:02 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:29:51 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

void fill_struct(t_w3d *w3d)
{
	w3d->map = ft_nbrsplit("data/map", &w3d);
	w3d_get_start(&w3d);
	w3d_check(w3d->map);
	w3d->mlx = mlx_init();
    w3d->win = mlx_new_window(w3d->mlx, WIDTH, HEIGHT, "Wolf3D");
    w3d->img = mlx_new_image(w3d->mlx, WIDTH, HEIGHT);
    w3d->data = mlx_get_data_addr(w3d->img, &(w3d->bits),
	&(w3d->ln), &(w3d->end));
}

void w3d_raycaster(t_w3d *w3d, short int type)
{
	unsigned int 			v_wall;
	unsigned int			h_wall;
	short int				n;
	double					b;

	n = 160;
	b = (type == 0) ? w3d->pos.a + to_rad(30) : w3d->pos.a - to_rad(30);
	w3d->ray = w3d->pos.a;
	printf("%f <= %f nig\n", w3d->ray, b);
	while ((w3d->ray <= b && type == 0) || (w3d->ray >= b && type == 1))
	{
		h_wall = w3d_cast_horizontal(w3d);
		if (w3d->ray >= 1.58824962)
			v_wall = w3d_cast_vertical(w3d);
		w3d_calc(h_wall, v_wall, type, &w3d);
		w3d_draw_slice(w3d, n);
		w3d->ray += (type == 0) ? PAD : -PAD;
		n += (type == 0) ? -1 : 1;
	}
}

int main(void)
{
	t_w3d	w3d;

	fill_struct(&w3d);
	w3d_raycaster(&w3d, 0);
	w3d_raycaster(&w3d, 1);
	mlx_put_image_to_window(w3d.mlx, w3d.win, w3d.img, 0, 0);
	sleep(99);
	free(w3d.map);
	return (0);
}
