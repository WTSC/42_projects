/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lvl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:20:03 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 21:29:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void inc_shlvl(t_env *env)
{
	char	*value;
	int		shlvl;

	if ((value = ft_getenv("SHLVL", env)) != NULL)
	{
		shlvl = ft_atoi(value);
		shlvl++;
		env->av = ft_strsplit(ft_freejoin("setenv SHLVL=", ft_itoa(shlvl), 2), ' ');
		ft_setenv(&env);
		free(env->av);
		env->av = NULL;
	}
	
}
