#include "so_long_bonus.h"

void	mlx_img(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, img, x, y);
}

void	putcoinframe(t_data *d, void *img)
{
	int	i;
	int	j;

	j = 0;
	while (d->map[j])
	{
		i = 0;
		while (d->map[j][i])
		{
			if (d->map[j][i] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, img, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

void	putenemyframe(t_data *d, void *img)
{
	int	i;
	int	j;

	j = 0;
	while (d->map[j])
	{
		i = 0;
		while (d->map[j][i])
		{
			if (d->map[j][i] == 'N')
				mlx_put_image_to_window(d->mlx, d->win, img, i * 64, j * 64);
			i++;
		}
		j++;
	}
}
