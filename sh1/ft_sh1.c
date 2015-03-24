#include "ft_sh1.h"

void print_time(void)
{
	time_t time;
	ctime(&time);
	
}

void fill_struct(t_env *env, char **e)
{
	env->e = ft_arrdup(e);
	env->user = ft_strdup("WTSC");
	env->pwd = (char *)malloc(sizeof(char) * 1024); 	
	getcwd(env->pwd, 1024);
}

int is_builtin(char *line, t_env **env)
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
		exit (0);
		return (1);	
	}
	else
		return (0);
}

void display_prompt(t_env *env)
{
	char *line;
	pid_t papa;

	ft_putstr("\033[1;1H\033[2J");
	ft_prompt(env);
	while (42)
	{
		if (get_next_line(0, &line) > 0)
		{

			line = ft_strtrim(line);
			line = ft_supertrim(line);
			if (is_multi(line, &env) == 0 && is_builtin(line, &env) == 0)
			{
				papa = sh_fork();
				if (papa == 0)
					ft_parse(env, &line);
				else
					wait(0);
			}
			free(line);
			line = NULL;
			ft_prompt(env);
		}
	}
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	t_env e;
	fill_struct(&e, env);
	display_prompt(&e);
	return (0);
}
