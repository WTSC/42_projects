/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:50:13 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:41:07 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "fractol.h"

void	ft_change(t_f **f, int type, int key)
{
	if (type == 0)
		(*f)->max += 50;
	else if (type == 1)
		(*f)->max -= 50;
	else if (type == 2)
		(*f)->layer = (key == 65474) ? 1 : 2;
	if (type == 2)
		ft_update(*f, 3, ft_itoa((*f)->layer));
	else
		ft_update(*f, 1, ft_itoa((*f)->max));
}

int		fractol_check(char *arg)
{
	if (ft_strcmp("mandelbrot", arg) == 0)
		return (1);
	else if (ft_strcmp("julia", arg) == 0)
		return (1);
	else if (ft_strcmp("ship", arg) == 0)
		return (1);
	else
		return (0);
}

void	fractol_change(int id, t_f **f)
{
	char *newname;

	free((*f)->frac);
	if (id == 1)
		(*f)->frac = ft_strdup("mandelbrot");
	if (id == 2)
		(*f)->frac = ft_strdup("julia");
	if (id == 3)
		(*f)->frac = ft_strdup("ship");
	newname = fractal_name(*f);
	ft_update(*f, 0, newname);
	fractol_reset(&(*f));
}

void	fractol_lumi(int key, t_f **f)
{
	erase_color(*f, (*f)->l1, 100);
	erase_color(*f, (*f)->l2, 120);
	if (key == 65365)
	{
		(*f)->l1 = fractol_modif_lumi((*f)->l1, 0);
		(*f)->l2 = fractol_modif_lumi((*f)->l2, 0);
	}
	else
	{
		(*f)->l1 = fractol_modif_lumi((*f)->l1, 1);
		(*f)->l2 = fractol_modif_lumi((*f)->l2, 1);
	}
	print_color(*f, (*f)->l1, 0xFFFFFF, 100);
	print_color(*f, (*f)->l2, 0xFFFFFF, 120);
}

void	fractol_color(int key, t_rgb *c, t_f *f)
{
	if (f->layer == 1)
		erase_color(f, *c, 100);
	else
		erase_color(f, *c, 120);
	if (key == 65482)
		fractol_modif_color(&c->r, 0);
	else if (key == 65483)
		fractol_modif_color(&c->g, 0);
	else if (key == 65484)
		fractol_modif_color(&c->b, 0);
	if (f->layer == 1)
		print_color(f, *c, 0xFFFFFF, 100);
	else
		print_color(f, *c, 0xFFFFFF, 120);
}
