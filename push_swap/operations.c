#include "push_swap.h"

char **ft_swap(char **p)
{
	char *tmp;
	int i;

	i = array_size(p) - 1;
	tmp = ft_strdup(p[i]);
	free(p[i]);
	p[i] = NULL;
	p[i] = ft_strdup(p[i - 1]);
	free(p[i - 1]);
	p[i - 1] = NULL;	
	p[i - 1] = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (p);	
}


void ft_atob(t_swap *swap)
{
swap->b = ft_insert(swap->a[array_size(swap->a) - 1], swap->b, 1);
swap->a = ft_delete(swap->a, 1);
}

void ft_btoa(t_swap *swap)
{
	swap->a = ft_insert(swap->b[array_size(swap->b) - 1], swap->a, 1);
	swap->b = ft_delete(swap->b, 1);
}

char **ft_rot(char **p)
{
	char *s;
	int i;

	i = array_size(p) - 1;
	s = ft_strdup(p[i]);
	p = ft_delete(p, 1);
	p = ft_insert(s, p, 0);
	free(s);
	return (p);
}

char **ft_rrot(char **p)
{
	char *s;

	s = ft_strdup(p[0]);
	p = ft_delete(p, 0);
	p = ft_insert(s, p, 1);
	free(s);
	return (p);
}
