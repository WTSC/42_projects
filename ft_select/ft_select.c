/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:30:51 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/03 14:33:09 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list *fill_list(t_list *l, char **argv)
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

static int     ft_select(t_list *l, struct winsize w)
{
	char     buffer[3];
	print_choices(l, w);
	print_bar(l, w);
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			highlight("fleeecheeee", 3);
		else if (ft_strchr(buffer, 4) != NULL)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

void go_canonical()
{
	struct termios *term;
	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	tputs(tgetstr("ti", NULL), 1, ft_outc);
	tputs(tgetstr("vi", NULL), 1, ft_outc);
}

void	select_close(void)
{
	struct termios *term;
term = (struct termios*)malloc(sizeof(struct termios));
tcgetattr(0, term);
term->c_lflag |= (ICANON | ECHO);
tcsetattr(0, 0, term);
tputs(tgetstr("cl", NULL), 1, ft_outc);
tputs(tgetstr("te", NULL), 1, ft_outc);
tputs(tgetstr("ve", NULL), 1, ft_outc);
tputs(tgetstr("me", NULL), 1, ft_outc);
}

int              main(int argc, char **argv, char **env)
{
	char			*name_term;
	struct termios	term;
	struct winsize	w;
	t_list			*l;

	(void)env;
	l = NULL;
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col < 4 || argc < 2)
		return (-1);
	l = fill_list(l, argv);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	go_canonical();
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	ft_select(l, w);
  	select_close();
	return (0);
}
