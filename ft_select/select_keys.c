/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:46:00 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 17:33:04 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list	*enter_key(t_list *l)
{
	t_list *tmp;

	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	tmp->selected = (tmp->selected == 1) ? 0 : 1;
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	print_choices(l);
	print_bar(l);
	return (l);
}
