/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:27:54 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:11:49 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <sys/xattr.h>

void	ft_info(char **filelist, char *file, char *folder, const char **args)
{
	int		mlen1;
	int		mlen2;
	int		dev[2];
	char	*path;

	dev[0] = ft_max_majmin(folder, args, 1, 0);
	dev[1] = ft_max_majmin(folder, args, 2, 0);
	path = ft_strdup(file);
	mlen1 = ft_max_str(folder, args, 1, 0);
	mlen2 = ft_max_str(folder, args, 2, 0);
	if (ft_get_xattr(folder, args) == 1)
		ft_get_permissions(&(*filelist), file, 1);
	else
		ft_get_permissions(&(*filelist), file, 0);
	ft_get_links(&(*filelist), file, ft_max_len(folder, args, 2, 0));
	uidgid2(&(*filelist), file, mlen1, mlen2);
	ft_get_size(&(*filelist), file, ft_max_len(folder, args, 1, 0) + 1, dev);
	ft_get_date(&(*filelist), file);
	*filelist = ft_mallcat(*filelist, ft_basename(file));
	ft_link(&(*filelist), path);
	*filelist = ft_mallcat(*filelist, "\n");
}

void	ft_perror(int code, const void *arg, char flag)
{
	char *str;

	if (code == 0)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(flag);
		ft_putstr("\n");
		ft_putendl("usage: ls [-atrlR] [file ...]");
		exit(0);
	}
	else if (code == 1)
	{
		ft_putendl("ls: not enough memory to perform the operation");
		exit(0);
	}
	else if (flag == 1)
	{
		str = (char *)arg;
		str = ft_basename(str);
		ft_putstr("ls: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putendl(strerror(code));
	}
}

int		ft_out(char *file, const char **args, char **filelist, char *folder)
{
	char	*flags;
	char	*basename;

	flags = ft_get_flags(args);
	if (ft_strchr(flags, 'l') != NULL)
	{
		basename = ft_basename(file);
		if (ft_strchr(flags, 'a') == NULL && basename[0] == '.')
			return (0);
		ft_print_total(file, 1);
		ft_info(&(*filelist), file, folder, args);
		return (0);
	}
	if (ft_strchr(flags, 'a') == NULL)
		if (ft_basename(file)[0] == '.')
			return (0);
	*filelist = ft_mallcat(*filelist, ft_basename(file));
	*filelist = ls_separate(*filelist, args);
	return (0);
}

void	ft_print(const char **args, char *filelist)
{
	int total;

	if (args == NULL || ft_strchr(ft_get_flags(args), 'l') == NULL)
	{
		filelist[ft_strlen(filelist) - 1] = '\0';
	}
	else if (ft_strlen(filelist) > 0)
	{
		filelist[ft_strlen(filelist) - 1] = '\0';
		total = ft_print_total(" ", 0);
		ft_putstr("total ");
		ft_putendl(ft_itoa(total));
		ft_print_total(NULL, 2);
	}
	if (ft_strlen(filelist) > 0)
		ft_putendl(filelist);
	else
		ft_putstr(filelist);
	free(filelist);
}

void	ls_proc(const char **args, char **array, char **filelist, char *folder)
{
	int i;

	if ((i = 0) == 0 && args != NULL)
	{
		if (ft_strchr(ft_get_flags(args), 'r') != NULL)
			array = ft_arrev(array, array_size(array));
		while (array[i])
		{
			ft_out(array[i], args, &(*filelist), folder);
			i++;
		}
	}
	else
	{
		while (array[i])
		{
			if (ft_basename(array[i])[0] != '.')
			{
				*filelist = ft_mallcat(*filelist, ft_basename(array[i]));
				*filelist = ls_separate(*filelist, args);
			}
			i++;
		}
	}
}
