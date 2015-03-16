/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uidgid_exceptions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:40:28 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 16:20:19 by jantiope         ###   ########.fr       */
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

int		calc_len(int mode, unsigned int uid, unsigned int gid)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				len;

	pwd = getpwuid(uid);
	grp = getgrgid(gid);
	if (mode == 1)
	{
		if (pwd == NULL)
			len = ft_int_len(uid);
		else
			len = ft_strlen(pwd->pw_name);
	}
	else if (grp == NULL)
		len = ft_int_len(gid);
	else
		len = ft_strlen(grp->gr_name);
	return (len);
}

void	only_uid_gid(char **filelist, char *file, int max1, int max2)
{
	struct stat			info;
	char				str[33];
	char				str2[33];

	if (lstat(file, &info) == 0)
	{
		ft_memcpy(str, ft_itoa(info.st_uid), ft_int_len(info.st_uid) + 1);
		*filelist = ft_mallcat(*filelist, str);
		while (ft_int_len(info.st_uid) != max1--)
			*filelist = ft_mallcat(*filelist, " ");
		*filelist = ft_mallcat(*filelist, "  ");
		ft_memcpy(str2, ft_itoa(info.st_gid), ft_int_len(info.st_uid) + 1);
		*filelist = ft_mallcat(*filelist, str2);
		while (ft_int_len(info.st_gid) != max2--)
			*filelist = ft_mallcat(*filelist, " ");
	}
}

void	only_uid(char **filelist, char *file, int max1, int max2)
{
	struct stat			info;
	struct group		*grp;
	char				str[33];
	char				str2[33];

	if (lstat(file, &info) == 0)
	{
		ft_memcpy(str, ft_itoa(info.st_uid), ft_int_len(info.st_uid) + 1);
		*filelist = ft_mallcat(*filelist, str);
		while (ft_int_len(info.st_uid) != max1--)
			*filelist = ft_mallcat(*filelist, " ");
		*filelist = ft_mallcat(*filelist, "  ");
		if ((grp = getgrgid(info.st_gid)) != NULL)
		{
			while ((int)ft_strlen(grp->gr_name) != max2--)
				*filelist = ft_mallcat(*filelist, " ");
			ft_memcpy(str2, grp->gr_name, ft_strlen(grp->gr_name) + 1);
			*filelist = ft_mallcat(*filelist, str2);
		}
	}
}

void	only_gid(char **filelist, char *file, int max1, int max2)
{
	struct stat			info;
	struct passwd		*pwd;
	char				str[33];
	char				str2[33];

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
		ft_memcpy(str2, ft_itoa(info.st_gid), ft_int_len(info.st_gid) + 1);
		*filelist = ft_mallcat(*filelist, str2);
		while (ft_int_len(info.st_gid) != max2--)
			*filelist = ft_mallcat(*filelist, " ");
	}
}
