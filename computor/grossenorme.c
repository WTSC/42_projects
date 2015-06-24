/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grossenorme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 14:25:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/24 15:24:52 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void print_sol(int *m, int d)
{
	ft_putnbr(m[1]);
	ft_putstr(" - sqrt(");
	ft_putnbr(d);
	ft_putstr(")) / (2 * ");
	ft_putnbr(m[2]);
	ft_putstr(") and (");
	ft_putnbr(m[1]);
	ft_putstr(" + sqrt(");
	ft_putnbr(d);
	ft_putstr(")) / (2 * ");
	ft_putnbr(m[2]);
	ft_putstr(")");
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

void print_complex(int *m, int d)
{
	ft_putnbr(m[1]);
	ft_putstr(" - isqrt(");
	ft_putnbr(d * -1);
	ft_putstr(")) / ( 2 * ");
	ft_putnbr(m[2]);
	ft_putstr(")) and ((-");
	ft_putnbr(m[1]);
	ft_putstr(" + isqrt(");
	ft_putnbr(d * -1);
	ft_putstr(")) / ( 2 * ");
	ft_putnbr(m[2]);
	ft_putstr("))");
}
