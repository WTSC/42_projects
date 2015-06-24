/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:51:55 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/24 15:54:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void		ft_simplify(int *m)
{
	ft_putnbr(m[0]);
	ft_putstr(" * X^0");
	write(1, (m[1] < 0) ? " - " : " + ", 3);
	ft_putnbr((m[1] < 0) ? m[1] * -1 : m[1]);
	ft_putstr(" * X^1");
	write(1, (m[2] < 0) ? " - " : " + ", 3);
	ft_putnbr((m[2] < 0) ? m[2] * -1 : m[2]);
	ft_putstr(" * X^2 = 0\n");
}

static int		ft_discriminant(int *m)
{
	int b;
	int d;

	b = m[1] * m[1];
	ft_putnbr(m[1]);
	ft_putstr("^2 - 4 * ");
	ft_putnbr(m[2]);
	ft_putstr(" * ");
	ft_putnbr(m[0]);
	ft_putstr(" = ");
	d = b - (4 * m[2] * m[0]);
	ft_putnbr(d);
	return (d);
}

static void		ft_solution(int d, int *m)
{
	m[1] *= -1;
	if (d > 0)
	{
		ft_putstr("\x1b[34mThere are two solutions :\x1b[0m (");
		print_sol(m, d);
		write(1, "\n", 1);
	}
	else if (d < 0)
	{
		ft_putstr("\x1b[34mThere are two complex solutions :\x1b[0m ((-");
		print_complex(m, d);
		write(1, "\n", 1);
	}
	else
	{
		ft_putstr("\x1b[34mThe solution is :\x1b[0m ");
		ft_putnbr(m[1] * -1);
		ft_putstr(" / (2 * ");
		ft_putnbr(m[2]);
		ft_putstr(")");
		write(1, "\n", 1);
	}
}

void			computor_solve(int *m)
{
	int d;

	ft_putstr("\x1b[35mSimplified equation : \x1b[0m");
	ft_simplify(m);
	ft_putstr("\x1b[36mCalculating delta : \x1b[0m");
	d = ft_discriminant(m);
	if (d > 0)
	{
		ft_putstr("\x1b[33m(DELTA IS POSITIVE !)\x1b[0m\n");
		ft_solution(d, m);
	}
	else if (d < 0)
	{
		ft_putstr("\x1b[31m(DELTA IS NEGATIVE !)\x1b[0m\n");
		ft_solution(d, m);
	}
	else
	{
		ft_putstr("\x1b[32m(DELTA IS ZERO !)\x1b[0m\n");
		ft_solution(d, m);
	}
}
