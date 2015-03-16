/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 20:26:46 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:47:36 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

void erase_color(t_f *f, t_rgb c, int y)
{
	f->mon.c = 0x000000;
	ft_putmon(ft_itoa(c.r), f, 160, y);
	ft_putmon(ft_itoa(c.g), f, 190, y);
	ft_putmon(ft_itoa(c.b), f, 220, y);
}

void print_color(t_f *f, t_rgb c, int col, int y)
{
	f->mon.c = col;
	ft_putmon("( ", f, 150, y);
	f->mon.c = ft_rgb(255, 255 - c.r, 255 - c.r);
	ft_putmon(ft_itoa(c.r), f, 160, y);
	f->mon.c = col;
	ft_putmon(", ", f, 180, y);
	f->mon.c = ft_rgb(255 - c.g, 255, 255 - c.g);
	ft_putmon(ft_itoa(c.g), f, 190, y);
	f->mon.c = col;
	ft_putmon(", ", f, 210, y);
	f->mon.c = ft_rgb(255 - c.b, 255 - c.b, 255);
	ft_putmon(ft_itoa(c.b), f, 220, y);
	f->mon.c = col;
	ft_putmon(")", f, 240, y);
}

void mon_init(t_f *f)
{
	f->mon.c = 0xFFFFFF;
	ft_putmon("Current fractal :", f, 10, 20);
	ft_putmon(f->mon.det[0], f, 150, 20);
	ft_putmon("Max iterations :", f, 10, 40);
	ft_putmon(f->mon.det[1], f, 150, 40);
	ft_putmon("Zoom :", f, 10, 60);
	ft_putmon(f->mon.det[2], f, 150, 60);
	ft_putmon("Layer selected :", f, 10, 80);
	ft_putmon(f->mon.det[3], f, 150, 80);
	ft_putmon("Layer 1 color :", f, 10, 100);
	print_color(f, f->l1, 0xFFFFFF, 100);
	ft_putmon("Layer 2 color :", f, 10, 120);
	print_color(f, f->l2, 0xFFFFFF, 120);
}

void ft_putmon(char *s, t_f *f, int x, int y)
{
	mlx_string_put(f->mon.mlx, f->mon.win, x, y, f->mon.c, s);
}

void ft_update(t_f *f, int i, char *s)
{
	f->mon.c = 0x000000;
	ft_putmon(f->mon.det[i], f, 150, 20 + (i * 20));
	free(f->mon.det[i]);
	f->mon.c = 0xFFFFFF;
	ft_putmon(s, f, 150, 20 + (i * 20));
	f->mon.det[i] = ft_strdup(s);
}
