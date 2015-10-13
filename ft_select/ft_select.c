/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:30:51 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 18:29:28 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*fill_list(t_list *l, char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		l = add_end(l, argv[i]);
		i++;
	}
	return (l);
}

static int		ft_select(t_list *l)
{
	char buffer[3];

	buffer[0] = '\0';
	print_choices(l);
	print_bar(l);
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			move_or_quit(l, buffer[2]);
		else if (ft_strchr(buffer, 4) != NULL)
			return (0);
		else if (buffer[0] == ' ')
			l = enter_key(l);
		else if (buffer[0] == '\n')
			return (0);
		ft_bzero(buffer, 3);
	}
	return (0);
}

static void		go_canonical(void)
{
	tcgetattr(0, &(g_l->term));
	g_l->term.c_lflag &= ~(ICANON | ECHO);
	g_l->term.c_cc[VMIN] = 1;
	g_l->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(g_l->term));
	tputs(tgetstr("ti", NULL), 1, ft_outc);
	tputs(tgetstr("vi", NULL), 1, ft_outc);
}

void			select_close(t_list *l, int print)
{
	tcgetattr(0, &(l->term));
	l->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(l->term));
	tputs(tgetstr("te", NULL), 1, ft_outc);
	tputs(tgetstr("ve", NULL), 1, ft_outc);
	tputs(tgetstr("me", NULL), 1, ft_outc);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	if (print)
		ft_lprint(l);
}

int				main(int argc, char **argv)
{
	char			*name_term;
	struct winsize	w;

	g_l = NULL;
	signal(SIGWINCH, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGCONT, signal_handler);
	ioctl(2, TIOCGWINSZ, &w);
	if (w.ws_col < 4 || argc <= 2)
		return (-1);
	g_l = fill_list(g_l, argv);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	go_canonical();
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	ft_select(g_l);
	select_close(g_l, 1);
	return (0);
}
