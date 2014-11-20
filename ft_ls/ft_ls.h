/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:04:33 by jantiope          #+#    #+#             */
/*   Updated: 2014/11/20 07:24:11 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

enum {ILLEGAL, MEMORY};
void	ft_time_ls(const char **args, int nbs);
int		ft_check_flag(const char **args, int nb);
char	*ft_get_folder(const char **args);
void	ft_perror(int code, const void *arg);
int		ft_out(char *file, const char **args, char **filelist, int nb);
char	*ft_get_flags(const char **args);
void	ls_process(const char **args, char *file, char **filelist, int nb);
void	my_realloc(char **filelist, char *file);
void	ft_print(const char **args, char *filelist);
int		ft_print_total(char *file, int mode);
void	ft_get_permissions(char **filelist, char *file);
void	ft_get_links(char **filelist, char *file);
void	ft_get_uid_gid(char **filelist, char *file);
void	ft_get_size(char **filelist, char *file, size_t maxlen);
int		ft_max_len(const char **args, int nb);
void	ft_get_date(char **filelist, char *file);
char	**ft_arrnew(const char **args, int nb);
char	**ft_arrev(char **copy, int size);
char	*ft_mallcat(char **s1, const char *s2);
#endif
