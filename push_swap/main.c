#include "push_swap.h"

void ft_countmoves(char *moves)
{
	int i;
	int m;

	m = 0;
	i = 0;
	while (moves[i] != '\0')
	{
		if (moves[i] == ' ')
			m++;
		i++;
	}
	ft_putstr("Total : ");
	ft_putnbr(m);
	ft_putendl((m == 1) ? " move." : " moves.");
}

char **ft_arrzero(char **a, int l)
{
  int i;

  i = 0;
  while (i < l)
    a[i++] = NULL;
  return (a);
}

int		main(int argc, char **argv)
{
	t_swap swap;

	if (argc == 1)
		return (1);
	swap.a = ft_arrdup(argv);
	swap.a = ft_delete(swap.a, 0);
	swap_flags(argv, &swap);
	if (swap.verbose == 1)
		swap.a = ft_delete(swap.a, 0);
	no_doubles(swap.a);
	if (is_sorted(swap.a))
	{
		ft_putendl("Nothing to do. Exiting...");
		return (1);
	}
	swap.b = (char **)malloc(sizeof(char *) * argc);
	ft_arrzero(swap.b, argc);
	swap.moves = ft_strnew(1);
	swap = swap_sort(swap);
	ft_putstr("Result : ");
        ft_putendl(swap.moves);
	ft_countmoves(swap.moves);
	return (0);
}
