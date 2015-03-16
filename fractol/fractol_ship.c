/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 14:59:49 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 16:25:18 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	init_ship(t_frac *ship, t_f **f, int x, int y)
{
	ship->tr = 0;
	ship->ti = 0;
	ship->i = 0;
	(*f)->r = 2 * (x - WIDTH / 2) / ((*f)->zoom * WIDTH * 0.25) + (*f)->x2;
	(*f)->i = (y - HEIGHT / 2) / ((*f)->zoom * HEIGHT * 0.25) + (*f)->y2;
}

void	init_ir(t_frac *ship, t_f *f)
{
	ship->zr = ship->tr * ship->tr - ship->ti * ship->ti + f->r;
	ship->zi = 2 * ft_abs(ship->tr) * ft_abs(ship->ti) + f->i;
	ship->tr = ship->zr;
	ship->ti = ship->zi;
}

void	ship_put(t_frac ship, t_f *f, int x, int y)
{
	if (ship.i == f->max)
		ft_pixel(&f, ft_rgb(f->l1.r, f->l1.g, f->l1.b), x, y);
	else
		ft_pixel(&f, ft_rgb(ship.i * f->l2.r / f->max,
		ship.i * f->l2.g / f->max, f->l2.b), x, y);
}

void	draw_ship(t_f *f)
{
	t_frac	ship;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			init_ship(&ship, &f, x, y);
			while (ship.i < f->max)
			{
				init_ir(&ship, f);
				if ((ship.zr * ship.zr + ship.zi * ship.zi) > 10)
					break ;
				ship.i = ship.i + 1;
			}
			ship_put(ship, f, x, y);
			y++;
		}
		x++;
	}
}
