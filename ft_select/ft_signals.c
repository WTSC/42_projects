/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 03:19:00 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 18:33:13 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_sigwinch(void)
{
	struct winsize	s;

	ioctl(2, TIOCGWINSZ, &s);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	if (get_elems(g_l) > (s.ws_row - 1) * (s.ws_col / 15))
		ft_putstr_fd("Window too small", 2);
	else
	{
		print_choices(g_l);
		print_bar(g_l);
	}
}

void	ft_sigstop(void)
{
	char c[2];

	c[0] = g_l->term.c_cc[VSUSP];
	c[1] = 0;
	g_l->term.c_lflag |= (ICANON | ECHO);
	signal(SIGSTOP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	tcsetattr(0, 0, &(g_l->term));
	tputs(tgetstr("te", NULL), 1, ft_outc);
	tputs(tgetstr("ve", NULL), 1, ft_outc);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	ioctl(0, TIOCSTI, c);
}

void	ft_sigcont(void)
{
	g_l->term.c_lflag &= ~(ICANON | ECHO);
	g_l->term.c_cc[VMIN] = 1;
	g_l->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(g_l->term));
	tputs(tgetstr("ti", NULL), 1, ft_outc);
	tputs(tgetstr("vi", NULL), 1, ft_outc);
	signal(SIGSTOP, signal_handler);
	ft_sigwinch();
}

void	ft_sigint(void)
{
	select_close(g_l, 0);
	exit(0);
}
