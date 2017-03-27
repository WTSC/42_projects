/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:23:06 by jantiope          #+#    #+#             */
/*   Updated: 2017/03/27 20:57:35 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <wchar.h>
# include <inttypes.h>
# include <sys/types.h>

void			ft_putarray(char **array, char s, int fd);
char			**ft_arrcat(char **arr1, const char **arr2);
char			**ft_arrcpy(char **dst, const char **src);
char			**ft_arrdup(char **src);
char			**ft_arrjoin(char **dst, char **src);
char			*ft_capitalize(char *s);
wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len);
size_t			ft_wstrlen(wchar_t *s);
char			*ft_strtolower(char *s);
char			*ft_strtoupper(char *s);
int				ft_int_len(intmax_t num);
int				id_chr(const char *s, int c);
int				get_next_line(const int fd, char **line);
int				array_size(char **array);
char			*ft_strrev(char *s);
int				ft_power(int n, int power);
void			ft_putwchar(wchar_t c);
void			ft_putwstr(const wchar_t *s);
uintmax_t		ft_tobase10(char *n, int base);
char			*ft_base16(uintmax_t n);
char			*ft_base(uintmax_t n, unsigned int base);
char			*ft_freedup (char *s1);
char			*ft_strdup (const char *s1);
size_t			ft_strlen (const char *s);
char			*ft_strcpy (char *dst, const char *src);
int				ft_memcmp (const void *s1, const void *s2, size_t n);
char			*ft_strncpy (char *dst, const char *src, size_t n);
char			*ft_strcat (char *s1, const char *s2);
char			*ft_strncat (char *s1, const char *s2, size_t n);
size_t			ft_strlcat (char *dst, const char *src, size_t size);
void			*ft_memchr (const void *s, int c, size_t n);
char			*ft_strchr (const char *s, int c);
char			*ft_strrchr (const char *s, int c);
char			*ft_strstr (const char *s1, const char *s2);
char			*ft_strnstr (const char *s1, const char *s2, size_t n);
int				ft_strcmp (const char *s1, const char *s2);
int				ft_strncmp (const char *s1, const char *s2, size_t n);
int				ft_atoi (const char *str);
void			*ft_memset (void *b, int c, size_t len);
void			ft_bzero (void *s, size_t m);
void			*ft_memcpy (void *dst, const void *src, size_t n);
void			*ft_memccpy (void *dst, const void *src, int c, size_t n);
char			*ft_itoa (intmax_t n);
void			*ft_memalloc (size_t size);
void			ft_memdel (void **ap);
void			*ft_memmove (void *s1, const void *s2, size_t n);
void			ft_strdel (char **as);
char			*ft_strnew (size_t size);
int				ft_isalpha (int c);
int				ft_isdigit (int c);
int				ft_isalnum (int c);
int				ft_isascii (int c);
int				ft_isprint (int c);
int				ft_toupper (int c);
int				ft_tolower (int c);
void			ft_strclr (char *s);
void			ft_striter (char *s, void (*f)(char *));
void			ft_striteri (char *s, void (*f)(unsigned int, char *));
char			*ft_strmap (const char *s, char (*f)(char));
char			*ft_strmapi (const char *s, char (*f)(unsigned int, char));
int				ft_strequ (const char *s1, const char *s2);
int				ft_strnequ (const char *s1, const char *s2, size_t n);
char			*ft_freesub (char *s, unsigned int start, size_t len);
char			*ft_strsub (const char *s, unsigned int start, size_t len);
char			*ft_freejoin (char *s1, char *s2, int mode);
char			*ft_strjoin (const char *s1, const char *s2);
char			*ft_strtrim (const char *s);
char			**ft_strsplit (const char *s, char c);
void			ft_putchar (char c);
void			ft_putstr (const char *s);
void			ft_putendl (char const *s);
void			ft_putnbr (intmax_t n);
void			ft_putunbr (uintmax_t n);
void			ft_putchar_fd (char c, int fd);
void			ft_putstr_fd (const char *s, int fd);
void			ft_putendl_fd (char const *s, int fd);
void			ft_putnbr_fd (int n, int fd);
#endif
