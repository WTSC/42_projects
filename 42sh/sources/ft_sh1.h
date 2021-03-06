/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:36:08 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 21:29:47 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include "../libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <time.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char **e;
	char **ev;
	char *pwd;
	char *user;
	char **av;
	char *test;
	char *protected;
}				t_env;

void			inc_shlvl(t_env *env);
void			write_env(t_env *env);
char			*select_home(char *pwd);
char			**ft_arradd(char **a1, char *a2);
int				unsetenv_check(char *key, t_env *env);
void			print_time(t_env *env);
int				setenv_check(char **args);
void			ft_replaceenv(t_env **env, char **split, char *newenv);
int				is_builtin(char *line, t_env **env);
void			ft_prompt(t_env *env);
void			ft_clear(void);
int				tilde_hyphen(t_env **env);
int				is_multi(char *line, t_env **env);
void			update_env(t_env **env, char *key, char *value);
pid_t			sh_fork(void);
int				is_path(char *cmd, t_env *env);
char			*ft_getenv(char *key, t_env *env);
void			ft_parse(t_env *env, char **line);
void			ft_env(t_env *env);
void			ft_exit(t_env *env);
void			ft_cd(t_env **env);
void			ft_file(t_env *env);
int				is_env(t_env *env, char *s);
void			ft_pwd(t_env *env);
void			display_prompt(t_env *env);
void			ft_setenv(t_env **env);
void			ft_unsetenv(t_env **env);
#endif
