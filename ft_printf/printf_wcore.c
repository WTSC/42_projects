/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wcore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:47:48 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:00:20 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

int		ft_wcharbyte(wchar_t c)
{
	char	*bin;
	int		len;

	bin = ft_base(c, 2);
	len = ft_strlen(bin);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	else
		return (4);
}

int		ft_wstrbyte(wchar_t *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
		count += ft_wcharbyte(s[i++]);
	return (count);
}

int		ft_putwcount(int type, wchar_t *s)
{
	static int	c;
	int			c_;

	c_ = c;
	if (type == 1)
		c++;
	if (type == 0)
	{
		c += ft_wstrbyte(s);
		ft_putwstr(s);
	}
	if (type == -1)
		c = 0;
	return ((type == -1) ? c_ : c);
}

void	char_putwcount(wchar_t c)
{
	wchar_t *s;

	if (c == 0)
		ft_putwcount(1, NULL);
	else
	{
		s = (wchar_t *)malloc(sizeof(char) * 2);
		s[0] = c;
		s[1] = '\0';
		ft_putwcount(0, s);
		free(s);
		s = NULL;
	}
}
