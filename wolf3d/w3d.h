/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jantiope <jantiope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 20:00:29 by jantiope          #+#    #+#             */
/*   Updated: 2015/03/16 21:06:00 by jantiope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_H
# define PI 3.14159265358979323846
# define W3D_H
# define WIDTH 320
# define HEIGHT 200
# define WALL 64
# define TALL 32
# define ANGLE 60
# define D 277
# define PAD 0.00327249234


typedef struct	s_file
{
	int			fd;
	int			n;
	char		*line;
	int			i;
}				t_file;

typedef struct	s_coor
{
	int			x;
	int			y;
	double			a;
}				t_coor;

typedef struct	s_w3d
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits;
	int			end;
	int			ln;
	t_coor		pos;
	char		*data;
	char		***map;
	int			width;
	int			height;
	double		ray;
	short		slice;
	int		color;
	int		change;
}				t_w3d;

void w3d_raycaster(t_w3d **w3d, short int type);
int 			expose_hook(t_w3d *w3d);
int			 key_hook(int keycode, t_w3d *w3d);
int 			loop_hook(t_w3d *w3d);
void			w3d_draw_ceil(t_w3d *w3d, short int n);
void 			w3d_draw_floor(t_w3d *w3d, short int n);
void			w3d_draw_slice(t_w3d *w3d, short int n, int d);
unsigned int	w3d_calc(double h, double v, short type, t_w3d **w3d, int n);
double			to_rad(double deg);
double			to_deg(double rad);

double			w3d_cast_vertical(t_w3d *w3d);
double			w3d_cast_horizontal(t_w3d *w3d);
double			to_rad(double deg);
int				w3d_get_start(t_w3d **w3d);
void			w3d_check(char ***map);
char			***ft_nbrsplit(char *file, t_w3d **w3d);
#endif
