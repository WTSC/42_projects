/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minormajor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 23:14:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:20:59 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>

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
