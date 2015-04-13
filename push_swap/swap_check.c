#include "push_swap.h"

int	count_char(char *s, char c)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			m++;
		i++;
	}
	return (m);
}

void	swap_flags(char **argv, t_swap *swap)
{
	if (ft_strcmp(argv[1], "-v") == 0)
		swap->verbose = 1;
	else if (!ft_isdigit(argv[1][0]))
	{
		ft_putendl_fd("Error : invalid number or flag", 2);
		exit (1);
	}
}

void	is_valid(char *n)
{
	int i;

	if (id_chr(n, '-') > 0 || count_char(n, '-') > 1)
	{
		ft_putstr_fd("Error : Invalid number: ", 2);
		ft_putendl_fd(n, 2);
		exit (1);
	}
	if (ft_strlen(n) > 20)
	{
		ft_putstr_fd("Error : Number too long: ", 2);
		ft_putendl_fd(n, 2);
		exit (1);
	}
	i = 0;
	while (n[i] != '\0')
	{
		if (ft_strchr( "0123456789-", n[i]) == NULL)
		{
			ft_putstr_fd("Error : This is not a number: ", 2);
			ft_putchar_fd(n[i], 2);
			ft_putchar_fd('\n', 2);
			exit (1);
		}
		i++;
	}
}
