/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:03:36 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/08 20:22:36 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	w3d_check(char ***map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			if (ft_strlen(map[i][j]) != 1 || ft_atoi(map[i][j]) > 1)
			{
				ft_putendl("Error: Corrupted or Invalid map in data/map");
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int		w3d_get_start(t_w3d **w3d)
{
	int		i;
	int		j;

	i = 0;
	while ((*w3d)->map[i] != NULL)
	{
		j = 0;
		while ((*w3d)->map[i][j] != NULL)
		{
			if (ft_strcmp((*w3d)->map[i][j], "X") == 0)
			{
				(*w3d)->pos.x = (64 * j) + 32;
				(*w3d)->pos.y = (64 * i) + 32;
				(*w3d)->pos.a = to_rad(90);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_putendl("Error: Start point not set in data/map");
	exit (0);
}

int		get_lines(char *file)
{
    int     i;
    int     fd;
    char    *line;

    i = 0;
    fd = open(file, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
        i++;
    i++;
    close(fd);
    return (i);
}

void     fdf_fill_data(t_file *d, char *file, t_w3d **w3d)
{
    d->fd = open(file, O_RDONLY);
    if (d->fd == -1)
	{
		ft_putendl("Error: File data/map not found");
		exit (0);
	}
	d->n = get_lines(file);
    d->line = NULL;
    d->i = 0;
	(*w3d)->height = d->n;
}

char	***ft_nbrsplit(char *file, t_w3d **w3d)
{
	t_file		d;
	char		***split;

	fdf_fill_data(&d, file, &(*w3d));
	split = (char ***)malloc(sizeof(char *) * get_lines(file) + 1);
	while (d.fd != -1 && get_next_line(d.fd, &(d.line)) > 0)
	{
		split[d.i++] = ft_strsplit(d.line, ' ');
	}
	(*w3d)->width = array_size(split[d.i - 1]);
    close(d.fd);
    split[d.i] = NULL;
    return (split);
}
