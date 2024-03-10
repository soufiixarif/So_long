#include "so_long_bonus.h"

char	**arrdup(char **map, int rows)
{
	char	**mapp;
	int		i;

	i = 0;
	mapp = (char **)malloc((rows + 1) * sizeof(char *));
	while (map[i])
	{
		mapp[i] = ft_strdup(map[i]);
		i++;
	}
	mapp[i] = NULL;
	return (mapp);
}

int	checkforcoin(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}

int	close_win(t_data *d)
{
	// ft_2dfree(d->map);
	d = NULL;
	exit(0);
}

int	ft_free(char *s)
{
	free(s);
	s = NULL;
	return (0);
}

int	ft_2dfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (0);
}
