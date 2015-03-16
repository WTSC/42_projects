/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 04:33:31 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 13:28:39 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>

int		is_dot(char *file, char *folder, const char **args)
{
	char	*basename;
	char	*flags;

	(void)folder;
	flags = ft_get_flags(args);
	basename = ft_basename(file);
	if (basename[0] == '.' && ft_strchr(flags, 'a') == NULL)
		return (0);
	else
		return (1);
}

int		ft_max_str(char *folder, const char **args, int mode, int i)
{
	char			**array;
	struct stat		info;
	int				len[2];

	len[1] = 0;
	array = list_dir(args, array_size((char **)args), folder);
	array = ft_qsort(array, array_size(array));
	if ((i = 0) == 0 && ft_strchr(ft_get_flags(args), 't') != NULL)
		array = ft_sort_by_time(array, array_size(array), folder);
	while (lstat(array[i], &info) != -1)
	{
		len[0] = calc_len(mode, info.st_uid, info.st_gid);
		if (is_dot(array[i], folder, args) && len[0] > len[1])
			len[1] = len[0];
		i++;
	}
	return (len[1]);
}

int		ft_max_len(char *folder, const char **args, int mode, int i)
{
	char			**array;
	struct stat		info;
	int				size;
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
			size = info.st_size;
		else
			size = info.st_nlink;
		while ((size = (size / 10)) != 0)
			len++;
		if (is_dot(array[i], folder, args) && len > mlen)
			mlen = len;
		i++;
	}
	return (mlen + 1);
}

char	**ft_arrev(char **copy, int size)
{
	char	**copycopy;
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	copycopy = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		copycopy[i++] = ft_strdup(copy[j--]);
	}
	copycopy[i] = NULL;
	return (copycopy);
}

char	*ft_mallcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = NULL;
	s1 = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(tmp) + 4));
	if (!s1)
		ft_perror(MEMORY, "", 0);
	s1 = ft_strcpy(s1, tmp);
	s1 = ft_strcat(s1, s2);
	free(tmp);
	tmp = NULL;
	return (s1);
}
