/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minormajor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 23:14:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:55:55 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>

void		printype(char **filelist, char *file)
{
	struct stat info;

	lstat(file, &info);
	if (S_ISCHR(info.st_mode))
		*filelist = ft_mallcat(*filelist, "c");
	else if (S_ISBLK(info.st_mode))
		*filelist = ft_mallcat(*filelist, "b");
	else if (S_ISLNK(info.st_mode))
		*filelist = ft_mallcat(*filelist, "l");
	else if (S_ISSOCK(info.st_mode))
		*filelist = ft_mallcat(*filelist, "s");
	else if (S_ISFIFO(info.st_mode))
		*filelist = ft_mallcat(*filelist, "p");
	else
		*filelist = ft_mallcat(*filelist, (S_ISDIR(info.st_mode)) ? "d" : "-");
}

void		putmajor(char **filelist, int l, char *str, long int size)
{
	while (l != (int)ft_strlen(ft_itoa(size)))
	{
		*filelist = ft_mallcat(*filelist, " ");
		l--;
	}
	ft_memcpy(str, ft_itoa(size), ft_strlen(ft_itoa(size)) + 1);
	*filelist = ft_mallcat(*filelist, str);
}

int			ft_get_xattr(char *folder, const char **args)
{
	char	**array;
	int		i;
	char	buff[256];

	i = 0;
	array = list_dir(args, array_size((char **)args), folder);
	array = ft_qsort(array, array_size(array));
	if (ft_strchr(ft_get_flags(args), 't') != NULL)
		array = ft_sort_by_time(array, array_size(array), folder);
	while (array[i] != NULL)
	{
		if (listxattr(array[i], buff, 256, 0) > 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_max_majmin(char *folder, const char **args, int mode, int i)
{
	char			**array;
	struct stat		info;
	long int		size;
	int				len;
	int				mlen;

	mlen = 0;
	array = list_dir(args, array_size((char **)args), folder);
	array = ft_qsort(array, array_size(array));
	if (ft_strchr(ft_get_flags(args), 't') != NULL)
		array = ft_sort_by_time(array, array_size(array), folder);
	while (lstat(array[i], &info) != -1)
	{
		if ((len = 0) == 0 && mode == 1)
			size = (long)major(info.st_rdev);
		else
			size = (long)minor(info.st_rdev);
		while ((size = (size / 10)) != 0)
			len++;
		if (is_dot(array[i], folder, args) && len > mlen)
			mlen = len;
		i++;
	}
	return (mlen + 1);
}
