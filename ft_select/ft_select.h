/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:44:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/10 14:38:06 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <termios.h>
# include <stdlib.h>
# include <curses.h>
# include "libft/libft.h"
# include <sys/ioctl.h>

typedef struct		s_list
{
	char			*name;
	int				tty;
	int				selected;
	int				highlighted;
	int				id;
	struct s_list	*nxt;
	struct s_list	*prev;
	struct s_list	*deb;
	struct s_list	*end;
}					t_list;
t_list				*l;

void				signal_handler(int sig);
void				resize_if_needed(t_list *l);
int					ft_format(int h, int s);
void				ft_lprint(t_list *l);
t_list				*enter_key(t_list *l);
void				select_close(t_list *l);
t_list				*move_or_quit(t_list *l, char c);
void				print_choices(t_list *l);
void				print_bar(t_list *l);
t_list				*add_end(t_list *l, char *name);
int					ft_outc(int c);
int					highlight(char *name, int m);
#endif
