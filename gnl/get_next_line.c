/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 01:24:58 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 18:29:25 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strichr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_cut(char **buffer, char **line)
{
	int	id;
	int len;

	len = ft_strlen(*buffer);
	if ((id = ft_strichr(*buffer, '\n')) != -1)
	{
		*line = ft_strsub(*buffer, 0, id);
		*buffer = ft_strsub(*buffer, id + 1, len - id - 1);
	}
	else
	{
		if (*buffer[0] != '\0')
			*line = ft_strdup(*buffer);
		*buffer = NULL;
	}
}

int		ft_read(int const fd, char **buffer)
{
	int		ret;
	char	tmp[BUF_SIZE + 1];

	while ((ret = read(fd, tmp, BUF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (!(*buffer))
			*buffer = ft_strdup(tmp);
		else
			*buffer = ft_strjoin(*buffer, tmp);
	}
	return ((ret == -1) ? -1 : 1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buffer;
	int			ret;

	if (!line || BUF_SIZE <= 0 || fd < 0 || BUF_SIZE > 8000000)
		return (-1);
	if (*line)
		*line = NULL;
	ret = 0;
	if (!buffer)
		ret = ft_read(fd, &buffer);
	if (ret == -1)
		return (-1);
	if (!buffer)
	{
		*line = ft_strnew(1);
		return (0);
	}
	ft_cut(&buffer, &(*line));
	return ((*line) ? 1 : 0);
}
