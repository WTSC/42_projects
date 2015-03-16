/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 02:35:20 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 16:15:05 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

int		ft_subchk(char *file, char **subfolders, char *path, const char **args)
{
	struct stat	info;

	if (ft_strchr(ft_get_flags(args), 'a') == NULL
		&& file[0] == '.')
		return (0);
	if ((ft_strcmp(file, ".") != 0)
		&& (ft_strcmp(file, "..") != 0))
	{
		if (stat(path, &info) >= 0)
		{
			if (S_ISDIR(info.st_mode))
			{
				*subfolders = ft_strjoin(*subfolders, path);
				*subfolders = ft_strjoin(*subfolders, " ");
				return (1);
			}
		}
	}
	return (0);
}

char	*sub_search(char *folder, char *subfolders, const char **args)
{
	char	**array;
	int		i;

	array = list_dir(args, array_size((char **)args), folder);
	if (ft_strchr(ft_get_flags(args), 'r') != NULL)
		i = array_size(array) - 1;
	else
		i = 0;
	array = ft_qsort(array, array_size(array));
	while (array[i] != NULL && i != -1)
	{
		if (ft_subchk(ft_basename(array[i]), &subfolders, array[i], args))
			subfolders = sub_search(array[i], subfolders, args);
		if (ft_strchr(ft_get_flags(args), 'r') != NULL)
			i--;
		else
			i++;
	}
	return (subfolders);
}

char	**ft_recursive(char **folders, const char **args)
{
	char	*array;
	char	**split;
	int		i;

	i = 0;
	array = NULL;
	while (folders[i])
	{
		array = ft_strjoin(array, folders[i]);
		array = ft_strjoin(array, " ");
		array = sub_search(folders[i], array, args);
		i++;
	}
	split = ft_strsplit(array, ' ');
	return (split);
}
