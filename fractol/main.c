/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:02:29 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 16:51:12 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	fractol_put(int what, t_f *f, int c)
{
	if (what == 1)
	{
		ft_putendl("Usage : ./fractol <name>");
		ft_putendl("------------------------");
		ft_putendl("Available fractals :");
		ft_putendl("Mandelbrot set (mandelbrot)");
		ft_putendl("Julia set (julia)");
		ft_putendl("Burning ship (ship)");
		exit (0);
	}
	if (what == 2)
	{
		f->mon.c = c;
		ft_putmon("AVAILABLE COMMANDS :", f, 10, 400);
		ft_putmon("Arrow keys : Move the fractal", f, 10, 420);
		ft_putmon("Left / Right click : Zoom / Unzoom", f, 10, 440);
		ft_putmon("Upscroll / Downscroll : Zoom / Unzoom", f, 10, 460);
		ft_putmon("1/2/3 keys : Switch between fractals", f, 10, 480);
		ft_putmon("+/- keys : Incresase/Decrease iterations", f, 10, 500);
		ft_putmon("R : Reset", f, 10, 520);
		ft_putmon("F13/F14/F15 : More red / green / blue", f, 10, 540);
		ft_putmon("F5/F6 : Switch between layer 1 or 2", f, 10, 560);
		ft_putmon("Page up / Page down : Adjust brightness", f, 10, 580);
		ft_putmon("ESC : Quit", f, 10, 600);
	}
}

void	fractol_reset(t_f **f)
{
	(*f)->r = -0.7;
	(*f)->i = 0.27015;
	(*f)->max = 50;
	(*f)->mod = 0;
	(*f)->zoom = 1;
	(*f)->x2 = 0;
	(*f)->y2 = 0;
	(*f)->layer = 1;
	erase_color(*f, (*f)->l1, 100);
	erase_color(*f, (*f)->l2, 120);
	if (ft_strcmp("mandelbrot", (*f)->frac) == 0)
		init_mandel_color(&(*f));
	else if (ft_strcmp("julia", (*f)->frac) == 0)
		init_julia_color(&(*f));
	else if (ft_strcmp("ship", (*f)->frac) == 0)
		init_ship_color(&(*f));
	print_color(*f, (*f)->l1, 0xFFFFFF, 100);
	print_color(*f, (*f)->l2, 0xFFFFFF, 120);
	ft_update(*f, 1, ft_itoa((*f)->max));
	ft_update(*f, 3, ft_itoa((*f)->layer));
	ft_update(*f, 2, ft_ftoa((*f)->zoom));
}

void	fill_struct(t_f *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol viewer");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img, &(f->bits), &(f->ln), &(f->end));
	f->mon.mlx = mlx_init();
	f->mon.win = mlx_new_window(f->mon.mlx, 650, 650, "Fract'ol monitor");
	f->max = 50;
	f->change = 0;
	f->mod = 0;
	f->zoom = 1;
	f->x2 = 0;
	f->y2 = 0;
	f->layer = 1;
	if (ft_strcmp("mandelbrot", f->frac) == 0)
		init_mandel_color(&f);
	else if (ft_strcmp("julia", f->frac) == 0)
		init_julia_color(&f);
	else if (ft_strcmp("ship", f->frac) == 0)
		init_ship_color(&f);
	f->mon.det[0] = fractal_name(f);
	f->mon.det[1] = ft_itoa(f->max);
	f->mon.det[2] = ft_ftoa((int)f->zoom);
	f->mon.det[3] = ft_itoa(f->layer);
}

void	redirect(t_f f)
{
	mlx_expose_hook(f.win, &expose_hook, &f);
	mlx_mouse_hook(f.win, &mouse_hook, &f);
	mlx_key_hook(f.win, &key_hook, &f);
	mlx_loop_hook(f.mlx, &loop_hook, &f);
	mlx_hook(f.win, 6, 1 << 6, &point_hook, &f);
	mlx_hook(f.win, 4, 1 << 2, &mouse_hook, &f);
	mlx_loop(f.mlx);
}

int		main(int argc, char **argv)
{
	t_f		f;

	if (argc == 2)
	{
		if (fractol_check(argv[1]) != 1)
			fractol_put(1, &f, 0xFFFFFF);
		f.frac = ft_strdup(argv[1]);
		fill_struct(&f);
		redirect(f);
		sleep(95);
	}
	else
	{
		fractol_put(1, &f, 0xFFFFFF);
	}
	return (0);
}
