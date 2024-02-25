#include "so_long.h"

void	checkstructcontent(t_check *s, int n)
{
	// befor floodfill
	if (n == 0)
	{
		if (s->c < 1)
			exit (write (1, "coins na9sin", 13));
		if (s->e != 1)
			exit (write (1, "lkharja mahiach", 16));
		if (s->p != 1)
			exit (write (1, "le3ab mahowach", 15));
	}
	//after floodfill
	else if (n == 1)
	{
		if (s->c > 0)
			exit (write (1, "coin mehbosa", 13));
		if (s->e > 0)
			exit (write (1, "l bab mbloki", 13));
		if (s->p > 0)
			exit (write (1, "le3ab sadin 3lih", 17));
	}
}

void	checkmapcomponent(char **map, t_check *s)
{
	int	i;
	int	j;
	int len;

	j = 0;
	s->c = 0;
	s->p = 0;
	s->e = 0;
	len = ft_strlen(map[0]);
	while(map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][0] != '1' || map[j][len - 1] != '1')
				exit (write (1, "makinch wahed f lowel ola tali", 31));
			else if (map[j][i] == 'P')
				s->p += 1;
			else if (map[j][i] == 'C')
				s->c += 1;
			else if (map[j][i] == 'E')
				s->e += 1;
			else if (map[j][i] != '0' && map[j][i] != '1' && write(1,"kayn tkharchich",16))
				exit(EXIT_FAILURE);
			i++;
		}
		j++;
	}
}

void	checkforone(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			exit (write (1, "line mafihch wahed", 20));
		i++;
	}
}

void	checkmapvalidity(char **mapfile)
{
	int		i;
	int		rows;
	t_check	s;
	char **mapp;

	s.xp = 0;
	s.yp = 0;
	i = 0;
	rows = checklenoflines(mapfile);
	mapp = arrdup(mapfile,rows);
	checklenmap(mapfile);
	checkforone(mapfile[0]);
	checkforone(mapfile[rows - 1]);
	checkmapcomponent(mapfile, &s);
	checkstructcontent(&s, 0);
	posplayer(mapfile, &s);
	floodfill(mapp, s.xp, s.yp, rows);
	checkmapcomponent(mapp, &s);
	checkstructcontent(&s, 1);
}
