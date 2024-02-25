#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
    void	*ground;
}				t_data;

int main()
{
    void *mlx;
    void *mlx_win;
    t_data  data;
    int height;
    int width;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx,1920,1024,"lmlx lmilha");

    data.ground = mlx_xpm_file_to_image(mlx, "grnd.xpm", &width, &height);
    if (!data.ground)
        exit(0);
    mlx_put_image_to_window(mlx, mlx_win, data.ground, 0, 0);

    mlx_loop(mlx);
}