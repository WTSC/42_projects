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
	w3d->change == 0;
    w3d->win = mlx_new_window(w3d->mlx, WIDTH, HEIGHT, "Wolf3D");
    w3d->img = mlx_new_image(w3d->mlx, WIDTH, HEIGHT);
    w3d->data = mlx_get_data_addr(w3d->img, &(w3d->bits),
	&(w3d->ln), &(w3d->end));
}

void w3d_raycaster(t_w3d **w3d, short int type)
{
	double 			v_wall;
	double			h_wall;
	static int			n;
	int			b;

	if (type == 0)
	{
		(*w3d)->ray = (*w3d)->pos.a + (160 * PAD);
		if ((*w3d)->ray > 2 * PI)
			(*w3d)->ray -= 2 * PI;
	}
	b = (*w3d)->pos.a - PI / 6;
	if (b < 0)
		b = (2 * PI) + b;
	while (((*w3d)->ray >= (*w3d)->pos.a && type == 0) || ((*w3d)->ray >= b && type == 1))
	{	
		//printf("type = %d ray = %f pos = %f pos - PI / 6 = %f\n", type, (*w3d)->ray, (*w3d)->pos.a, (*w3d)->pos.a - PI / 6);
		if ((*w3d)->ray	< 0)
		{
			(*w3d)->ray = (2 * PI) + (*w3d)->ray;
			if ((*w3d)->ray	<= b)
				break ;
		}		
		h_wall = w3d_cast_horizontal(*w3d);
		v_wall = w3d_cast_vertical(*w3d);	
		w3d_calc(h_wall, v_wall, type, &(*w3d), n);
		w3d_draw_ceil(*w3d, n);
		w3d_draw_slice(*w3d, n);
		w3d_draw_floor(*w3d, n);
		(*w3d)->ray -= PAD;
		n++;
		if (n == 321)
		{
			n = 0;
			break ;
		}
	}
	printf("type %d n %d\n", type, n); 
}

void w3d_init(t_w3d w3d)
{
	mlx_expose_hook(w3d.win, &expose_hook, &w3d);
	mlx_key_hook(w3d.win, &key_hook, &w3d);
	mlx_loop_hook(w3d.mlx, &loop_hook, &w3d);
	mlx_loop(w3d.mlx);
}

int main(void)
{
	t_w3d	w3d;

	fill_struct(&w3d);
	w3d_init(w3d);
	return (0);
}
