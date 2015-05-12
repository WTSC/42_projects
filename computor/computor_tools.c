/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 18:33:03 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/12 21:18:40 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

char **computor_organize(char *arg)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(arg, ' ');
	while (ft_strcmp(split[i], "=") != 0)
		i++;
	if (ft_strcmp(split[i + 1], "0") != 0 && split[i + 2] == NULL)
	{
		ft_arradd(split, "0");
		free(split[array_size(split) - 3]);
		split[array_size(split) - 3] = ft_strdup(array_size(split) - 2);
		free(split[array_size(split) - 2]);
		split[array_size(split) - 2] = ft_strdup("=");
	}
}

char *computor_nospaces(char *arg)
{
	char *out;
	int i;
	int j;

	i = 0;
	j = 0;
	out = (char *)malloc(sizeof(char) * ft_strlen(arg));
	while (arg[i] != '\0')
	{
		if (arg[i] > 32)
			out[j++] = arg[i];
		i++;
	}
	out[j + 1] = '\0';
	return (out);
}

char *computor_rewrite(char *arg)
{
	char	*out;
	int		i;
	int		j;
	int		p;

	i = 0;
	j = 0;
	out = (char *)malloc(sizeof(char *) * (ft_strlen(arg) + computor_members(arg)));
	while (arg[i] != '\0')
	{
		if (arg[i] == '^')
			p = 1;
		if ((arg[i] == '+' || arg[i] == '-') && p == 1)
			out[j++] = ' ';
		out[j++] = arg[i++];
		if ((arg[i - 1] == '+' || arg[i - 1] == '-') && p == 1)
		{
			out[j++] = ' ';
			p = 0;
		}
	}
	out[j - 1] = '\0';
	free(arg);
	return (out);
}
