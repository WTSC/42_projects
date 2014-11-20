/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:10:40 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 07:55:54 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_ls.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_get_flags(const char **args)
{
	size_t i;
    size_t j;
	size_t k;
	char *flags;

    j = 1;
	k = 0;
	flags = (char *)malloc(sizeof(char) * 10);
    while (args[j] != NULL && args[j][0] == '-' && args[j][1])
    {
		i = 1;
        while (args[j][i])
            flags[k++] = args[j][i++];
		j++;
	}
	flags[k] = '\0';
	return (flags);
}

int ft_check_flag(const char **args, int nb)
{
	char flag[2];
	size_t i;
	int j;

	i = 1;
	j = 1;
	while (j < nb && args[j][0] == '-' && args[j][1])
    {
        while (i < ft_strlen(args[j]))
        {
			if (ft_strchr("atrlR", args[j][i]) == NULL)
			{
				flag[0] = args[j][i];
				flag[1] = '\0';
				ft_perror(ILLEGAL, flag);
			}
			i++;
        }
		i = 1;
        j++;
    }
	if (args[j])
		return (1);
	else
		return (2);
}

char *ft_get_folder(const char **args)
{
	size_t i;

	i = 1;
	while (args[i][0] == '-')
		i++;
	return ((char *)args[i]);
}
