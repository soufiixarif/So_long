#include "so_long_bonus.h"

void	moveright(t_data *d, int j, int i, int keycode)
{
	char	*steps;

	if (d->map[j][i + 1] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		write(1, "you won", 8);
		exit(0);
	}
	else if (d->map[j][i + 1] == 'N')
	{
		ft_2dfree(d->map);
		exit(write(1, "you lose", 8));
	}
	else if (d->map[j][i + 1] != '1' && d->map[j][i + 1] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j][i + 1] = 'P';
		put_img(d->map, d, keycode);
		ft_printf("%d moves\n", ++d->moves);
		steps = ft_itoa(d->moves);
		steps = ft_strjoinmliha("steps : ", steps);
		mlx_string_put(d->mlx, d->win, 60, 30, 0x00FFFF, steps);
		free(steps);
	}
}

void	moveleft(t_data *d, int j, int i, int keycode)
{
	char	*steps;

	if (d->map[j][i - 1] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		write(1, "you won", 8);
		exit(0);
	}
	else if (d->map[j][i - 1] == 'N')
	{
		ft_2dfree(d->map);
		exit(write(1, "you lose", 8));
	}
	else if (d->map[j][i - 1] != '1' && d->map[j][i - 1] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j][i - 1] = 'P';
		put_img(d->map, d, keycode);
		ft_printf("%d moves\n", ++d->moves);
		steps = ft_itoa(d->moves);
		steps = ft_strjoinmliha("steps : ", steps);
		mlx_string_put(d->mlx, d->win, 60, 30, 0x00FFFF, steps);
		free(steps);
	}
}

void	moveup(t_data *d, int j, int i, int keycode)
{
	char	*steps;

	if (d->map[j - 1][i] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		write(1, "you won", 8);
		exit(0);
	}
	else if (d->map[j - 1][i] == 'N')
	{
		ft_2dfree(d->map);
		exit(write(1, "you lose", 8));
	}
	else if (d->map[j - 1][i] != '1' && d->map[j - 1][i] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j - 1][i] = 'P';
		put_img(d->map, d, keycode);
		ft_printf("%d moves\n", ++d->moves);
		steps = ft_itoa(d->moves);
		steps = ft_strjoinmliha("steps : ", steps);
		mlx_string_put(d->mlx, d->win, 60, 30, 0x00FFFF, steps);
		free(steps);
	}
}

void	movedown(t_data *d, int j, int i, int keycode)
{
	char	*steps;

	if (d->map[j + 1][i] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		write(1, "you won", 8);
		exit(0);
	}
	else if (d->map[j + 1][i] == 'N')
	{
		ft_2dfree(d->map);
		exit(write(1, "you lose", 8));
	}
	else if (d->map[j + 1][i] != '1' && d->map[j + 1][i] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j + 1][i] = 'P';
		put_img(d->map, d, keycode);
		ft_printf("%d moves\n", ++d->moves);
		steps = ft_itoa(d->moves);
		steps = ft_strjoinmliha("steps : ", steps);
		mlx_string_put(d->mlx, d->win, 60, 30, 0x00FFFF, steps);
		free(steps);
	}
}

void	printerror(t_data *d)
{
	ft_2dfree(d->map);
	d->map = NULL;
	printf("Error\nmap invalide");
	exit(EXIT_FAILURE);
}
