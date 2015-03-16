/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:05:20 by jantiope          #+#    #+#             */
/*   Updated: 2015/02/26 17:53:40 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1280
# define HEIGHT 720

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
	int c;
}				t_rgb;

typedef struct	s_mon
{
	void		*mlx;
	void		*win;
	void		*img;
	int			ln;
	int			bits;
	int			end;
	char		*data;
	int			change;
	char		*det[4];
	int			c;
}				t_mon;

typedef struct	s_f
{
	void		*mlx;
	void		*win;
	t_mon		mon;
	void		*img;
	char		*frac;
	char		*data;
	int			ln;
	int			bits;
	int			end;
	int			x;
	int			y;
	int			change;
	int			layer;
	t_rgb		l1;
	t_rgb		l2;
	double		x2;
	double		y2;
	double		mod;
	double		r;
	double		i;
	double		zoom;
	int			max;
}				t_f;

typedef struct	s_pt
{
	double		x;
	double		y;
}				t_pt;

typedef struct	s_frac
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	int			i;
	int			j;
	int			k;
	int			h;
	double		tr;
	double		ti;
}				t_frac;

void			ft_move(t_f **f, int keycode);
char			*fractal_name(t_f *f);
void			print_color(t_f *f, t_rgb c, int col, int y);
void			erase_color(t_f *f, t_rgb c, int y);
char			*ft_ftoa(double i);
void			ft_change(t_f **f, int type, int key);
void			ft_update(t_f *f, int i, char *s);
void			mon_init(t_f *f);
void			ft_putmon(char *s, t_f *f, int x, int y);
t_rgb			fractol_modif_lumi(t_rgb c, int type);
void			fractol_modif_color(int *color, int type);
void			fractol_lumi(int key, t_f **f);
void			fractol_color(int key, t_rgb *c, t_f *f);
void			fractol_change(int id, t_f **f);
int				fractol_check(char *arg);
void			fractol_put(int what, t_f *f, int c);
void			draw_ship(t_f *f);
int				loop_hook(t_f *f);
void			init_mandel_color(t_f **f);
void			init_ship_color(t_f **f);
void			init_julia_color(t_f **f);
void			fractol_reset(t_f **f);
int				key_hook(int keycode, t_f *f);
int				point_hook(int x, int y, t_f *f);
int				expose_hook(t_f *f);
int				mouse_hook(int b, int x, int y, t_f *f);
void			draw_julia(t_f *f);
int				ft_rgb(int r, int g, int b);
void			ft_pixel(t_f **t, int color, int x, int y);
void			draw_mandel(t_f *f);
double			ft_abs(double i);
#endif
