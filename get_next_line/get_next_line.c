/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:06:09 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/14 18:09:23 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	my_realloc(char **line, size_t oldsize)
{
	char	*temp;
	size_t	i;

	i = 0;
	(*line)[oldsize] = '\0';
	temp = (char *)malloc((oldsize + 1) * sizeof(char));
	while (i < oldsize)
	{
		temp[i] = (*line)[i];
		i++;
	}
	temp[i] = '\0';
	*line = NULL;
	free(*line);
	*line = (char *)malloc(sizeof(char) * (oldsize + 2));
	i = 0;
	while (temp[i] != '\0')
	{
		(*line)[i] = temp[i];
		i++;
	}
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	char	*buffer;
	int		cursor;
	size_t	i;

	buffer = (char *)malloc(sizeof(char));
	*line = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	i = 0;
	if (fd < 0 || !line || !buffer)
		return (-1);
	cursor = 1;
	while (cursor != 0)
	{
		cursor = read(fd, buffer, 1);
		if (buffer[0] == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		if (i > BUF_SIZE)
			my_realloc(&(*line), i);
		(*line)[i++] = buffer[0];
	}
	(*line)[i - 1] = '\0';
	return (0);
}
