#include "libft/libft.h"
#include "ft_sh1.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

char **ft_arradd(char **a1, char *a2)
{
	char **join;
	int i;

	i = 0;
	join = (char **)malloc(sizeof(char *) * (array_size(a1) + 1));
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

void ft_replaceenv(t_env **env, char **split, char *newenv)
{
	int i;

	i = is_env(*env, split[0]);
	free((*env)->e[i]);
	(*env)->e[i] = NULL;
	(*env)->e[i] = ft_strdup(newenv);
}

void ft_setenv(t_env **env)
{
	char **split;

	if (array_size((*env)->av) > 1)
		if (ft_strchr((*env)->av[1], '=') != NULL)
		{
			split = ft_strsplit((*env)->av[1], '=');
			if (is_env(*env, split[0]) != -1)
				ft_replaceenv(&(*env), split, (*env)->av[1]);
			else
				(*env)->e = ft_arradd((*env)->e, (*env)->av[1]);
		}
		else
		{
			if (is_env(*env, split[0]) == -1)
				{
					split[0] = ft_strjoin(split[0], "=");
					(*env)->e = ft_arradd((*env)->e, split[0]);
				}		
		}
	else
		ft_putendl("Usage : setenv KEY=VALUE");
}

char **ft_arrdel(char **a, int i)
{
	char **new;
	int j;
	int k;

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

void ft_unsetenv(t_env **env)
{
	int i;

	if (array_size((*env)->av) > 1)
	{
		if ((i = is_env(*env, (*env)->av[1])) != -1)
		{
			(*env)->e = ft_arrdel((*env)->e, i);
		}
	}
	else
		ft_putendl("error");
}
