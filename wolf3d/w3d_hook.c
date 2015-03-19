#include "w3d.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>

void w3d_exit(t_w3d **w3d)
{
	free((*w3d)->map);
	exit (0);
}

int loop_hook(t_w3d *w3d)
{
	if (w3d->change == 1)
	{
		expose_hook(w3d);
		w3d->change = 0;
	}
	return (0);
}

#include <stdio.h>
void	move_forward(t_w3d **w3d)
{

	double	x;
	double	y;

	x = (*w3d)->pos.x + cos((*w3d)->pos.a) * 10;
	y = (*w3d)->pos.y - sin((*w3d)->pos.a) * 10;
	if (y < (*w3d)->height * 64 && y > 0
	&& x < (*w3d)->width * 64 && x > 0)
	{
		if ((*w3d)->map[(int)y / 64][(int)x / 64][0] == '0' || (*w3d)->map[(int)y / 64][(int)x / 64][0] == 'X')
		{
			(*w3d)->pos.x = x;
			(*w3d)->pos.y = y;
		}
	}
}

void	move_back(t_w3d **w3d)
{

	double	x;
	double	y;

	x = (*w3d)->pos.x - cos((*w3d)->pos.a) * 10;
	y = (*w3d)->pos.y + sin((*w3d)->pos.a) * 10;
	if (y < (*w3d)->height * 64 && y > 0
	&& x < (*w3d)->width * 64 && x > 0)
	{
		if ((*w3d)->map[(int)y / 64][(int)x / 64][0] == '0' || (*w3d)->map[(int)y / 64][(int)x / 64][0] == 'X')
		{
			(*w3d)->pos.x = x;
			(*w3d)->pos.y = y;
		}
	}
}


int key_hook(int keycode, t_w3d *w3d)
{
	if (keycode == 65307)
		w3d_exit(&w3d);
	else if (keycode == 65361 || keycode == 65363)
	{
		w3d->pos.a += (keycode == 65361) ? PI / 6 : -PI / 6;
		if (w3d->pos.a > 2 * PI)
			w3d->pos.a -= 2 * PI;
		else if (w3d->pos.a < 0)
			w3d->pos.a = (2 * PI) + w3d->pos.a;
	}
	else if (keycode == 65362 || keycode == 65364)
	{
		if (keycode == 65362)
			move_forward(&w3d);
		else
			move_back(&w3d);
	}
	w3d->change = 1;
	return (0);
}

int expose_hook(t_w3d *w3d)
{
	printf("w3d->pos.a before = %f\n", w3d->pos.a);
	w3d_raycaster(&w3d, 0);
	w3d_raycaster(&w3d, 1);
	mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->img, 0, 0);
	return (0);
}
