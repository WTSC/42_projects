
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:24:22 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 21:19:34 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

void	print_time(t_env *env)
{
	time_t		raw;
	char		**split;

	time(&raw);
	split = ft_strsplit(ctime(&raw), ' ');
	ft_putchar('[');
	ft_putstr(ft_getenv("PWD", env));
	ft_putstr("] ");
	ft_putchar('[');
	ft_putstr(split[3]);
	ft_putstr("] > ");
	free(split);
}

void	fill_struct(t_env *env, char **e)
{
	env->e = NULL;
	env->pwd = (char *)malloc(sizeof(char) * 1024);
	getcwd(env->pwd, 1024);
	if (e[0] == NULL)
	{
		env->e = ft_arradd(env->e, "SHLVL=1");
		env->e = ft_arradd(env->e, ft_strjoin("PWD=", env->pwd));
		env->e = ft_arradd(env->e, "OLDPWD=");
		env->e = ft_arradd(env->e, ft_strjoin("HOME=", select_home(env->pwd)));
	}
	else
	{
		env->e = ft_arrdup(e);
		inc_shlvl(env);
	}
	env->protected = ft_strdup("OLDPWD,PWD,SHLVL,HOME,LOGNAME");
}

int		is_builtin(char *line, t_env **env)
{
	(*env)->av = ft_strsplit(line, ' ');
	if (ft_strcmp(ft_strtolower((*env)->av[0]), "setenv") == 0)
	{
		ft_setenv(&(*env));
		return (1);
	}
	else if (ft_strcmp(ft_strtolower((*env)->av[0]), "unsetenv") == 0)
	{
		ft_unsetenv(&(*env));
		return (1);
	}
	else if (ft_strcmp(ft_strtolower((*env)->av[0]), "cd") == 0)
	{
		ft_cd(&(*env));
		return (1);
	}
	else if (ft_strcmp(ft_strtolower((*env)->av[0]), "exit") == 0)
	{
		exit(0);
		return (1);
	}
	else
		return (0);
}

void	display_prompt(t_env *env)
{
	char	*line;
	pid_t	papa;

	while (42)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (ft_strcmp(ft_strtrim(line), "") != 0)
			{
				line = ft_strtrim(line);
				if (line && is_multi(line, &env) == 0
					&& is_builtin(line, &env) == 0)
				{
					papa = sh_fork();
					if (papa == 0)
						ft_parse(env, &line);
					else
						wait(0);
				}
			}
			free(line);
			line = NULL;
			ft_prompt(env);
		}
	}
}

int		main(int argc, char **argv, char **env)
{
	t_env e;

	(void)argc;
	(void)argv;
	fill_struct(&e, env);
	print_time(&e);
	ft_putstr("\033[1;1H\033[2J");
	ft_prompt(&e);
	display_prompt(&e);
	return (0);
}
