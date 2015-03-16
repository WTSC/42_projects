/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_folders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 04:54:50 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 16:19:41 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/includes/libft.h"
#include <strings.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

char **ft_arradd(char **dst, char *src)
{
	char	**join;
	int		len;

	if (!dst)
	{
		join = (char **)malloc(sizeof(char *) * 2);
		join[0] = ft_strdup(src);
		join[1] = NULL;
	}
	else
	{
		len = array_size(dst);
		join = (char **)malloc(sizeof(char *) * (len + 2));
		join = ft_arrcpy(join, (const char **)dst);
		join[len] = ft_strdup(src);
		join[len + 1] = NULL;
	}
	return (join);
}

char **ft_filesfirst(char **folders)
{
	int				i;
	struct stat		info;
	static char		**files;
	static char		**dirs;
	static char		**join;

	i = 0;
	while (folders[i] != NULL)
	{
		if (lstat(folders[i], &info) >= 0)
		{
			if (S_ISDIR(info.st_mode))
				dirs = ft_arradd(dirs, folders[i]);
			else
				files = ft_arradd(files, folders[i]);
		}
		else
			join = ft_arradd(join, folders[i]);
		i++;
	}
	join = ft_arrjoin(join, files);
	join = ft_arrjoin(join, dirs);
	return (join);
}
