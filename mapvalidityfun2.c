#include "so_long.h"

void	checklenmap(char **mapfile)
{
	int		len;
	int		tmp;
	int		nboflines;
	int		i;

	nboflines = checklenoflines(mapfile);
	i = 1;
	len = ft_strlen(mapfile[0]);
	while (i < nboflines - 1)
	{
		tmp = so_long_strlen(mapfile[i]);
		if (len != tmp)
			exit (write (1, "len of map lines error", 23));
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
