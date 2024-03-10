#include "so_long_bonus.h"

int	moves(int keycode, t_data *d)
{
	posplayer(d->map, d);
	if (keycode == 2 || keycode == 124)
		moveright(d, d->yp, d->xp, keycode);
	if (keycode == 0 || keycode == 123)
		moveleft(d, d->yp, d->xp, keycode);
	if (keycode == 13 || keycode == 126)
		moveup(d, d->yp, d->xp, keycode);
	if (keycode == 1 || keycode == 125)
		movedown(d, d->yp, d->xp, keycode);
	if (keycode == 53)
		exit(ft_2dfree(d->map));
	return (0);
}

void	put_img(char **map, t_data *d, int keycode)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wall, i * 64, j * 64);
			else if (map[j][i] == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->grnd, i * 64, j * 64);
			else if (map[j][i] == 'P')
				put_img_player(d, keycode, i, j);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->yc, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->cd, i * 64, j * 64);
			else if (map[j][i] == 'N')
				mlx_put_image_to_window(d->mlx, d->win, d->n1, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

void	xmp_to_img(t_data *d)
{
	d->cd = mlx_xpm_file_to_image(d->mlx,
			"Btextures/door_closed.xpm", &d->width, &d->height);
	d->od = mlx_xpm_file_to_image(d->mlx,
			"Btextures/door_open.xpm", &d->width, &d->height);
	d->grnd = mlx_xpm_file_to_image(d->mlx,
			"Btextures/ground.xpm", &d->width, &d->height);
	d->pd = mlx_xpm_file_to_image(d->mlx,
			"Btextures/player_down.xpm", &d->width, &d->height);
	d->pu = mlx_xpm_file_to_image(d->mlx,
			"Btextures/playerUp.xpm", &d->width, &d->height);
	d->pl = mlx_xpm_file_to_image(d->mlx,
			"Btextures/playerLeft.xpm", &d->width, &d->height);
	d->pr = mlx_xpm_file_to_image(d->mlx,
			"Btextures/playerRight.xpm", &d->width, &d->height);
	d->yc = mlx_xpm_file_to_image(d->mlx,
			"Btextures/c1.xpm", &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->mlx,
			"Btextures/wall.xpm", &d->width, &d->height);
	d->n1 = mlx_xpm_file_to_image(d->mlx,
			"Btextures/E1.xpm", &d->width, &d->height);
}

void	mlx(t_data *d)
{
	d->moves = 0;
	d->rows = checklenoflines(d->map);
	d->len = ft_strlen(d->map[0]);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 64 * d->len, 64 * d->rows, "So_long");
	xmp_to_img(d);
	put_img(d->map, d, -1);
	mlx_hook(d->win, 2, 0, moves, d);
	mlx_hook(d->win, 17, 1L << 17, close_win, &d);
	mlx_loop(d->mlx);
}
