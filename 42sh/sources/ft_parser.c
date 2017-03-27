/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 17:52:25 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 18:53:26 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int		is_multi(char *line, t_env **env)
{
	char	**split;
	int		i;
	pid_t	papa;

	if ((i = 0) == 0 && ft_strchr(line, ';') != NULL)
	{
		split = ft_strsplit(line, ';');
		while (split[i] != NULL)
		{
			split[i] = ft_strtrim(split[i]);
			if (split[i][0] != '\0' && is_builtin(split[i], &(*env)) == 0)
			{
				papa = sh_fork();
				if (papa == 0)
					ft_parse(*env, &split[i]);
				else
					wait(0);
			}
			i++;
		}
		free(split);
		return (1);
	}
	return (0);
}

char	*ft_getenv(char *key, t_env *env)
{
	int		i;
	char	**split;

	i = is_env(env, key);
	if (i == -1)
		return (NULL);
	split = ft_strsplit(env->e[i], '=');
	return (split[1]);
}

int		is_path(char *cmd, t_env *env)
{
	char			**path;
	int				i;
	DIR				*d;
	struct dirent	*file;

	d = NULL;
	file = NULL;
	i = 0;
	path = ft_strsplit(ft_getenv("PATH", env), ':');
	while (path && path[i] != NULL)
	{
		if ((d = opendir(path[i])) != NULL)
		{
			while ((file = readdir(d)) != NULL)
				if (ft_strcmp(file->d_name, cmd) == 0)
				{
					free(path);
					return (i);
				}
			closedir(d);
		}
		i++;
	}
	return (-1);
}

int		is_env(t_env *env, char *s)
{
	int i;

	i = 0;
	while (env->e[i] != NULL)
	{
		if (ft_strncmp(env->e[i], s, id_chr(env->e[i], '=')) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_parse(t_env *env, char **line)
{
	env->av = ft_strsplit(*line, ' ');
	if (ft_strcmp(ft_strtolower(env->av[0]), "env") == 0)
		ft_env(env);
	else if (ft_strcmp(ft_strtolower(env->av[0]), "pwd") == 0)
		ft_pwd(env);
	else if (ft_strcmp(ft_strtolower(env->av[0]), "clear") == 0)
	{
		ft_putstr("\033[1;1H\033[2J");
		exit(0);
	}
	else
		ft_file(env);
}
