/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:04:55 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:44:34 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <mlx.h>

int loop_hook(t_f *f)
{
	if (f->change == 1)
	{
		expose_hook(f);
		f->change = 0;
	}
	return (0);
}

int point_hook(int x, int y, t_f *f)
{
	if (ft_strcmp("julia", f->frac) == 0)
	{
		if (y != f->y)
		{
			f->mod += (y > f->y) ? 0.01 : -0.01;
			f->y = y;
		}
		if (x != f->x)
		{
			f->mod += (x > f->x) ? 0.005 : -0.005;
			f->x = x;
		}
		f->change = 1;
	}
	return (0);
}

int mouse_hook(int b, int x, int y, t_f *f)
{
	t_pt	mouse;
	double	m;

	m = (x < (WIDTH / 2)) ? -0.5 : 1.5;
	if (b == 5 || b == 4)
		b = (b == 5) ? 3 : 1;
	if (b == 1 || b == 3)
	{
		f->zoom *= (b == 3) ? 0.9 : 1.1;
		mouse.x = ((double)x - (WIDTH / 1)) / (WIDTH / 2) + m;
		mouse.y = ((double)y - (HEIGHT / 2.0)) / (HEIGHT / 2);
		f->x2 += mouse.x / f->zoom / 10.0;
		f->y2 += mouse.y / f->zoom / 10.0;
		ft_update(f, 2, ft_ftoa(f->zoom));
		f->change = 1;
	}
	return (0);
}

int key_hook(int keycode, t_f *f)
{
	if (keycode == 65307)
		exit (0);
	else if (keycode == 65451)
		ft_change(&f, 0, keycode);
	else if (keycode == 65453 && f->max > 50)
		ft_change(&f, 1, keycode);
	else if (keycode == 114)
		fractol_reset(&f);
	else if (keycode == 65362 || keycode == 65364)
		ft_move(&f, keycode);
	else if (keycode == 65361 || keycode == 65363)
		ft_move(&f, keycode);
	else if ((keycode >= 49 && keycode <= 51)
		|| (keycode >= 65457 && keycode <= 65459))
		fractol_change((keycode > 51) ? keycode - 65456 : keycode - 48, &f);
	else if (keycode >= 65482 && keycode <= 65484)
		fractol_color(keycode, (f->layer == 1) ? &f->l1 : &f->l2, f);
	else if (keycode == 65474 || keycode == 65475)
		ft_change(&f, 2, keycode);
	else if (keycode == 65365 || keycode == 65366)
		fractol_lumi(keycode, &f);
	f->change = 1;
	return (0);
}

int expose_hook(t_f *f)
{
	static int run;

	if (ft_strcmp("mandelbrot", f->frac) == 0)
		draw_mandel(f);
	else if (ft_strcmp("julia", f->frac) == 0)
		draw_julia(f);
	else if (ft_strcmp("ship", f->frac) == 0)
		draw_ship(f);
	else
		exit (0);
	if (run == 0)
	{
		fractol_put(2, f, 0xFFFFFF);
		mon_init(f);
		run = 1;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
