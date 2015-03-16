/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:04:33 by jantiope          #+#    #+#             */
/*   Updated: 2015/01/15 02:58:19 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <string.h>

enum	{ILLEGAL, MEMORY, NODIR};
void	printype(char **filelist, char *file);
void	putmajor(char **filelist, int l, char *str, long int size);
int		ft_get_xattr(char *folder, const char **args);
int		ft_max_majmin(char *folder, const char **args, int mode, int i);
void	ft_majorminor(char *file, char **filelist, int l1, int l2);
void	modif_time(char **filelist, char **str, long long tiemm, char **hour);
void	user_bit(char **filelist, char *file);
int		calc_len(int mode, unsigned int uid, unsigned int gid);
void	group_bit(char **filelist, char *file);
void	other_bit(char **filelist, char *file);
void	uidgid2(char **filelist, char *file, int mlen1, int mlen2);
void	uidgid(char **filelist, char *file);
void	only_uid(char **filelist, char *file, int max1, int max2);
void	only_uid_gid(char **filelist, char *file, int max1, int max2);
void	only_gid(char **filelist, char *file, int max1, int max2);
char	**ft_filesfirst(char **folders);
char	**ft_arrsub(char **split, int start);
int		ft_count_folders(char **folders);
int		ft_isfolder(char *folder);
char	*ft_basename(char *path);
int		ft_subchk(char *file, char **subfolders, char *path, const char **args);
char	**ft_recursive(char **folders, const char **args);
void	ft_file_info(char **filelist, char *file);
char	*ft_basename(char *path);
void	ft_link(char **filelist, char *file);
char	*ls_trad(char *s);
void	ls_separate2(int i, char **dirs, const char **args);
char	*ls_separate(char *filelist, const char **args);
int		ft_max_str(char *folder, const char **args, int mode, int i);
int		is_dot(char *file, char *folder, const char **args);
char	**remove_path(char **array, const char **args, int nb, char *folder);
char	**ft_purge(char **array, char *folder);
int		ft_time_ls(const char **args, int nb, char *folder, int test);
int		ft_check_flag(const char **args, int nb);
char	**ft_get_folder(const char **args, int nb);
void	ft_perror(int code, const void *arg, char flag);
int		ft_out(char *file, const char **args, char **filelist, char *folder);
char	*ft_get_flags(const char **args);
void	ls_proc(const char **args, char **array, char **filelist, char *folder);
int		test_dir(char *folder, int i, const char **args);
void	ft_print(const char **args, char *filelist);
int		ft_print_total(char *file, int mode);
void	ft_get_permissions(char **filelist, char *file, int mode);
void	ft_get_links(char **filelist, char *file, size_t maxlen);
void	ft_get_uid_gid(char **filelist, char *file, int max1, int max2);
void	ft_get_size(char **filelist, char *file, size_t maxlen, int *dev);
int		ft_max_len(char *folder, const char **args, int mode, int i);
void	ft_get_date(char **filelist, char *file);
char	**ft_arrnew(char *folder);
char	**ft_arrev(char **copy, int size);
char	*ft_mallcat(char *s1, const char *s2);
int		array_size(char **array);
char	**ft_sort_by_time(char **array, int size, char *folder);
char	**list_dir(const char **args, int nb, char *folder);
char	**ft_qsort(char **array, int size);
char	**ft_list_directories(char **array);
int		ft_isdir(char *file);
#endif
