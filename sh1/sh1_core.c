#include "libft/libft.h"
#include "ft_sh1.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void ft_env(t_env *env)
{
	ft_putarray(env->e, '\n');
	ft_putchar('\n');
	exit (0);
}

void ft_cd (t_env **env)
{
	char *opwd;

	opwd = ft_strdup((*env)->pwd);
	if (array_size((*env)->av) > 1)
	{
		if (tilde_hyphen(&(*env)) == 1)
		{
			if (chdir((*env)->av[1]) != -1)
				getcwd((*env)->pwd, 1024);
			else
				ft_putendl_fd("cd: No such file or directory", 2);
		}
		else
		{
			ft_putendl_fd("Environment error", 2);
		}
	}
	else if (chdir(ft_getenv("HOME", *env)) != -1)
			getcwd((*env)->pwd, 1024);
		else
			ft_putendl_fd("Error : HOME is not set in the environment", 2);
	update_env(&(*env), "PWD", (*env)->pwd);
	if (ft_strcmp((*env)->pwd, opwd) != 0 && is_env(*env, "OLDPWD") != -1)
		update_env(&(*env), "OLDPWD", opwd);
}

void ft_pwd(t_env *env)
{
	ft_putendl(env->pwd);
	exit (0);
}

void ft_file (t_env *env)
{
	int i;
	char **path;
	char *bin;

	i = is_path(env->av[0], env);
	if (i == -1)
	{
		execve(env->av[0], env->av, env->e);
		ft_putstr("Command not found :");
		ft_putendl(env->av[0]);
	}
	else
	{
		path = ft_strsplit(ft_getenv("PATH", env), ':');
		if (path == NULL)
			exit (0);
		bin = ft_strjoin(path[i], "/");
		bin = ft_freejoin(bin, env->av[0], 1);
		execve(bin, env->av, env->e);
		printf("exec : couldn't run %s (not an executable or access denied)\n", bin);
	}
	exit (0);
}
