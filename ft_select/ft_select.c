/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:30:51 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/27 20:43:05 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_select.h"
#include <stdio.h>
#include <unistd.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <curses.h>
#include "libft/libft.h"
#include <sys/ioctl.h>

int ft_outc(int c)
{
	write(1, &c, 1);
	return (0);
}

int highlight(char *fleche)
{
	char    *res;

	tputs(tgetstr("us", NULL), 1, ft_outc);
	tputs(tgetstr("mr", NULL), 1, ft_outc);
	ft_putstr_fd(fleche, 2);
	tputs(tgetstr("me", NULL), 1, ft_outc);
	return (1);
}


int     voir_touche()
{
	char     buffer[3];
 
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

int              main(int ac, char **av, char **env)
{
	char			*name_term;
	struct termios	term;

	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
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
	voir_touche();
    if (tcgetattr(0, &term) == -1)
        return (-1);
    term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}
