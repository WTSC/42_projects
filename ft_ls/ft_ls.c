/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:10:45 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 06:29:07 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "ft_ls.h"
#include <sys/stat.h>
#include "libft/includes/libft.h"

int ft_max_len(const char **args, int nb)
{
    DIR             *dir_;
    struct dirent   *obj_;
	struct stat		info;
	int				size;
	int				len;
	int				mlen;

	if (args != NULL && ft_check_flag(args, nb) == 1)
        dir_ = opendir(ft_get_folder(args));
    else
        dir_ = opendir(".");
    if (dir_)
    {
        while ((obj_ = readdir(dir_)) != NULL && stat(obj_->d_name, &info) != -1)
		{
			len = 0;
			size = info.st_size;
			while ((size = size / 10))
				len++;
			if (len > mlen)
				mlen = len;
		}
		closedir(dir_);
    }
	return (mlen + 1);
}

int ft_print_total(char *file, int mode)
{
	int size;
	static unsigned int total;
	static int init;
	struct stat info;
	
	stat(file, &info);
	if (init != 1)
	{
		total = 0;
		init = 1;
	}
	if (mode == 1 && opendir(file) == NULL)
	{
		if (info.st_size == 0)
            return (0);
		size = info.st_size / 512;
		if (size % 8 == 0)
			size++;
		while (size % 8 != 0)
			size++;
		if (size< 0)
            size = 8;
		total += size;
	}
	return (total);
}

void my_realloc(char **filelist, char *file)
{
	char *temp;
	size_t i;

	i = 0;
	temp = (char *)malloc((ft_strlen(*filelist) + 1) * sizeof(char));
	if (!temp)
		ft_perror(MEMORY, "");
	while ((*filelist)[i])
	{
		temp[i] = (*filelist)[i];
		i++;
	}
	temp[i] = '\0';
    i = ft_strlen(*filelist);
	*filelist = NULL;
	free(*filelist);
	*filelist = (char *)malloc(sizeof(char) * (i + ft_strlen(file) + 75));
	if (!filelist)
		ft_perror(MEMORY, "");
	i = 0;
	while (temp[i])
	{
		(*filelist)[i] = temp[i];
		i++;
	}
	free(temp);
}

void ft_ls(const char **args, int nb)
{
	DIR				*dir;
	struct dirent	*obj;
	char file[256];
	char *filelist;
	
	filelist = (char *)malloc(sizeof(char));
	if (!filelist)
		ft_perror(MEMORY, "");
	if (args != NULL)
		ft_check_flag(args, nb);
	if (args != NULL && ft_check_flag(args, nb) == 1)
		dir = opendir(ft_get_folder(args));
	else
		dir = opendir(".");
	if (dir)
	{
		while ((obj = readdir(dir)) != NULL)
		{
			ft_strcpy(file, obj->d_name);
			ls_process(args, file, &filelist, nb);
		}
		ft_print(args, filelist);
		closedir(dir);
	}
}

int main (int argc, char **argv)
{
	if (argc > 1)
		if (ft_strchr(ft_get_flags((const char **)argv), 't') != NULL)
			ft_time_ls((const char **)argv, argc);
		else
			ft_ls((const char **)argv, argc);
	else
		ft_ls(NULL, 0);
	return (0);
}
