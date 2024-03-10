#include "so_long_bonus.h"

void	put_img_player(t_data *d, int keycode, int i, int j)
{
	if (keycode == 2 || keycode == 124)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->pr, i * 64, j * 64);
		opendoor(d);
	}
	else if (keycode == 0 || keycode == 123)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->pl, i * 64, j * 64);
		opendoor(d);
	}
	else if (keycode == 13 || keycode == 126)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->pu, i * 64, j * 64);
		opendoor(d);
	}
	else
	{
		mlx_put_image_to_window(d->mlx, d->win, d->pd, i * 64, j * 64);
		opendoor(d);
	}
}

void	opendoor(t_data *d)
{
	checkmapcomponent(d->map, d);
	if (d->c == 0)
		d->cd = d->od;
	else
		return ;
}
