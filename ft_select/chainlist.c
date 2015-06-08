/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 13:13:41 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/08 18:14:09 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_lprint(t_list *l)
{
	while (l != NULL)
	{
		if (l->selected)
		{
			ft_putstr(l->name);
			if (l->nxt != NULL)
				ft_putchar(' ');
		}
		l = l->nxt;
	}
	ft_putchar('\n');
}

t_list	*lsearch(t_list *l, int value)
{
	t_list	*tmp;

	tmp = l;
	while (tmp != NULL)
	{
		if (tmp->id == value)
			return (tmp);
		else
			tmp = tmp->nxt;
	}
	return (NULL);
}

t_list	*add_end(t_list *l, char *name)
{
	t_list	*new;
	t_list	*temp;
	int		i;

	i = 0;
	temp = l;
	new = (t_list *)malloc(sizeof(t_list));
	new->name = ft_strdup(name);
	new->highlighted = 0;
	new->selected = 0;
	new->nxt = NULL;
	if (l == NULL)
	{
		new->highlighted = 1;
		new->deb = new;
		new->prev = NULL;
		new->id = 0;
		return (new);
	}
	else
	{
		new->deb = temp;
		while (temp->nxt != NULL)
		{
			i++;
			temp->end = new;
			temp = temp->nxt;
		}
		i++;
		new->id = i;
		new->prev = temp;
		temp->nxt = new;
		return (l);
	}
}
