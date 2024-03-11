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

int	animation(t_data *d)
{
	coinanimation(d);
	enemyanimation(d);
	return (0);
}

void	coinanimation(t_data *d)
{
	static int	frame;

	if (clock() > d->cstart + 20000)
	{
		if (frame == 0)
			putcoinframe(d, d->c1);
		else if (frame == 1)
			putcoinframe(d, d->c2);
		else if (frame == 2)
			putcoinframe(d, d->c3);
		else if (frame == 3)
			putcoinframe(d, d->c4);
		frame++;
		d->cstart = clock();
	}
	if (frame == 4)
		frame = 0;
}

void	enemyanimation(t_data *d)
{
	static int	eframe;

	if (clock() > d->estart + 20000)
	{
		if (eframe == 0)
			putenemyframe(d, d->n1);
		else if (eframe == 1)
			putenemyframe(d, d->n2);
		else if (eframe == 2)
			putenemyframe(d, d->n3);
		else if (eframe == 3)
			putenemyframe(d, d->n4);
		eframe++;
		d->estart = clock();
	}
	if (eframe == 4)
		eframe = 0;
}
