#include "push_swap.h"

void		no_doubles(char **a)
{
	int i;
	int j;

	i = 0;
	while (a[i] != NULL)
	{
		is_valid(a[i]);
		j = i + 1;
		while (a[j] != NULL)
		{
			if (ft_strcmp(a[i], a[j]) == 0)
			{
				ft_putendl_fd("Error : You can't use multiple numbers of the same value", 2);
				exit (1);
			}
			j++;
		}
	i++;
	}
}

int		is_sorted(char **a)
{
	int	i;
	int	x;
	int	x2;

	i = 0;
	x = 0;
	while (a[i + 1] != NULL)
	{
		x2 = ft_atoi(a[i]);
		x =  ft_atoi(a[i + 1]);
		if (x2 <= x)
			return (0);
		i++;
	}
	return (1);
}

char *ft_max(char **p)
{
	int	i;
	char	*max;

	if (p[0] == NULL)
		return (NULL);
	i = 1;
	max = (char *)malloc(sizeof(char) * 21);
	ft_strcpy(max, p[0]);
	while (p[i] != NULL)
	{
		if (ft_nbrcmp(max, p[i]) < 0)
		{
			ft_strcpy(max, p[i]);
		}
		i++;
	}
	return (max);
}

char *ft_min(char **p)
{
	int	i;
	char	*min;

	if (p[0] == NULL)
		return (NULL);
	i = 1;
	min = (char *)malloc(sizeof(char) * 21);
	ft_strcpy(min, p[0]);
	while (p[i] != NULL)
	{
		if (ft_nbrcmp(min, p[i]) > 0)
		{
			ft_strcpy(min, p[i]);
		}
		i++;
	}
	return (min);
}

void 	display_if_needed(t_swap swap, int change)
{
	if (swap.verbose == 1 && change == 1)
	{
		ft_putstr("Pile A : ");
		ft_putarray((swap.verbose == 1) ? swap.a : NULL, ' ');
		ft_putstr("Pile B : ");
		ft_putarray((swap.verbose == 1) ? swap.b : NULL, ' ');
	}	
}
