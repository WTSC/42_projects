/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:07:42 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:29:09 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void init_mandel(t_frac *man, t_f **f, int x, int y)
{
	man->cr = 1.5 * (x - WIDTH / 2) / (0.5 * (*f)->zoom * WIDTH) + (*f)->x2;
	man->ci = (y - HEIGHT / 2) / (0.5 * (*f)->zoom * HEIGHT) + (*f)->y2;
	man->zr = 0;
	man->zi = 0;
	man->i = 0;
}

void mandel_ir(t_frac *man)
{
	man->tr = man->zr;
	man->ti = man->zi;
	man->zr = man->tr * man->tr - man->ti * man->ti + man->cr;
	man->zi = 2 * man->tr * man->ti + man->ci;
}

void mandel_put(t_frac man, t_f *f, int x, int y)
{
	if (man.i == f->max)
		ft_pixel(&f, ft_rgb(f->l1.r, f->l1.g, f->l1.b), x, y);
	else
		ft_pixel(&f, ft_rgb(man.i * f->l2.r / f->max,
							f->l2.g, f->l2.b), x, y);
}

void draw_mandel(t_f *f)
{
	t_frac	man;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			init_mandel(&man, &f, x, y);
			while (man.i < f->max)
			{
				mandel_ir(&man);
				if ((man.zr * man.zr + man.zi * man.zi) > 4)
					break ;
				man.i = man.i + 1;
			}
			mandel_put(man, f, x, y);
			y++;
		}
		x++;
	}
}
