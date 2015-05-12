/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 15:54:53 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/12 20:47:49 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void prompt_help(void)
{
	ft_putendl_fd("HOW TO USE COMPUTOR :", 2);
	ft_putendl_fd("Syntax : ./computor \"equation\"", 2);
    ft_putendl_fd("Your equation MUST be a true one and so MUST contain a '='.", 2);
	ft_putendl_fd("e.g : ./computor \"25 + 45x + 50x^2 = 0\"", 2);
    ft_putendl_fd("This program doesen't support 3+ degrees equations", 2);
    ft_putendl_fd("WARNING : BRACKETS NOT ALLOWED", 2);
}

int main(int argc, char **argv)
{
	char *arg;

	if (argc > 1)
	{
		computor_check(argv[1]);
		arg = computor_nospaces(argv[1]);
		arg = computor_rewrite(arg);
		computor_solve(arg)
		ft_putendl(arg);
	}
	else
	{
		prompt_help();
	}
	return (0);
}
