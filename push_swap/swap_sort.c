#include "push_swap.h"

void update_move(t_swap **swap, char *move)
{
	int i;

	i = ft_strlen((*swap)->moves) - 1;
	while ((*swap)->moves[i - 1] != ' ')
		i--;
	if (ft_strcmp(&(*swap)->moves[i], move) == -1)
	{
		while ((*swap)->moves[i + 1] != ' ')
			i++;
		(*swap)->moves[i] = move[0];
	}
	else
		(*swap)->moves = ft_freejoin((*swap)->moves, move, 1);
	ft_putendl(((*swap)->verbose == 1) ? move : NULL);
}

void pile_b(t_swap *swap)
{
	swap->change = 0;
	if (array_size(swap->b) > 1)
	{
	  if (ft_nbrcmp(swap->b[array_size(swap->b) - 1], swap->b[array_size(swap->b) - 2]) < 0)
	    {
		update_move(&swap, "sb ");
	      swap->change = 1;
	      swap->b = ft_swap(swap->b);
	    }
	  else if (ft_nbrcmp(swap->b[0],  swap->bmax) == 0)
	    {
		update_move(&swap, "rrb ");
		ft_putendl((swap->verbose == 1) ? "rrb" : NULL);
	      swap->change = 1;
	      swap->b = ft_rrot(swap->b);
	    }
	  else if (ft_nbrcmp(swap->b[0], swap->b[array_size(swap->b) - 1]) > 0)
	    {
		update_move(&swap, "rb ");
				ft_putendl((swap->verbose == 1) ? "rb" : NULL);
	      swap->change = 1;
	      swap->b = ft_rot(swap->b);
	    }
	}
}

void pile_a(t_swap *swap)
{
	swap->change = 0;
	if (array_size(swap->a) > 1)
	{
		if (ft_nbrcmp(swap->a[array_size(swap->a) - 1], swap->a[array_size(swap->a) - 2]) > 0)
  		{
			swap->moves = ft_freejoin(swap->moves, "sa ", 1);
			ft_putendl((swap->verbose == 1) ? "sa" : NULL);
			swap->change = 1;
			swap->a = ft_swap(swap->a);
		}
  		else if (ft_nbrcmp(swap->a[0], swap->amin) == 0)
		{
			swap->moves = ft_freejoin(swap->moves, "rra ", 1);
			ft_putendl((swap->verbose == 1) ? "rra" : NULL);
			swap->change = 1;
			swap->a = ft_rrot(swap->a);
		}
		else if (ft_nbrcmp(swap->a[0], swap->a[array_size(swap->a) - 1]) < 0)
		{
			swap->moves = ft_freejoin(swap->moves, "ra ", 1);
			ft_putendl((swap->verbose == 1) ? "ra" : NULL);
			swap->change = 1;
			swap->a = ft_rot(swap->a);
		}
	}
}

t_swap swap_sort(t_swap swap)
{
	int i = 0;
	while ((!is_sorted(swap.a) || swap.b[0] != NULL) && i != 100)
	{
		swap.amin = ft_min(swap.a);
		pile_a(&swap);
		display_if_needed(swap, swap.change);
		if (swap.change == 0 && !is_sorted(swap.a))
		{
			swap.moves = ft_freejoin(swap.moves, "pb ", 1);
			ft_putendl((swap.verbose == 1) ? "pb" : NULL);
		    	ft_atob(&swap);
			display_if_needed(swap, 1);
		}		
		swap.bmax = ft_max(swap.b);
		pile_b(&swap);
		display_if_needed(swap, swap.change);
       		if ((swap.change == 1 && ft_nbrcmp(swap.b[0], swap.a[0]) < 0) || (swap.change == 0 && is_sorted(swap.a) && swap.b[0] != NULL))
		{
			swap.moves = ft_freejoin(swap.moves, "pa ", 1);
			ft_putendl((swap.verbose == 1) ? "pa" : NULL);
			ft_btoa(&swap);
			display_if_needed(swap, 1);
		}
		i++;
	}
	return (swap);
}
