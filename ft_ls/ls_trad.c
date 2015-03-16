/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_trad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 21:18:17 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:21:43 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/xattr.h>

void	ft_link(char **fl, char *f)
{
	struct stat		i;
	char			target[256];
	int				len;

	if (lstat(f, &i) == 0)
	{
		if (S_ISLNK(i.st_mode))
		{
			if ((len = readlink(f, target, 256)) != -1)
			{
				target[len] = '\0';
				*fl = ft_mallcat(*fl, " -> ");
				*fl = ft_mallcat(*fl, target);
			}
		}
	}
}

void	uidgid2(char **fl, char *f, int mlen1, int mlen2)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		i;

	lstat(f, &i);
	pwd = getpwuid(i.st_uid);
	grp = getgrgid(i.st_gid);
	if (pwd == NULL && grp == NULL)
		only_uid_gid(&(*fl), f, mlen1, mlen2);
	else if (pwd == NULL)
		only_uid(&(*fl), f, mlen1, mlen2);
	else if (grp == NULL)
		only_gid(&(*fl), f, mlen1, mlen2);
	else
		ft_get_uid_gid(&(*fl), f, mlen1, mlen2);
}

void	uidgid(char **fl, char *f)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		i;
	int				len1;
	int				len2;

	lstat(f, &i);
	pwd = getpwuid(i.st_uid);
	grp = getgrgid(i.st_gid);
	if (pwd == NULL && grp == NULL)
		only_uid_gid(&(*fl), f, ft_int_len(i.st_uid), ft_int_len(i.st_gid));
	else if (pwd == NULL)
		only_uid(&(*fl), f, ft_int_len(i.st_uid), ft_strlen(grp->gr_name));
	else if (grp == NULL)
		only_gid(&(*fl), f, ft_strlen(pwd->pw_name), ft_int_len(i.st_gid));
	else
	{
		len1 = ft_strlen(pwd->pw_name);
		len2 = ft_strlen(grp->gr_name);
		ft_get_uid_gid(&(*fl), f, len1, len2);
	}
}

void	ft_file_info(char **fl, char *f)
{
	struct stat		i;
	int				dev[2];
	char			buff[256];

	lstat(f, &i);
	dev[0] = ft_int_len((long)major(i.st_rdev));
	dev[1] = ft_int_len((long)minor(i.st_rdev));
	if (listxattr(f, buff, 256, 0) > 0)
		ft_get_permissions(&(*fl), f, 1);
	else
		ft_get_permissions(&(*fl), f, 0);
	ft_get_links(&(*fl), f, ft_int_len(i.st_nlink));
	uidgid(&(*fl), f);
	*fl = ft_mallcat(*fl, " ");
	ft_get_size(&(*fl), f, ft_int_len(i.st_size), dev);
	ft_get_date(&(*fl), f);
	*fl = ft_mallcat(*fl, f);
	ft_link(&(*fl), f);
}
