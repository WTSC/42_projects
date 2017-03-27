/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shi_core3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:29:51 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/01 21:41:20 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		setenv_check(char **args)
{
	int i;

	i = 0;
	if (array_size(args) < 2)
		return (0);
	while (args[i] != NULL)
	{
		if (args[i][0] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	update_env(t_env **env, char *key, char *value)
{
	char *join;
	char **split;

	join = ft_strjoin(key, "=");
	join = ft_strjoin(join, value);
	split = ft_strsplit(join, '=');
	ft_replaceenv(&(*env), split, join);
	free(join);
	free(split);
}

int		tilde_hyphen(t_env **env)
{
	char *sub;

	if ((*env)->av[1][0] == '~')
	{
		if (is_env(*env, "HOME") == -1)
			return (0);
		sub = ft_strsub((*env)->av[1], 1, ft_strlen((*env)->av[1]) - 1);
		free((*env)->av[1]);
		(*env)->av[1] = NULL;
		(*env)->av[1] = ft_strjoin(ft_getenv("HOME", *env), sub);
	}
	else if (ft_strcmp((*env)->av[1], "-") == 0)
	{
		if (is_env(*env, "OLDPWD") == -1)
			return (0);
		free((*env)->av[1]);
		(*env)->av[1] = NULL;
		(*env)->av[1] = ft_getenv("OLDPWD", *env);
	}
	return (1);
}

int		unsetenv_check(char *key, t_env *env)
{
	char	**lock;
	int		i;

	i = 0;
	lock = ft_strsplit(env->protected, ',');
	while (lock[i] != NULL)
	{
		if (!ft_strcmp(lock[i], key))
			return (0);
		i++;
	}
	return (1);
}

void	ft_prompt(t_env *env)
{
	print_time(env);
}
