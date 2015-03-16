/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 21:13:09 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:32:47 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <string.h>
#include <sys/stat.h>

char	**ft_qsort(char **array, int size)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				temp = ft_strdup(array[i]);
				free(array[i]);
				array[i] = ft_strdup(array[i + 1]);
				free(array[i + 1]);
				array[i + 1] = ft_strdup(temp);
			}
			i++;
		}
		j++;
	}
	return (array);
}

int		ft_time_ls(const char **args, int nb, char *folder, int test)
{
	char	**array;
	char	*filelist;

	test = test_dir(folder, -1, args);
	if (test == 12 || test == -1)
		return (0);
	filelist = (char *)malloc(sizeof(char) * 513);
	if (!filelist)
		ft_perror(MEMORY, "", 0);
	filelist[0] = '\0';
	if (test_dir(folder, -1, args) == 2)
	{
		if (ft_strchr(ft_get_flags(args), 'l') == NULL)
			ft_putendl(ft_basename(folder));
		else
			ft_file_info(&filelist, folder);
		ft_putstr(filelist);
		return (1);
	}
	array = list_dir(args, nb, folder);
	array = ft_qsort(array, array_size(array));
	array = ft_sort_by_time(array, array_size(array), folder);
	ls_proc(args, array, &filelist, folder);
	ft_print(args, filelist);
	return (0);
}

int		ft_ls(const char **args, int nb, char *folder)
{
	char	**array;
	char	*filelist;
	int		test;

	test = test_dir(folder, -1, args);
	if (test == 12 || test == -1)
		return (0);
	filelist = (char *)malloc(sizeof(char) * 312);
	if (!filelist)
		ft_perror(MEMORY, "", 0);
	filelist[0] = '\0';
	if (test_dir(folder, -1, args) == 2)
	{
		if (ft_strchr(ft_get_flags(args), 'l') == NULL)
			ft_putendl(ft_basename(folder));
		else
			ft_file_info(&filelist, folder);
		ft_putstr(filelist);
		return (1);
	}
	array = list_dir(args, nb, folder);
	array = ft_qsort(array, array_size(array));
	ls_proc(args, array, &filelist, folder);
	ft_print(args, filelist);
	return (0);
}

int		main(int argc, const char **argv)
{
	char		**dirs;
	static int	i;

	if (argc > 1 && (int)argv[1][0] != 0)
	{
		dirs = ft_get_folder(argv, argc);
		while (dirs[i])
		{
			if (array_size(dirs) >= 2 && test_dir(dirs[i], i, argv) < 2)
			{
				if (i != 0 && test_dir(dirs[i - 1], i, argv) == 2)
					ft_putstr("\n");
				ft_putstr(dirs[i]);
				ft_putendl(":");
			}
			if (ft_strchr(ft_get_flags(argv), 't') != NULL)
				ft_time_ls(argv, argc, dirs[i++], 0);
			else
				ft_ls(argv, argc, dirs[i++]);
			ls_separate2(i, dirs, argv);
		}
	}
	else
		ft_ls(NULL, 0, ".");
	return (0);
}
