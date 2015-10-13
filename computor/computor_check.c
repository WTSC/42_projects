/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 15:55:39 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 17:21:31 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		*computor_members(char *arg, char sign)
{
	int		*m;
	int		p;
	int		v;
	int		i;

	i = 0;
	m = (int *)malloc(sizeof(int) * 3);
	m = ft_memset(m, 0, sizeof(int) * 3);
	while (arg[i] != sign)
	{
		v = ft_atoi(&arg[i]);
		while (ft_isdigit(arg[i]) || arg[i] == '-')
			i++;
		p = (arg[i + 1] == '*') ? ft_atoi(&arg[i + 5]) : 0;
		if (p >= 3)
		{
			ft_putendl_fd("I can't solve this\npls\nseriously\nI can't", 2);
			exit(0);
		}
		m[p] += v;
		while (arg[i] != '+' && arg[i] != '-' && arg[i] != sign)
			i++;
		i += (arg[i] == sign) ? 0 : 2;
	}
	return (m);
}

int		*computor_sign(char *arg, int *m)
{
	int		n;
	int		p;
	int		i;

	i = 0;
	n = 0;
	if (arg[0] == '-')
		n = 1;
	while (arg[i] != '=' && arg[i] != '\0')
	{
		while (ft_isdigit(arg[i]))
			i++;
		p = (arg[i + 1] == '*') ? ft_atoi(&arg[i + 5]) : 0;
		if (n)
		{
			m[p] *= -1;
			n = 0;
		}
		while (arg[i] != '+' && arg[i] != '-' && arg[i] != '=')
			i++;
		if (arg[i] == '-')
			n = 1;
		i += (arg[i] == '=' || arg[i] == '\0') ? 0 : 2;
	}
	return (m);
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
		if (ft_strchr("0123456789+-*=^Xx ", arg[i]) == NULL)
		{
			ft_putendl_fd("Error : Invalid format", 2);
			prompt_help();
			exit(0);
		}
		i++;
	}
}

void	computor_check(char *arg)
{
	ft_checkchars(arg);
	ft_really_equa(arg);
}
