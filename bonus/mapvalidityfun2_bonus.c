#include "so_long_bonus.h"

void	checklenmap(t_data *d, char **mapfile)
{
	int		len;
	int		tmp;
	int		nboflines;
	int		i;

	nboflines = checklenoflines(mapfile);
	i = 1;
	len = ft_strlen(mapfile[0]);
	while (i < nboflines)
	{
		tmp = so_long_strlen(mapfile[i]);
		if (len != tmp)
			printerror(d);
		i++;
	}
}

int	checklenoflines(char **gamap)
{
	int	i;

	i = 0;
	while (gamap[i])
	{
		if (gamap[i][0] != '\0')
			i++;
		else
			break ;
	}
	return (i);
}

size_t	so_long_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	else
	{
		while (str[i])
		{
			i++;
		}
	}
	return (i);
}

void	posplayer(char **map, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				d->xp = i;
				d->yp = j;
			}
			i++;
		}
		j++;
	}
}

void	floodfill(char **map, int xp, int yp, int rows)
{
	int	len;

	len = ft_strlen(map[0]);
	if (xp < 0 || xp >= len || yp < 0 || yp >= rows || map[yp][xp] == '1')
		return ;
	else if (map[yp][xp] == 'E' || map[yp][xp] == 'N')
		map[yp][xp] = '1';
	else
	{
		map[yp][xp] = '1';
		floodfill(map, (xp + 1), yp, rows);
		floodfill(map, (xp - 1), yp, rows);
		floodfill(map, xp, (yp + 1), rows);
		floodfill(map, xp, (yp - 1), rows);
	}
}
