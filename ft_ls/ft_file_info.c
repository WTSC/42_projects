/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:33:20 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/18 03:56:58 by jantiope         ###   ########.fr       */
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

void ft_get_permissions(char **filelist, char *file)
{
	struct stat info;

	if (stat(file, &info) == 0)
	{
		*filelist = ft_strcat(*filelist, (S_ISDIR(info.st_mode))? "d" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IRUSR)? "r" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IWUSR)? "w" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IXUSR)? "x" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IRGRP)? "r" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IWGRP)? "w" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IXGRP)? "x" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IROTH)? "r" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IWOTH)? "w" : "-");
		*filelist = ft_strcat(*filelist, (info.st_mode & S_IXOTH)? "x" : "-");
		*filelist = ft_strcat(*filelist, "  ");
	}
}

void ft_get_links(char **filelist, char *file)
{
	struct stat info;
	int links;
	char str[10];
	
    if (stat(file, &info) == 0)
    {
		links = info.st_nlink;
		ft_memcpy(str, ft_itoa(links), ft_strlen(ft_itoa(links)) + 1);
		*filelist = ft_strcat(*filelist, str);
		*filelist = ft_strcat(*filelist, " ");
	}
}

#include <stdio.h>
void ft_get_uid_gid(char **filelist, char *file)
{
	struct stat		info;
	struct passwd	*pwd;
	struct group	*grp;
	char			str[32];
	char			str2[32];

    if (stat(file, &info) == 0)
    {
		if ((pwd = getpwuid(info.st_uid)) != NULL)
		{
			ft_memcpy(str, pwd->pw_name, ft_strlen(pwd->pw_name) + 1);
			*filelist = ft_strcat(*filelist, str);
		}
		*filelist = strcat(*filelist, "  ");
		if ((grp = getgrgid(info.st_gid)) != NULL)
		{
			ft_memcpy(str2, grp->gr_name, ft_strlen(grp->gr_name) + 1);
			*filelist = ft_strcat(*filelist, str2);
		}
		*filelist = ft_strcat(*filelist, "  ");
	}
}

void ft_get_size(char **filelist, char *file, size_t maxlen)
{
	struct stat     info;
	size_t			size;
	char			*str;

	str = (char *)malloc(sizeof(char) * maxlen);
	if (stat(file, &info) == 0)
    {
		size = info.st_size;
		while (maxlen-- != ft_strlen(ft_itoa(size)))
			*filelist = strcat(*filelist, " ");
		ft_memcpy(str, ft_itoa(size), ft_strlen(ft_itoa(size)) + 1);
		*filelist = ft_strcat(*filelist, str);
        *filelist = strcat(*filelist, " ");
	}
}

void ft_get_date(char **filelist, char *file)
{
	struct stat     info;
    char            **str;
	char			**hour;
    int				i;

	i = 0;
	if (stat(file, &info) == 0)
    {
		str = ft_strsplit(ctime(&info.st_mtime), ' ');
		hour = ft_strsplit(str[3], ':');
		while (str[1][i])
		{
			str[1][i] = ft_tolower(str[1][i]);
			i++;
		}
		*filelist = ft_strcat(*filelist, str[2]);
		*filelist = ft_strcat(*filelist, " ");
		*filelist = ft_strcat(*filelist, str[1]);
		*filelist = ft_strcat(*filelist, " ");
		*filelist = ft_strcat(*filelist, hour[0]);
		*filelist = ft_strcat(*filelist, ":");
		*filelist = ft_strcat(*filelist, hour[1]);		
		*filelist = ft_strcat(*filelist, " ");
	}
}
