/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:49:21 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/03 14:22:25 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int ft_outc(int c)
{
    write(1, &c, 1);
    return (0);
}

int highlight(char *name, int m)
{
	if (m == 2 || m == 3)
	    tputs(tgetstr("us", NULL), 1, ft_outc);
	if (m == 1 || m == 3)
	    tputs(tgetstr("mr", NULL), 1, ft_outc);
    ft_putstr_fd(name, 2);
    tputs(tgetstr("me", NULL), 1, ft_outc);
    return (1);
}

char *ft_truncate(char *s, int m, struct winsize w)
{
	if (m > w.ws_col)
		m = w.ws_col;
	if (ft_strlen(s) <= m)
		return (s);
	s[m] = '\0';
	s[m - 1] = '.';
	s[m - 2] = '.';
	s[m - 3] = '.';
	return(s);
}

void print_choices(t_list *l, struct winsize w)
{
	int format;
	int i;
	char *print;

	i = 0;
	while (l != NULL)
	{
		print = ft_strdup(l->name);
		format = 0;
		if (l->highlighted)
			format += 1;
		if (l->selected)
			format += 2;
		highlight(ft_truncate(print, 12, w), format);
		write(2, "\n", 1);
		l = l->nxt;
		free(print);
		print = NULL;
		i++;
		tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, ft_outc);	
	}
}

void print_bar(t_list *l, struct winsize w)
{
	int i;
	char *print;

	print = ft_strdup(l->name);
	print = ft_truncate(print, w.ws_col, w);
	i = ft_strlen(l->name);
	tputs(tgoto(tgetstr("cm", NULL), 0, w.ws_row), 1, ft_outc);	
	tputs(tgetstr("mr", NULL), 1, ft_outc);
	ft_putstr_fd(print, 2);
	while (i < w.ws_col)
	{
		write(2, " ", 1);
		i++;
	}
    tputs(tgetstr("me", NULL), 1, ft_outc);
}
