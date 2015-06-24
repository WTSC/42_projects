/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 19:02:38 by jantiope          #+#    #+#             */
/*   Updated: 2015/06/24 15:19:29 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

void	print_sol(int *m, int d);
char	*ft_ftoa(double i);
void	computor_solve(int *m);
void	print_complex(int *m, int d);
int		*computor_sign(char *arg, int *m);
int		*computor_members(char *arg, char sign);
char	*computor_rewrite(char *arg);
char	*computor_nospaces(char *arg);
void	prompt_help(void);
void	computor_check(char *arg);
#endif
