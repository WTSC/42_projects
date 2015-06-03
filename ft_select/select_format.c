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

int highlight(char *fleche)
{
    tputs(tgetstr("us", NULL), 1, ft_outc);
    tputs(tgetstr("mr", NULL), 1, ft_outc);
    ft_putstr_fd(fleche, 2);
    tputs(tgetstr("me", NULL), 1, ft_outc);
    return (1);
}

void print_bar(t_list *l, struct winsize w)
{
	int i;

	i = ft_strlen(l->name);
	tputs(tgetstr("mr", NULL), 1, ft_outc);
	ft_putstr_fd(l->name, 2);
	while (i < w.ws_col)
	{
		write(2, " ", 1);
		i++;
	}
}
