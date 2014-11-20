/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:44:56 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 08:17:17 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>



int ft_arrstr(char *file, char **copy)
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

char *get_newer(char **copy, char **array)
{
	int i;
	time_t timm;
	time_t newer;
	char *file;
	struct stat info;

	i = 0;
	newer = time(NULL);
	file = ft_strdup(array[i]);
	while (array[i])
	{
		if (stat(array[i], &info) != -1)
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

void ft_sort_by_time(char **array, const char **args, int size, int nb)
{
	int i;
	char **copy;
    	char *filelist;
	int namesize;

    	filelist = ft_strnew(1);
    	if (!filelist)
		ft_perror(MEMORY, "");
	i = 0;
	copy = ft_arrnew(args, nb);
	while (i < size && copy[i])
	{
		copy[i] = ft_strnew(256);
		copy[i] = ft_strcpy(copy[i], get_newer(copy, array));
		i++;
	}
	i = 0;
	copy = ft_arrev(copy, size);
	while (i < size)
	{		
		namesize = ft_strlen(ft_get_folder(args));
		copy[i] = ft_strsub(copy[i], namesize + 1, ft_strlen(copy[i]) - namesize - 1);
		ls_process(args, copy[i++], &filelist, nb);
	}
	ft_print(args, filelist);
}

char **ft_arrnew(const char **args, int nb)
{
	char			**array;
    DIR             *dir;
    struct dirent   *obj;
    int i;

	i = 0;
    if (args != NULL && ft_check_flag(args, nb) == 1)
        dir = opendir(ft_get_folder(args));
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
		ft_perror(MEMORY, "");
	array[i] = NULL;
	return (array);
}

void ft_time_ls(const char **args, int nb)
{
	DIR             *dir;
    struct dirent   *obj;
    char **array;
	int i;

	array = ft_arrnew(args, nb);
	if (ft_check_flag(args, nb) == 1)
        dir = opendir(ft_get_folder(args));
    else
        dir = opendir(".");
    if (dir && (i = 0) == 0)
    {
		while ((obj = readdir(dir)) != NULL)
		{
			if (ft_check_flag(args, nb) == 1)
			{
				array[i] = ft_strdup(ft_get_folder(args));
				ft_mallcat(&array[i], "/");
				ft_mallcat(&array[i], obj->d_name);
				i++;
			}
			else
				array[i++] = ft_strdup(obj->d_name);
		}
			closedir(dir);
	}
	ft_sort_by_time(array, args, i, nb);
}
