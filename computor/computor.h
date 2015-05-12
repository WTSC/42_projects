/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 19:02:38 by jantiope          #+#    #+#             */
/*   Updated: 2015/05/12 20:15:49 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

int		computor_members(char *arg);
char	*computor_rewrite(char *arg);
char	*computor_nospaces(char *arg);
void	prompt_help(void);
void	computor_check(char *arg);
#endif
