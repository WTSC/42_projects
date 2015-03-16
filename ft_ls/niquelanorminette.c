/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niquelanorminette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 00:25:05 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:22:19 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "ft_ls.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

void ft_majorminor(char *file, char **filelist, int l1, int l2)
{
	struct stat		info;
	char			*str;
	char			*str2;

	str = (char *)malloc(sizeof(char) * l1);
	str2 = (char *)malloc(sizeof(char) * l2);
	if (lstat(file, &info) == 0)
	{
		putmajor(&(*filelist), l1, str, (long)major(info.st_rdev));
		*filelist = ft_mallcat(*filelist, ", ");
		putmajor(&(*filelist), l2, str2, (long)minor(info.st_rdev));
		*filelist = ft_mallcat(*filelist, " ");
	}
	free(str);
	free(str2);
}

void modif_time(char **filelist, char **str, long long tiemm, char **hour)
{
	if ((long long)time(NULL) - tiemm > 15778463
		|| (long long)time(NULL) - tiemm < 0)
	{
		*filelist = ft_mallcat(*filelist, " ");
		str[4][ft_strlen(str[4]) - 1] = '\0';
		*filelist = ft_mallcat(*filelist, str[4]);
		*filelist = ft_mallcat(*filelist, " ");
	}
	else
	{
		*filelist = ft_mallcat(*filelist, hour[0]);
		*filelist = ft_mallcat(*filelist, ":");
		*filelist = ft_mallcat(*filelist, hour[1]);
		*filelist = ft_mallcat(*filelist, " ");
	}
}

char *ft_basename(char *path)
{
	int		i;
	int		j;
	char	*copy;

	i = ft_strlen(path) - 1;
	while (path[i] == '/')
		i--;
	j = i + 1;
	while (i != 0 && path[i - 1] != '/')
		i--;
	copy = ft_strsub(path, i, j - i);
	return (copy);
}

char *ls_separate(char *filelist, const char **args)
{
	if (args != NULL && ft_strchr(ft_get_flags(args), '1') != NULL)
		filelist = ft_mallcat(filelist, "\n");
	else
		filelist = ft_mallcat(filelist, "\n");
	return (filelist);
}

void ls_separate2(int i, char **dirs, const char **args)
{
	int test;

	test = test_dir(dirs[i - 1], i, args);
	if (array_size(dirs) != 1 && test != 12 && test != -1
		&& test != 2)
	{
		if (i != array_size(dirs))
			ft_putstr("\n");
	}
	else
	{
		if (ft_strchr(ft_get_flags(args), 'l') != NULL
			&& array_size(dirs) == 1 && test == 2)
			ft_putstr("\n");
		else if ((test == 12 || test == -1)
				&& ft_strchr(ft_get_flags(args), 'R') != NULL)
			ft_putstr("\n");
	}
}
