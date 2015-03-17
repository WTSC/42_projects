#include "w3d.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <mlx.h>

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

int key_hook(int keycode, t_w3d *w3d)
{
	if (keycode == 65307)
		w3d_exit(&w3d);
	else if (keycode == 65361 || keycode == 65363)
	{
		w3d->pos.a += (keycode == 65361) ? PI / 3 : -PI / 3;
		if (w3d->pos.a > 2 * PI)
			w3d->pos.a -= 2 * PI;
		else if (w3d->pos.a < 0)
			w3d->pos.a = (2 * PI) + w3d->pos.a;
	}
	else if (keycode == 65362 || keycode == 65364)
		w3d->pos.y += (keycode == 65362) ? 30 : -30;
	w3d->change = 1;
	return (0);
}

#include <stdio.h>
int expose_hook(t_w3d *w3d)
{
	printf("w3d->pos.a before = %f\n", w3d->pos.a);
	w3d_raycaster(&w3d, 0);
	w3d_raycaster(&w3d, 1);
	mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->img, 0, 0);
	return (0);
}
