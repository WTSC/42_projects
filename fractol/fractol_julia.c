/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:14:40 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:30:17 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_frac *jul, t_f **f, int x, int y)
{
	jul->zr = 1.5 * (x - WIDTH / 2) / ((*f)->zoom * WIDTH * 0.5) + (*f)->x2;
	jul->zi = (y - HEIGHT / 2) / ((*f)->zoom * HEIGHT * 0.5) + (*f)->y2;
	jul->i = 0;
	(*f)->r = -0.7 + (*f)->mod;
	(*f)->i = 0.27015 + (*f)->mod;
}

void jul_ir(t_frac *jul, t_f *f)
{
	jul->tr = jul->zr;
	jul->ti = jul->zi;
	jul->zr = jul->tr * jul->tr - jul->ti * jul->ti + f->r;
	jul->zi = 2 * jul->tr * jul->ti + f->i;
}

void jul_put(t_frac jul, t_f *f, int x, int y)
{
	if (jul.i == f->max)
		ft_pixel(&f, ft_rgb(f->l1.r, f->l1.g, f->l1.b), x, y);
	else
		ft_pixel(&f, ft_rgb(f->l2.r, jul.i * f->l2.g / f->max,
		(jul.i % 256) + f->l2.b), x, y);
}

void draw_julia(t_f *f)
{
	t_frac	jul;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			init_julia(&jul, &f, x, y);
			while (jul.i < f->max)
			{
				jul_ir(&jul, f);
				if ((jul.zr * jul.zr + jul.zi * jul.zi) > 4)
					break ;
				jul.i = jul.i + 1;
			}
			jul_put(jul, f, x, y);
			y++;
		}
		x++;
	}
}
