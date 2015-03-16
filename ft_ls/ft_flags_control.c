/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:10:40 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/12 15:37:26 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_ls.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

char	*ft_get_flags(const char **args)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*flags;

	j = 1;
	k = 0;
	flags = (char *)malloc(sizeof(char) * 10);
	flags[0] = '\0';
	while (args[j] != NULL && args[j][0] == '-' && args[j][1])
	{
		i = 1;
		while (args[j][i])
		{
			if (k == 0 || ft_strchr(flags, args[j][i]) == NULL)
				flags[k++] = args[j][i];
			i++;
		}
		j++;
	}
	flags[k] = '\0';
	return (flags);
}

int		ft_check_flag(const char **args, int nb)
{
	size_t	i;
	int		j;

	i = 1;
	j = 1;
	while (j < nb && args[j][0] == '-' && args[j][1])
	{
		while (i < ft_strlen(args[j]))
		{
			if (ft_strchr("-1atrlR", args[j][i]) == NULL)
				ft_perror(ILLEGAL, "", args[j][i]);
			i++;
		}
		i = 1;
		j++;
	}
	if (args[j] || ft_strchr(ft_get_flags(args), 'R') != NULL)
	{
		return (1);
	}
	else
	{
		return (2);
	}
}

char	**ft_get_folder(const char **args, int nb)
{
	int		i;
	size_t	j;
	char	**folders;

	folders = (char **)malloc(sizeof(char *) * nb);
	i = 1;
	j = 0;
	while (args[i] && args[i][0] == '-' && args[i][1])
		i++;
	if (i < nb)
		while (i < nb)
		{
			if ((int)args[i++][0] != 0)
				folders[j++] = ft_strdup(args[i - 1]);
		}
	else
		folders[0] = ft_strdup(".");
	i = 0;
	folders = ft_qsort(folders, array_size(folders));
	folders = ft_filesfirst(folders);
	if (ft_strchr(ft_get_flags(args), 'r') != NULL)
		folders = ft_arrev(folders, array_size(folders));
	if (ft_strchr(ft_get_flags(args), 'R') != NULL)
		folders = ft_recursive(folders, args);
	return (folders);
}
