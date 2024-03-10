#include "so_long.h"

void	moveright(t_data *d, int j, int i)
{
	if (d->map[j][i + 1] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		exit(write(1, "you won", 8));
	}
	else if (d->map[j][i + 1] != '1' && d->map[j][i + 1] != 'E')
	{
		d->moves += 1;
		d->map[j][i] = '0';
		d->map[j][i + 1] = 'P';
		put_img(d->map, d);
		ft_printf("%d moves\n", d->moves);
	}
}

void	moveleft(t_data *d, int j, int i)
{
	if (d->map[j][i - 1] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		exit(write(1, "you won", 8));
	}
	else if (d->map[j][i - 1] != '1' && d->map[j][i - 1] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j][i - 1] = 'P';
		put_img(d->map, d);
		ft_printf("%d moves\n", ++d->moves);
	}
}

void	moveup(t_data *d, int j, int i)
{
	if (d->map[j - 1][i] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		exit(write(1, "you won\n", 8));
	}
	else if (d->map[j - 1][i] != '1' && d->map[j - 1][i] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j - 1][i] = 'P';
		put_img(d->map, d);
		ft_printf("%d moves\n", ++d->moves);
	}
}

void	movedown(t_data *d, int j, int i)
{
	if (d->map[j + 1][i] == 'E' && !checkforcoin(d->map))
	{
		ft_printf("%d moves\n", ++d->moves);
		ft_2dfree(d->map);
		exit(write(1, "you won", 8));
	}
	else if (d->map[j + 1][i] != '1' && d->map[j + 1][i] != 'E')
	{
		d->map[j][i] = '0';
		d->map[j + 1][i] = 'P';
		put_img(d->map, d);
		ft_printf("%d moves\n", ++d->moves);
	}
}

void	printerror(t_data *d)
{
	ft_2dfree(d->map);
	d->map = NULL;
	printf("map error");
	exit(EXIT_FAILURE);
}
