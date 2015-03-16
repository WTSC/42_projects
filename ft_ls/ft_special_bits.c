/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:54:51 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 16:10:47 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void user_bit(char **fl, char *file)
{
	struct stat i;

	if (lstat(file, &i) == 0)
	{
		if (i.st_mode & S_ISUID)
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXUSR) ? "s" : "S");
		else
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXUSR) ? "x" : "-");
	}
}

void group_bit(char **fl, char *file)
{
	struct stat i;

	if (lstat(file, &i) == 0)
	{
		if (i.st_mode & S_ISGID)
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXGRP) ? "s" : "S");
		else
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXGRP) ? "x" : "-");
	}
}

void other_bit(char **fl, char *file)
{
	struct stat i;

	if (lstat(file, &i) == 0)
	{
		if (i.st_mode & S_ISVTX)
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXOTH) ? "t" : "T");
		else
			*fl = ft_mallcat(*fl, (i.st_mode & S_IXOTH) ? "x" : "-");
	}
}
