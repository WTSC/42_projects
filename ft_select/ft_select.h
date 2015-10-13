/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:44:23 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 18:30:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <signal.h>
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
	int				hidden;
	struct s_list	*nxt;
	struct s_list	*prev;
	struct s_list	*deb;
	struct s_list	*end;
	struct termios	term;
}					t_list;
t_list				*g_l;

t_list				*lsearch(t_list *l, int value);
t_list				*ldel(t_list *l);
t_list				*ft_recount(t_list *l);
t_list				*ft_gotodeb(t_list *l);
t_list				*ft_gotoend(t_list *l);
int					get_elems(t_list *l);
void				ft_sigstop(void);
void				ft_sigcont(void);
void				ft_sigint(void);
void				ft_sigwinch(void);
void				signal_handler(int sig);
void				resize_if_needed(t_list *l);
int					ft_format(int h, int s);
void				ft_lprint(t_list *l);
t_list				*enter_key(t_list *l);
void				select_close(t_list *l, int print);
t_list				*move_or_quit(t_list *l, char c);
void				print_choices(t_list *l);
void				print_bar(t_list *l);
t_list				*add_end(t_list *l, char *name);
int					ft_outc(int c);
int					highlight(char *name, int m, int h);
#endif
