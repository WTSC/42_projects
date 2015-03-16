/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:14:41 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/07 04:54:53 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t counter;
	size_t word;
	size_t i;

	i = 0;
	word = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (!word)
		{
			while (s[i] == c)
				i++;
			word = 1;
			counter++;
		}
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			word = 0;
		}
	}
	return (counter);
}

static size_t	ft_splitwords(const char *s, char *split, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
		split[j++] = s[i++];
	split[j] = '\0';
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	split = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	j = 0;
	while (j < ft_wordcount(s, c))
		split[j++] = (char *)malloc(1 + ft_strlen(s) * sizeof(char));
	j = 0;
	while (s[i] != '\0' && j < ft_wordcount(s, c))
	{
		i = ft_splitwords(s, split[j], i, c);
		while (s[i] == c)
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}
