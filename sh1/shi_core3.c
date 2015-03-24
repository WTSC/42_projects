#include "ft_sh1.h"

void update_env(t_env **env, char *key, char *value)
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

int tilde_hyphen(t_env **env)
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

void	ft_clear(void)
{
	ft_putstr("\033[1;1H\033[2J");
	exit (0);
}

void	ft_prompt(t_env *env)
{
	ft_putstr("[ ");
	ft_putstr(env->pwd);
	ft_putstr(" ] %>");
}
