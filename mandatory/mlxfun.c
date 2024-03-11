#include "so_long.h"

int	moves(int keycode, t_data *d)
{
	posplayer(d->map, d);
	if (keycode == 2 || keycode == 124)
		moveright(d, d->yp, d->xp);
	if (keycode == 0 || keycode == 123)
		moveleft(d, d->yp, d->xp);
	if (keycode == 13 || keycode == 126)
		moveup(d, d->yp, d->xp);
	if (keycode == 1 || keycode == 125)
		movedown(d, d->yp, d->xp);
	if (keycode == 53)
		exit(ft_2dfree(d->map));
	return (0);
}

void	put_img(char **map, t_data *d)
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
				mlx_img(d, d->wall, i * 60, j * 60);
			else if (map[j][i] == '0')
				mlx_img(d, d->grnd, i * 60, j * 60);
			else if (map[j][i] == 'P')
				mlx_img(d, d->pd, i * 60, j * 60);
			else if (map[j][i] == 'C')
				mlx_img(d, d->yc, i * 60, j * 60);
			else if (map[j][i] == 'E')
				mlx_img(d, d->cd, i * 60, j * 60);
			i++;
		}
		j++;
	}
}

void	xmp_to_img(t_data *d)
{
	d->cd = mlx_xpm_file_to_image(d->mlx,
			"textures/doorClosed.xpm", &d->width, &d->height);
	d->grnd = mlx_xpm_file_to_image(d->mlx,
			"textures/ground.xpm", &d->width, &d->height);
	d->pd = mlx_xpm_file_to_image(d->mlx,
			"textures/playerDown.xpm", &d->width, &d->height);
	d->yc = mlx_xpm_file_to_image(d->mlx,
			"textures/YellowCollectible.xpm", &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->mlx,
			"textures/wall.xpm", &d->width, &d->height);
}

void	mlx(t_data *d)
{
	d->moves = 0;
	d->rows = checklenoflines(d->map);
	d->len = ft_strlen(d->map[0]);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 60 * d->len, 60 * d->rows, "So_long");
	xmp_to_img(d);
	put_img(d->map, d);
	mlx_hook(d->win, 2, 0, moves, d);
	mlx_hook(d->win, 17, 1L << 17, close_win, &d);
	mlx_loop(d->mlx);
}
