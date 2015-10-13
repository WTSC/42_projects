/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:22:39 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 16:40:32 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	prompt_help(void)
{
	ft_putendl_fd("HOW TO USE COMPUTOR :", 2);
	ft_putendl_fd("Syntax : ./computor \"equation\"", 2);
	ft_putendl_fd("Your equation MUST be valid and MUST contain a '='.", 2);
	ft_putendl_fd("e.g : ./computor \"25 + 45x + 50x^2 = 0\"", 2);
	ft_putendl_fd("This program doesen't support 3+ degrees equations", 2);
	ft_putendl_fd("WARNING : BRACKETS NOT ALLOWED", 2);
}

int		main(int argc, char **argv)
{
	int		*left;
	int		*right;
	int		i;

	if (argc == 2)
	{
		computor_check(argv[1]);
		left = computor_members(argv[1], '=');
		i = id_chr(argv[1], '=') + 2;
		right = computor_members(&argv[1][i], '\0');
		left = computor_sign(argv[1], left);
		right = computor_sign(&argv[1][i], right);
		printf("left = %d right = %d\n", left[0], right[0]);
		left[0] -= right[0];
		left[1] -= right[1];
		left[2] -= right[2];
		computor_solve(left);
		free(left);
		free(right);
	}
	else
	{
		prompt_help();
	}
	return (0);
}
