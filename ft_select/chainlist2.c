/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 04:52:13 by jantiope          #+#    #+#             */
/*   Updated: 2015/10/08 17:33:43 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list	*ft_recount(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp != NULL)
	{
		if (tmp->hidden == 0)
			tmp->id = i++;
		tmp = tmp->nxt;
	}
	return (l);
}

t_list	*ft_gotodeb(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	tmp->highlighted = 0;
	tmp = tmp->deb;
	while (tmp != NULL && tmp->hidden == 1)
		tmp = tmp->nxt;
	tmp->highlighted = 1;
	return (l);
}

t_list	*ft_gotoend(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp->highlighted != 1)
		tmp = tmp->nxt;
	tmp->highlighted = 0;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	while (tmp != NULL && tmp->hidden == 1)
		tmp = tmp->prev;
	tmp->highlighted = 1;
	return (l);
}
