/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 04:33:31 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 07:23:31 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft/includes/libft.h"
#include "ft_ls.h"

char **ft_arrev(char **copy, int size)
{
	char **copycopy;
	int i;
	int j;

	i = 0;
	j = size - 1;
	copycopy = (char **)malloc(sizeof(char *) * size);
	while (i < size)
		copycopy[i++] = ft_strdup(copy[j--]);
	return (copycopy);
}

char *ft_mallcat(char **s1, const char *s2)
{
	char *tmp;
	
	tmp = ft_strdup(*s1);
	if(!tmp)
	return (NULL);
	*s1 = NULL;
	free(*s1);
		printf("s\n");
	*s1 = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(tmp) + 1));
	if (!(*s1))
		return (NULL);	
	*s1 = ft_strcpy(*s1, tmp);
	*s1 = ft_strcat(*s1, s2);
	tmp = NULL;	
	free(tmp);
	return (*s1);
}
