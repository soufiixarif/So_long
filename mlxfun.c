#include "so_long.h"
void    mlx(char **map)
{
    t_data  d;

    d.rows = checklenoflines(map);
    d.len = ft_strlen(map[0]);
    d.mlx = mlx_init();
    d.win = mlx_new_window(d.mlx,60 * d.len, 60 * d.rows , "So_long");
    d.cd = mlx_xpm_file_to_image(d.mlx,"doorC.xpm",&d.width,&d.height);
    mlx_put_image_to_window(d.mlx, d.win, d.cd, 0, 0);

    mlx_loop(d.mlx);
}