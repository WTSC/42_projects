#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct		s_swap
{
	int		verbose;
	int		change;
	char		**a;
	char		**b;
	char		*bmax;
	char		*amin;
	char		*moves;
}					t_swap;

t_swap swap_sort(t_swap swap);
char	**ft_swap(char **p);
void	no_doubles(char **argv);
int	is_sorted(char **argv);
char **ft_delete(char **p, int type);
char **ft_insert(char *s, char **p, int type);
void	swap_flags(char **argv, t_swap *swap);
void ft_atob(t_swap *swap);
void ft_btoa(t_swap *swap);
char **ft_rot(char **p);
char **ft_rrot(char **p);
char *ft_min(char **p);
char *ft_max(char **p);
void 	display_if_needed(t_swap swap, int change);
void	is_valid(char *n);

#endif
