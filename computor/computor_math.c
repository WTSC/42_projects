/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:51:55 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 17:20:45 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void		first_degree(int *m)
{
	double nb;

	if (m[0] == m[1])
		ft_putstr("\n\x1b[32mSolved.\x1b[0m\n");
	else if (m[1] == 0)
		ft_putstr("\n\x1b[31mUnsolvable.\x1b[0m\n");
	else
	{
		ft_putstr("\n\x1b[34mThe solution is \x1b[32m");
		nb = m[0] / (m[1] * whichsign(m[0], m[1]));
		ft_putstr(ft_ftoa(nb));
		ft_putstr("\x1b[0m\n");
	}
	exit(0);
}

static void		ft_simplify(int *m)
{
	if (m[0] != 0)
	{
		ft_putnbr(m[0]);
		ft_putstr(" * X^0");
		if (m[1] != 0)
			write(1, (m[1] < 0) ? " - " : " + ", 3);
	}
	if (m[1] != 0)
	{
		ft_putnbr((m[1] < 0) ? m[1] * -1 : m[1]);
		ft_putstr(" * X^1");
		if (m[2] != 0)
			write(1, (m[2] < 0) ? " - " : " + ", 3);
	}
	if (m[2] != 0)
	{
		ft_putnbr((m[2] < 0) ? m[2] * -1 : m[2]);
		ft_putstr(" * X^2 = 0");
	}
	if (m[0] == 0 && m[1] == 0 && m[2] == 0)
		ft_putchar('0');
	ft_putstr(" = 0\n");
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
		ft_putstr(ft_ftoa((m[1]) / (2 * m[2])));
		write(1, "\n", 1);
	}
}

void			computor_solve(int *m)
{
	int d;

	ft_putstr("\x1b[35mSimplified equation : \x1b[0m");
	ft_simplify(m);
	if (m[2] == 0)
		first_degree(m);
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
