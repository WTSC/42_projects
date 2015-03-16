/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 22:53:53 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/24 23:57:51 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include <stdlib.h>

void ft_move(t_f **f, int keycode)
{
	if ((*f)->zoom <= 1.0)
	{
		if (keycode == 65362 || keycode == 65364)
			(*f)->y2 += (keycode == 65362) ? 0.01 : -0.01;
		else if (keycode == 65361 || keycode == 65363)
			(*f)->x2 += (keycode == 65361) ? 0.01 : -0.01;
	}
	else
	{
		if (keycode == 65362 || keycode == 65364)
			(*f)->y2 += (keycode == 65362) ? 0.01 : -0.01;
		else if (keycode == 65361 || keycode == 65363)
			(*f)->x2 += (keycode == 65361) ? 0.01 : -0.01;
	}
}

char *fractal_name(t_f *f)
{
	char *s;

	if (ft_strcmp("mandelbrot", f->frac) == 0)
		s = ft_strdup("Mandelbrot set");
	else if (ft_strcmp("julia", f->frac) == 0)
		s = ft_strdup("Julia set");
	else if (ft_strcmp("ship", f->frac) == 0)
		s = ft_strdup("Burning Ship");
	else
		s = ft_strdup("Unknown");
	return (s);
}

char *ft_ftoa(double i)
{
	int		left;
	int		right;
	char	*n;
	char	*l;
	char	*r;

	left = (int)i;
	right = (i * 100) - left * 100;
	n = malloc(sizeof(char) * 50);
	l = ft_itoa(left);
	ft_strcpy(n, l);
	ft_strcat(n, ".");
	r = ft_itoa(right);
	ft_strcat(n, r);
	free(r);
	free(l);
	return (n);
}
