#include "push_swap.h"

char **ft_switch(char **s1, char **s2, int i)
{
	char *tmp;

	if (*s1 != NULL)
	{
		tmp = ft_strdup(*s1);
		free(*s1);
		*s1 = NULL;
	}
	else
		tmp = ft_strdup(s2[0]);
	*s1 = ft_strdup(s2[i]);
	free(s2[i]);
	s2[i] = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (s2);
}

char **ft_insert(char *s, char **p, int type)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = (type == 1) ? array_size(p) : 1;
	if (type == 1)
	{
		p[i] = ft_strdup(s);
	}
	else
	{
		while (p[i] != NULL)
		{
			p = ft_switch(&tmp, p, i);
			i++;
		}
		p[i] = ft_strdup(tmp);
		free(p[0]);
		p[0] = ft_strdup(s);
	}
	return (p);
}

char **ft_delete(char **p, int type)
{
	int	i;

	i = (type == 1) ? array_size(p) - 1 : 0;
	if (type == 1)
	{
		free(p[i]);
		p[i] = NULL;
	}
	else
	{
		while (p[i + 1] != NULL)
		{		
			free(p[i]);
			p[i] = ft_strdup(p[i + 1]);
			i++;
		}
		free(p[i]);
		p[i] = NULL;
	}
	return (p);
}
