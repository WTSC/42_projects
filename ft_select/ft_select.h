/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:44:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/03 14:21:10 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <termios.h>
# include <stdlib.h>
# include <curses.h>
# include "libft/libft.h"
# include <sys/ioctl.h>

typedef struct	s_list
{
	char			*name;
	int				selected;
	int				highlighted;
	struct s_list	*nxt;
	struct s_list	*prev;
	struct s_list	*deb;
	struct s_list	*end;
}				t_list;

void print_bar(t_list *l, struct winsize w);
t_list	*add_end(t_list *l, char *name);
int		ft_outc(int c);
int		highlight(char *fleche);
#endif
