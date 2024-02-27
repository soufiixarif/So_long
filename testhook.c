#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook! the key is %d \n",keycode);
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}