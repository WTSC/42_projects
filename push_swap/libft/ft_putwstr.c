/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:27:59 by jantiope          #+#    #+#             */
/*   Updated: 2014/12/25 23:28:01 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include "libft.h"

void ft_putwstr(const wchar_t *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		ft_putwchar(s[i++]);
}
