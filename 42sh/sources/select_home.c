/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:25:40 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 20:09:46 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int sh1_isdir(char *path)
{
	struct stat	s;
	int			err;

	err = stat(path, &s);
	if (err == -1)
	{
		perror("error");
		ft_printf("\nPlease type the path of the directory which will be used as home directory : ");
		return (0);
	}
	else
	{
		if (S_ISDIR(s.st_mode))
			return (1);
		else 
		{
			ft_printf("error: %s is not a directory.\n");
			ft_printf("Please type the path of the directory which will be used as home directory : ");
			return (0);
		}
	}
}

char *select_home(char *pwd)
{
	char *line;

	ft_printf("Actually, the current home directory is set to : %s.\n Do you want to change it ? (y/n) ", pwd);
	while (42)
		if (get_next_line(0, &line) > 0)
		{
			if (ft_strcmp(ft_strtrim(line), "y") == 0)
				break ;
			else if (ft_strcmp(ft_strtrim(line), "n") == 0)
				return (pwd);
			free(line);
			line = NULL;
		}
	ft_printf("Please type the path of the directory which will be used as home directory : ");
	while (42)
		if (get_next_line(0, &line) > 0)
		{
			if (sh1_isdir(line) == 1)
				return (line);
			free(line);
			line = NULL;
		}
}
