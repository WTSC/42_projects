/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:34:10 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:39:21 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	fractol_modif_lumi(t_rgb c, int type)
{
	if (type == 0)
	{
		c.r += (c.r + 11 > 255 || c.r == 0) ? 0 : 11;
		c.g += (c.g + 11 > 255 || c.g == 0) ? 0 : 11;
		c.b += (c.b + 11 > 255 || c.b == 0) ? 0 : 11;
	}
	else
	{
		c.r -= (c.r - 11 <= 0) ? 0 : 11;
		c.g -= (c.g - 11 <= 0) ? 0 : 11;
		c.b -= (c.b - 11 <= 0) ? 0 : 11;
	}
	return (c);
}

void	fractol_modif_color(int *color, int type)
{
	if (type == 0)
	{
		*color += 25;
		*color -= (*color >= 255) ? 255 : 0;
	}
	else
	{
		*color -= 25;
		*color = (*color <= 0) ? 255 + *color : *color + 0;
	}
}

void	init_julia_color(t_f **f)
{
	(*f)->l1.r = 0;
	(*f)->l1.g = ft_abs(128 - ((*f)->mod * 200000));
	(*f)->l1.b = ft_abs(128 - ((*f)->mod * 200000));
	(*f)->l2.r = 0;
	(*f)->l2.g = 255;
	(*f)->l2.b = 0;
}

void	init_mandel_color(t_f **f)
{
	(*f)->l1.r = 0;
	(*f)->l1.g = 0;
	(*f)->l1.b = 0;
	(*f)->l2.r = 255;
	(*f)->l2.g = 0;
	(*f)->l2.b = 0;
}

void	init_ship_color(t_f **f)
{
	(*f)->l1.r = 102;
	(*f)->l1.g = 51;
	(*f)->l1.b = 0;
	(*f)->l2.r = 255;
	(*f)->l2.g = 30;
	(*f)->l2.b = 0;
}
