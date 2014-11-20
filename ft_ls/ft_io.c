/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:27:54 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 08:18:46 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <string.h>

void ft_file_info(char **filelist, char *file, const char **args, int nb)
{
	ft_get_permissions(&(*filelist), file);
	ft_get_links(&(*filelist), file);
	ft_get_uid_gid(&(*filelist), file);
	ft_get_size(&(*filelist), file, ft_max_len(args, nb));
	ft_get_date(&(*filelist), file);
	*filelist = ft_strcat(*filelist, file);
}

void ft_perror(int code, const void *arg)
{
	char *str;

	if (code == 0)
	{
		str = (char *)arg;
		ft_putstr("ls: illegal option -- ");
		ft_putchar(str[0]);
		ft_putstr("\n");
		ft_putendl("usage: ls [-atrlR] [file ...]");
	}
	if (code == 1)
        ft_putstr("ls: not enough memory to perform the operation");
	exit(0);
}

#include <stdio.h>
int ft_out(char *file, const char **args, char **filelist, int nb)
{
	char *flags;
	flags = ft_get_flags(args);
	if (ft_strchr(flags, 'a') == NULL)
		if (file[0] == '.')
			return (0);
	ft_print_total(file, 1);
	if (ft_strchr(flags, 'l') != NULL)
	{
		ft_file_info(&(*filelist), file, args, nb);
		ft_mallcat(&(*filelist), "\n");
		return (0);
	}
	printf(":D\n");
	ft_mallcat(&(*filelist), file);
	ft_mallcat(&(*filelist), "  ");
		printf("working\n");	
	return (0);
}

void ls_process(const char **args, char *file, char **filelist, int nb)
{
	if (args != NULL)
		ft_out(file, args, &(*filelist), nb);
	else if (file[0] != '.')
	{
		ft_mallcat(&(*filelist), file);
		ft_mallcat(&(*filelist), "  ");
	}
}

#include <stdio.h>
void ft_print(const char **args, char *filelist)
{
	int total;

    if (args == NULL || ft_strchr(ft_get_flags(args), 'l') == NULL)
    {
		filelist[ft_strlen(filelist) - 2] = '\0';
    }
    else
    {
        total = ft_print_total(" ", 0);
		ft_putstr("total ");
		ft_putendl(ft_itoa(total));
    }
	filelist[ft_strlen(filelist)] = '\0';
    ft_putstr(filelist);
	free(filelist);
}
