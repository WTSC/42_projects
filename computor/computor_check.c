/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 15:55:39 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/12 20:18:42 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		computor_members(char *arg)
{
	int		i;
	int 	j;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '^')
			p = 1;
		if ((arg[i] == '+' || arg[i] == '-') && p == 1)
		{
			j++;
			p = 0;
		}
		i++;
	}
	return (j);
}

void	ft_identical(char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_strchr("+-*/^.", arg[i]) != NULL
			&& ft_strchr("+-*/^.", arg[i + 1]) != NULL)
		{
			ft_putendl_fd("Error : Two consecutive signs", 2);
			prompt_help();
			exit(0);
		}
		i++;
	}
}

void	ft_really_equa(char *arg)
{
	if (ft_chrcount(arg, '=') != 1)
	{
		printf("chrcount of is %d\n", ft_chrcount(arg, '='));
		ft_putendl_fd("Error : There should  ONE '=' sign in the equation", 2);
		prompt_help();
		exit(0);
	}
}

void	ft_checkchars(char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_strchr("0123456789+-*/=^Xx. ", arg[i]) == NULL)
		{
			ft_putendl_fd("Error : Invalid format", 2);
			prompt_help();
			exit(0);
		}
		i++;
	}
}

void computor_check(char *arg)
{
	ft_checkchars(arg);
	ft_really_equa(arg);
	ft_identical(arg);
}
