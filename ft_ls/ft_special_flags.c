/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:44:56 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/04 21:46:53 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <time.h>
#include <sys/stat.h>

int		ft_arrstr(char *file, char **copy)
{
	int i;

	i = 0;
	while (copy[i] != NULL && copy[i][0] != '\0')
	{
		if (ft_strcmp(file, copy[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*get_newer(char **copy, char **array)
{
	int				i;
	time_t			timm;
	time_t			newer;
	char			*file;
	struct stat		info;

	i = 0;
	newer = 99999999999;
	file = ft_strdup(array[i]);
	while (array[i])
	{
		if (lstat(array[i], &info) != -1)
		{
			timm = info.st_mtime;
			if (timm <= newer && ft_arrstr(array[i], copy) != 1)
			{
				newer = timm;
				file = NULL;
				free(file);
				file = ft_strdup(array[i]);
			}
		}
		i++;
	}
	return (file);
}

char	**ft_sort_by_time(char **array, int size, char *folder)
{
	int		i;
	char	**copy;

	i = 0;
	copy = ft_arrnew(folder);
	while (i < size)
	{
		copy[i] = (char *)malloc(sizeof(char) * 256);
		copy[i] = ft_strcpy(copy[i], get_newer(copy, array));
		i++;
	}
	copy = ft_arrev(copy, size);
	return (copy);
}

char	**ft_arrnew(char *folder)
{
	char			**array;
	DIR				*dir;
	struct dirent	*obj;
	int				i;

	i = 0;
	if (ft_strcmp(".", folder) != 0)
		dir = opendir(folder);
	else
		dir = opendir(".");
	if (dir)
	{
		while ((obj = readdir(dir)) != NULL)
			i++;
		closedir(dir);
	}
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		ft_perror(MEMORY, "", 0);
	array[i] = NULL;
	return (array);
}
