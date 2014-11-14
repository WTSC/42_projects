/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:18:17 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/06 23:01:22 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *join;

	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
