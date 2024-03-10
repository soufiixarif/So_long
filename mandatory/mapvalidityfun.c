#include "so_long.h"

void	checkstructcontent(t_data *d, int n)
{
	if (n == 0)
	{
		if (d->c < 1)
			printerror(d);
		if (d->e != 1)
			printerror(d);
		if (d->p != 1)
			printerror(d);
	}
	else if (n == 1)
	{
		if (d->c > 0)
			printerror(d);
		if (d->e > 0)
			printerror(d);
		if (d->p > 0)
			printerror(d);
	}
}

void	checkmapcomponent(char **map, t_data *d)
{
	int	i;
	int	j;

	j = 0;
	d->c = 0;
	d->p = 0;
	d->e = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
				printerror(d);
			else if (map[j][i] == 'P')
				d->p += 1;
			else if (map[j][i] == 'C')
				d->c += 1;
			else if (map[j][i] == 'E')
				d->e += 1;
			else if (map[j][i] != '0' && map[j][i] != '1')
				printerror(d);
			i++;
		}
		j++;
	}
}

void	checkforone(t_data *d, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			printerror(d);
		i++;
	}
}

void	checkmapvalidity(t_data *d)
{
	int		i;
	int		rows;
	char	**mapp;

	d->xp = 0;
	d->yp = 0;
	i = 0;
	rows = checklenoflines(d->map);
	checklenmap(d, d->map);
	checkforone(d, d->map[0]);
	checkforone(d, d->map[rows - 1]);
	checkmapcomponent(d->map, d);
	checkstructcontent(d, 0);
	posplayer(d->map, d);
	mapp = arrdup(d->map, rows);
	floodfill(mapp, d->xp, d->yp, rows);
	checkmapcomponent(mapp, d);
	ft_2dfree(mapp);
	checkstructcontent(d, 1);
}
