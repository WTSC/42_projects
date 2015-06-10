/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 11:48:32 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/10 15:02:49 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_elems(t_list *l)
{
	struct	winsize  s;
	t_list	*tmp;
	int		i;

	tmp = l;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	i = tmp->id + 1;
	return (i);
}

void resize(t_list *l)
{
	struct winsize  s;
	static int      h;
	static int      w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &s);
	if (h != s.ws_row || w != s.ws_col)
	{
		h = s.ws_row;
		w = s.ws_col;
		tputs(tgetstr("cl", NULL), 1, ft_outc);
		print_choices(l);
		print_bar(l);
	}
}

void signal_handler(int sig)
{
	struct winsize  s;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &s);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	if (get_elems(l) > (s.ws_row - 1) * (s.ws_col / 15))
		ft_putstr("Window too small");
	else
	{
		print_choices(l);
		print_bar(l);
	}
}

int ft_format(int h, int s)
{
	int i;

	i = 0;
	if (h)
		i += 1;
	if (s)
		i += 2;
	return (i);
}
