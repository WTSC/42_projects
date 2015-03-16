/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:01:27 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:29:09 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.141592654
#include <math.h>
#include "w3d.h"

double to_rad(double deg)
{
	return (deg * (PI / 180));
}

double to_deg(double rad)
{
	return (rad * (180 / PI));
}

unsigned int w3d_shortest(unsigned int h_wall, unsigned int v_wall)
{
	if (v_wall < h_wall)
		return (v_wall);
	else
		return (h_wall);
}

#include <stdio.h>
unsigned int w3d_calc(unsigned h, unsigned v, short type, t_w3d **w3d)
{
	unsigned int s;
	
	printf("well... %d, %d\n", h, v);
	s = w3d_shortest(h, v);
	s = s * cos((type == 0) ? 30 : -30);
	printf("%d\n", s);
	(*w3d)->slice = ceil((64 / s) * 277);
	return (s);
}
