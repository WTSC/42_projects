/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 20:45:03 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/01 20:22:00 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <wchar.h>
# include <inttypes.h>
# include <sys/types.h>

int		ft_setflags(char c, int *flag);
char	*ft_getzeros(char *f, char *s, int flag);
void	printf_oputjustified(size_t len, uintmax_t o, int flag, char type);
void	printf_ojustify(char *s, int flag, char type, uintmax_t o);
void	printf_owidth(char *s, char type, uintmax_t o, int flag);
void	printf_oprocess(uintmax_t o, char type, int flag, char *f);
char	*printf_octal2(char *f, char type, uintmax_t i);
void	printf_uprocess(uintmax_t o, char type, int flag, char *f);
size_t	ft_usize(uintmax_t o, char type, int mode, int flag);
void	printf_uputjustified(size_t len, uintmax_t o, int flag, char type);
void	printf_ujustify(char *s, int flag, char type, uintmax_t o);
void	printf_uwidth(char *s, char type, uintmax_t o, int flag);
char	*printf_uint2(char *f, char type, uintmax_t ld);
size_t	printf_prec3(char *s);
size_t	printf_prec2(char *s, int flag);
void	printf_iputjustified(size_t len, intmax_t o, int flag, char type);
size_t	ft_size(intmax_t o, char type, int mode, int flag);
void	printf_iprocess(intmax_t o, char type, int flag, char *f);
size_t	printf_prec(char *s, int flag);
int		ft_wstrbyte(wchar_t *s);
void	char_putwcount(wchar_t c);
int		ft_putwcount(int type, wchar_t *s);
void	char_putcount(char c);
int		ft_putcount(int type, char *s);
char	*ft_puthex(char *s, char type, int flag, char *f);
int		ft_is_hjz(char *f);
char	ft_modifier(const char *o, char mod, int i);
void	printf_iwidth(char *s, char type, intmax_t o, int flag);
void	printf_ijustify(char *s, int flag, char pad, intmax_t o);
int		printf_iprec(char *s, int flag, char type);
wchar_t	*printf_wprec(char *s, wchar_t *o);
char	*printf_cprec(char *s, char *o);
char	*printf_sprocess(char *s, char type, char *f);
void	printf_width(char *s, int flag, char type, char *o);
void	printf_justify(char *s, int flag, char pad, char *o);
void	printf_wwidth(char *s, wchar_t *o);
void	printf_wjustify(char *s, int flags, char pad, wchar_t *o);
void	printf_error(int id);
int		printf_flags(char *f, int *flag, int i, int j);
int		ft_is_binary(char *seq);
void	is_dot_valid(char *f, int *flag, int i);
char	*printf_wchar(char *f, wchar_t c);
char	*printf_hexa(char *f, char type, unsigned long long int ld);
char	*printf_octal(char *f, char type, uintmax_t ld);
char	*printf_uint(char *f, char type, uintmax_t d);
char	*printf_pointer(char *f, void *p);
char	*printf_clean(char **f, int *flag);
char	*printf_ud(char *f, char type, uintmax_t d);
char	*printf_d(char *f, char type, long int d);
char	*printf_s(char *f, char type, void *s);
char	*printf_string(char *f, char *s, char type);
char	*printf_wstring(char *f, wchar_t *s);
char	*printf_percent(char *f, char type);
char	*printf_int(char *f, char type, intmax_t i);
char	*printf_lint(char *f, long int d);
#endif
