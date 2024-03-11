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
				mlx_img(d, d->wall, i * 64, j * 64);
			else if (map[j][i] == '0')
				mlx_img(d, d->grnd, i * 64, j * 64);
			else if (map[j][i] == 'P')
				put_img_player(d, keycode, i, j);
			else if (map[j][i] == 'E')
				mlx_img(d, d->cd, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

void	xmp_to_img(t_data *d)
{
	d->cd = mlx_xpm_file_to_image(d->mlx, DC, &d->width, &d->height);
	d->od = mlx_xpm_file_to_image(d->mlx, DO, &d->width, &d->height);
	d->grnd = mlx_xpm_file_to_image(d->mlx, GRND, &d->width, &d->height);
	d->pd = mlx_xpm_file_to_image(d->mlx, PD, &d->width, &d->height);
	d->pu = mlx_xpm_file_to_image(d->mlx, PU, &d->width, &d->height);
	d->pl = mlx_xpm_file_to_image(d->mlx, PL, &d->width, &d->height);
	d->pr = mlx_xpm_file_to_image(d->mlx, PR, &d->width, &d->height);
	d->c1 = mlx_xpm_file_to_image(d->mlx, C1, &d->width, &d->height);
	d->c2 = mlx_xpm_file_to_image(d->mlx, C2, &d->width, &d->height);
	d->c3 = mlx_xpm_file_to_image(d->mlx, C3, &d->width, &d->height);
	d->c4 = mlx_xpm_file_to_image(d->mlx, C4, &d->width, &d->height);
	d->n1 = mlx_xpm_file_to_image(d->mlx, N1, &d->width, &d->height);
	d->n2 = mlx_xpm_file_to_image(d->mlx, N2, &d->width, &d->height);
	d->n3 = mlx_xpm_file_to_image(d->mlx, N3, &d->width, &d->height);
	d->n4 = mlx_xpm_file_to_image(d->mlx, N4, &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->mlx, WALL, &d->width, &d->height);
}

void	mlx(t_data *d)
{
	char	*steps;

	d->moves = 0;
	d->estart = clock();
	d->cstart = clock();
	d->rows = checklenoflines(d->map);
	d->len = ft_strlen(d->map[0]);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 64 * d->len, 64 * d->rows, "So_long");
	xmp_to_img(d);
	put_img(d->map, d, -1);
	mlx_loop_hook(d->mlx, animation, d);
	mlx_hook(d->win, 2, 0, moves, d);
	mlx_hook(d->win, 17, 1L << 17, close_win, &d);
	mlx_loop(d->mlx);
}
