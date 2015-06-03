/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 13:13:41 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/03 14:29:40 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list *add_end(t_list *l, char *name)
{
	t_list *new = (t_list *)malloc(sizeof(t_list));
	t_list *temp = l;

    new->name = ft_strdup(name);
	new->highlighted = 0;
	new->selected = 0;
	new->nxt = NULL;
    if (l == NULL)
	{
		new->highlighted = 1;
		new->deb = new;
		new->prev = new->end;
		return (new);
	}
    else
    {
	new->deb = temp;
        while (temp->nxt != NULL)
        {
		temp->end = new;
            temp = temp->nxt;
        }
		new->prev = temp;
		temp->nxt = new;
		return (l);
    }
}
