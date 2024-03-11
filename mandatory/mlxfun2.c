#include "so_long.h"

void	mlx_img(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, img, x, y);
}
