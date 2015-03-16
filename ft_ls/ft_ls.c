/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:10:45 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 15:46:52 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "ft_ls.h"
#include <sys/stat.h>
#include "libft/includes/libft.h"
#include <errno.h>

int		array_size(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int		ft_print_total(char *file, int mode)
{
	int						size;
	static unsigned int		total;
	struct stat				info;

	size = 0;
	if (mode == 2)
		total = 0;
	if (lstat(file, &info) >= 0 && mode == 1 && !(S_ISDIR(info.st_mode)))
	{
		if (info.st_size == 0)
			return (0);
		size = info.st_size / 512;
		if (size % 8 == 0)
			size++;
		while (size % 8 != 0)
			size++;
		if (size < 0)
			size = 8;
		total += size;
	}
	return (total);
}

int		test_dir(char *folder, int i, const char **args)
{
	DIR				*dir;
	struct stat		info;

	if (i == 0 && ft_strchr(ft_get_flags(args), 'R') != NULL)
		return (3);
	dir = opendir(folder);
	if (!dir)
	{
		if (lstat(folder, &info) == 0 && (!S_ISDIR(info.st_mode)))
			return (2);
		else
		{
			if (i == -1)
				ft_perror(errno, folder, 1);
			if (errno == EACCES)
				return (-1);
			else
				return (12);
		}
	}
	(void)closedir(dir);
	return (1);
}

char	**list_dir(const char **args, int nb, char *folder)
{
	DIR				*dir;
	struct dirent	*obj;
	char			**array;
	int				i;

	array = ft_arrnew(folder);
	if (args != NULL && ft_check_flag(args, nb) == 1)
		dir = opendir(folder);
	else
		dir = opendir(".");
	if (dir && (i = 0) == 0)
	{
		while ((obj = readdir(dir)) != NULL)
		{
			array[i++] = ft_strdup(folder);
			array[i - 1] = ft_mallcat(array[i - 1], "/");
			array[i - 1] = ft_mallcat(array[i - 1], obj->d_name);
		}
		closedir(dir);
	}
	array[i] = NULL;
	return (array);
}
