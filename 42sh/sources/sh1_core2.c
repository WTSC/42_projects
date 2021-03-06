/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_core2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:19:20 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 19:08:39 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

char	**ft_arradd(char **a1, char *a2)
{
	char	**join;
	int		i;

	i = 0;
	if (!a1)
	{
		a1 = (char **)malloc(sizeof(char *));
		a1[0] = NULL;
	}
	join = (char **)malloc(sizeof(char *) * (array_size(a1) + 2));
	while (a1[i] != NULL)
	{
		join[i] = ft_strdup(a1[i]);
		i++;
	}
	join[i] = ft_strdup(a2);
	i++;
	join[i] = NULL;
	return (join);
}

void	ft_replaceenv(t_env **env, char **split, char *newenv)
{
	int i;

	i = is_env(*env, split[0]);
	free((*env)->e[i]);
	(*env)->e[i] = NULL;
	(*env)->e[i] = ft_strdup(newenv);
}

void	ft_setenv(t_env **env)
{
	char	**split;
	int		i;

	i = 1;
	if (!setenv_check((*env)->av))
		ft_putendl("Usage : setenv KEY[=VALUE] ...");
	while ((*env)->av[i] != NULL && setenv_check((*env)->av))
	{
		if (ft_strchr((*env)->av[i], '=') != NULL)
		{
			split = ft_strsplit((*env)->av[i], '=');
			if (is_env(*env, split[0]) != -1)
				ft_replaceenv(&(*env), split, (*env)->av[i]);
			else
			{
				(*env)->e = ft_arradd((*env)->e, (*env)->av[i]);
			}
		}
		else if (is_env(*env, (*env)->av[i]) == -1)
		{
			(*env)->av[i] = ft_strjoin((*env)->av[i], "=");
			(*env)->e = ft_arradd((*env)->e, (*env)->av[i]);
		}
		i++;
	}
}

char	**ft_arrdel(char **a, int i)
{
	char	**new;
	int		j;
	int		k;

	j = 0;
	new = (char **)malloc(sizeof(char *) * array_size(a));
	while (j < i)
	{
		new[j] = ft_strdup(a[j]);
		j++;
	}
	k = j + 1;
	while (a[k] != NULL)
	{
		new[j] = ft_strdup(a[k]);
		j++;
		k++;
	}
	new[j] = NULL;
	return (new);
}

void	ft_unsetenv(t_env **env)
{
	int i;
	int j;

	j = 1;
	if (array_size((*env)->av) < 2)
		ft_putendl("error");
	while ((*env)->av[j] != NULL)
	{
		if (!unsetenv_check((*env)->av[j], *env))
		{
			ft_putstr("error : can't unset ");
			ft_putendl((*env)->av[j]);
		}
		else if ((i = is_env(*env, (*env)->av[j])) != -1)
			(*env)->e = ft_arrdel((*env)->e, i);
		j++;
	}
}
