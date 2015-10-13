/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 15:14:00 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 18:26:31 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*move_up(t_list *l)
{
	t_list *tmp;

	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	if (tmp->id == 0)
		return (ft_gotoend(l));
	tmp->highlighted = 0;
	while (tmp->prev != NULL && tmp->prev->hidden == 1)
		tmp = tmp->prev;
	tmp = (tmp->prev == NULL) ? tmp : tmp->prev;
	tmp->highlighted = 1;
	return (l);
}

static t_list	*move_down(t_list *l)
{
	t_list *tmp;

	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	if (lsearch(l, tmp->id + 1) == NULL)
		return (ft_gotodeb(l));
	tmp->highlighted = 0;
	while (tmp->nxt != NULL && tmp->nxt->hidden == 1)
		tmp = tmp->nxt;
	tmp = (tmp->nxt == NULL) ? tmp : tmp->nxt;
	tmp->highlighted = 1;
	return (l);
}

static t_list	*move_right(t_list *l)
{
	t_list			*tmp;
	t_list			*tmp_;
	int				i;
	struct winsize	w;

	ioctl(2, TIOCGWINSZ, &w);
	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	tmp_ = tmp;
	i = tmp->id;
	while (tmp != NULL && tmp->id != i + (w.ws_row - 1))
		tmp = tmp->nxt;
	if (tmp != NULL)
	{
		tmp_->highlighted = 0;
		tmp->highlighted = 1;
	}
	return (l);
}

static t_list	*move_left(t_list *l)
{
	t_list			*tmp;
	t_list			*tmp_;
	int				i;
	struct winsize	w;

	ioctl(2, TIOCGWINSZ, &w);
	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	tmp_ = tmp;
	i = tmp->id;
	while (tmp != NULL && tmp->id != i - (w.ws_row - 1))
		tmp = tmp->prev;
	if (tmp != NULL)
	{
		tmp_->highlighted = 0;
		tmp->highlighted = 1;
	}
	return (l);
}

t_list			*move_or_quit(t_list *l, char c)
{
	if (c == 0)
	{
		select_close(l, 0);
		exit(0);
	}
	else if (c == 'A')
		l = move_up(l);
	else if (c == 'B')
		l = move_down(l);
	else if (c == 'C')
		l = move_right(l);
	else if (c == 'D')
		l = move_left(l);
	else if (c == 51)
		l = ldel(l);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	print_choices(l);
	print_bar(l);
	return (l);
}
