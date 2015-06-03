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
	print_bar(l, w);
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			highlight("fleeecheeee");
		else if (ft_strchr(buffer, 4) != NULL)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

static void go_canonical(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

int              main(int argc, char **argv, char **env)
{
	char			*name_term;
	struct termios	term;
	struct winsize	w;
	t_list			*l;

	(void)argc;
	(void)env;
	l = NULL;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
	l = fill_list(l, argv);
	go_canonical(&term);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	tputs(tgoto(tgetstr("cm", NULL), 0, w.ws_row), 1, ft_outc);
	ft_select(l, w);
    if (tcgetattr(0, &term) == -1)
        return (-1);
    term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	printf("%s\n", l->name);
	return (0);
}
