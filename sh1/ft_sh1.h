#ifndef FT_SH_H
# define FT_SH_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>


typedef struct s_env
{
	char **e;
	char **ev;
	char *pwd;
	char *user;
	char **av;
	char *test;
}				t_env;

void	ft_prompt(t_env *env);
void	ft_clear(void);
int tilde_hyphen(t_env **env);
int is_multi(char *line, t_env **env);
void update_env(t_env **env, char *key, char *value);
pid_t	sh_fork(void);
int is_path(char *cmd, t_env *env);
char	*ft_getenv(char *key, t_env *env);
void	ft_parse(t_env *env, char **line);
void	ft_env(t_env *env);
void	ft_exit(t_env *env);
void	ft_cd(t_env **env);
void	ft_file(t_env *env);
int	is_env(t_env *env, char *s);
void	ft_pwd(t_env *env);
void	display_prompt(t_env *env);
void	ft_setenv(t_env **env);
void ft_unsetenv(t_env **env);
#endif
