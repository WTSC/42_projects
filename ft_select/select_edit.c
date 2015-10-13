/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 11:48:32 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 18:26:02 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_elems(t_list *l)
{
	t_list	*tmp;
	int		i;

	tmp = l;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	i = tmp->id + 1;
	return (i);
}

void	resize(t_list *l)
{
	struct winsize	s;
	static int		h;
	static int		w;

	ioctl(2, TIOCGWINSZ, &s);
	if (h != s.ws_row || w != s.ws_col)
	{
		h = s.ws_row;
		w = s.ws_col;
		tputs(tgetstr("cl", NULL), 1, ft_outc);
		print_choices(l);
		print_bar(l);
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		ft_sigwinch();
	if (sig == SIGSTOP)
		ft_sigstop();
	if (sig == SIGCONT)
		ft_sigcont();
	if (sig == SIGINT)
		ft_sigint();
}

int		ft_format(int h, int s)
{
	int i;

	i = 0;
	if (h)
		i += 1;
	if (s)
		i += 2;
	return (i);
}
