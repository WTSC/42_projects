/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:33:20 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 03:00:35 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <stdlib.h>
#include <time.h>
#include <sys/xattr.h>

void ft_get_permissions(char **filelist, char *file, int mode)
{
	struct stat info;
	char		buff[256];

	lstat(file, &info);
	printype(&(*filelist), file);
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IRUSR) ? "r" : "-");
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IWUSR) ? "w" : "-");
	user_bit(&(*filelist), file);
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IRGRP) ? "r" : "-");
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IWGRP) ? "w" : "-");
	group_bit(&(*filelist), file);
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IROTH) ? "r" : "-");
	*filelist = ft_mallcat(*filelist, (info.st_mode & S_IWOTH) ? "w" : "-");
	other_bit(&(*filelist), file);
	if (mode == 1)
		*filelist = ft_mallcat(*filelist, (listxattr(file, buff, 256, 0) > 0)
							? "@" : " ");
	*filelist = ft_mallcat(*filelist, (mode == 1) ? " " : "  ");
}

void ft_get_links(char **filelist, char *file, size_t maxlen)
{
	struct stat	info;
	int			links;
	char		*str;
	size_t		i;

	i = maxlen;
	str = (char *)malloc(sizeof(char) * maxlen + 1);
	if (lstat(file, &info) == 0)
	{
		links = info.st_nlink;
		i = ft_strlen(ft_itoa(links));
		while (maxlen != i)
		{
			*filelist = ft_mallcat(*filelist, " ");
			i++;
		}
		ft_memcpy(str, ft_itoa(links), ft_strlen(ft_itoa(links)) + 1);
		*filelist = ft_mallcat(*filelist, str);
		*filelist = ft_mallcat(*filelist, " ");
	}
	free(str);
}

void ft_get_uid_gid(char **filelist, char *file, int max1, int max2)
{
	struct stat		info;
	struct passwd	*pwd;
	struct group	*grp;
	char			str[33];
	char			str2[33];

	if (lstat(file, &info) == 0)
	{
		if ((pwd = getpwuid(info.st_uid)) != NULL)
		{
			ft_memcpy(str, pwd->pw_name, ft_strlen(pwd->pw_name) + 1);
			*filelist = ft_mallcat(*filelist, str);
			while ((int)ft_strlen(pwd->pw_name) != max1--)
				*filelist = ft_mallcat(*filelist, " ");
		}
		*filelist = ft_mallcat(*filelist, "  ");
		if ((grp = getgrgid(info.st_gid)) != NULL)
		{
			ft_memcpy(str2, grp->gr_name, ft_strlen(grp->gr_name) + 1);
			*filelist = ft_mallcat(*filelist, str2);
			while ((int)ft_strlen(grp->gr_name) != max2--)
				*filelist = ft_mallcat(*filelist, " ");
		}
	}
	*filelist = ft_mallcat(*filelist, " ");
}

void ft_get_size(char **filelist, char *file, size_t maxlen, int *dev)
{
	struct stat		info;
	size_t			size;
	char			*str;
	int				i;

	i = maxlen - 1;
	str = (char *)malloc(sizeof(char) * maxlen);
	if (lstat(file, &info) == 0)
	{
		if (S_ISCHR(info.st_mode) || S_ISBLK(info.st_mode))
			ft_majorminor(file, &(*filelist), dev[0], dev[1]);
		else
		{
			size = info.st_size;
			while (i != (int)ft_strlen(ft_itoa(size)) - 1)
			{
				*filelist = ft_mallcat(*filelist, " ");
				i--;
			}
			ft_memcpy(str, ft_itoa(size), ft_strlen(ft_itoa(size)) + 1);
			*filelist = ft_mallcat(*filelist, str);
			*filelist = ft_mallcat(*filelist, " ");
		}
	}
	free(str);
}

void ft_get_date(char **filelist, char *file)
{
	struct stat		info;
	char			**str;
	char			**hour;
	size_t			i;

	i = 0;
	if (lstat(file, &info) == 0)
	{
		str = ft_strsplit(ctime(&info.st_mtime), ' ');
		hour = ft_strsplit(str[3], ':');
		while (str[1][i++])
			str[1][i] = ft_tolower(str[1][i]);
		if (ft_strlen(str[2]) == 1)
			*filelist = ft_mallcat(*filelist, " ");
		*filelist = ft_mallcat(*filelist, str[2]);
		*filelist = ft_mallcat(*filelist, " ");
		*filelist = ft_mallcat(*filelist, ft_strtolower(str[1]));
		*filelist = ft_mallcat(*filelist, " ");
		modif_time(&(*filelist), str, (long long)info.st_mtime, hour);
	}
}
