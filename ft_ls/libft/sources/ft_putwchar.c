/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 18:26:22 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/27 10:08:11 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "../includes/libft.h"

void	putwchar_print(char **split)
{
	int i;
	int dec;

	i = 0;
	while (split[i])
	{
		dec = ft_tobase10(split[i], 2);
		write(1, &dec, 1);
		i++;
	}
}

char	**putwchar_fill(char *mask, char *bin)
{
	int i;
	int j;

	j = ft_strlen(bin);
	i = ft_strlen(mask);
	i--;
	j--;
	while (i != -1 && j != -1)
	{
		if (mask[i] == 'x')
			mask[i] = bin[j--];
		i--;
	}
	if (i != -1)
		while (i != -1)
		{
			if (mask[i] == 'x')
				mask[i] = '0';
			i--;
		}
	return (ft_strsplit(mask, ' '));
}

void	ft_putwchar(wchar_t c)
{
	char	*bin;
	char	*mask;
	char	**split;
	int		len;

	bin = ft_base(c, 2);
	len = ft_strlen(bin);
	if (len <= 7)
		ft_putchar((char)c);
	else
	{
		if (len <= 11)
			mask = ft_strdup("110xxxxx 10xxxxxx");
		else if (len <= 16)
			mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		else
			mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		split = putwchar_fill(mask, bin);
		putwchar_print(split);
	}
}
