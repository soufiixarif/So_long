#include "so_long.h"

void	checkstructcontent(t_check *s, int n)
{
	if (n == 0)
	{
		if (s->c < 1)
			exit (write (1, "coins na9sin", 13));
		if (s->e != 1)
			exit (write (1, "lkharja mahiach", 16));
		if (s->p != 1)
			exit (write (1, "le3ab mahowach", 15));
	}
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

void	checkmiddlemap(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[0] != '1')
			exit (write (1, "makinch wahed f lowel", 23));
		if (line[len - 1] != '1')
			exit (write (1, "makinch wahed f tali", 22));
		i++;
	}
}

void	checkmapcomponent(char *line, t_check *s)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			s->p += 1;
		else if (line[i] == 'C')
			s->c += 1;
		else if (line[i] == 'E')
			s->e += 1;
		else if (line[i] != '0' && line[i] != '1' && puts("kayn tkhrchich"))
			exit(EXIT_FAILURE);
		i++;
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

	s.p = 0;
	s.c = 0;
	s.e = 0;
	s.xp = 0;
	s.yp = 0;
	rows = checklenoflines(mapfile);
	i = 0;
	checklenmap(mapfile);
	checkforone(mapfile[0]);
	checkforone(mapfile[rows - 1]);
	while (mapfile[i])
	{
		checkmiddlemap(mapfile[i]);
		checkmapcomponent(mapfile[i], &s);
		i++;
	}
	checkstructcontent(&s,0);
	posplayer(mapfile, &s);
	floodfill(mapfile,s.xp,s.yp,rows);
	i = -1;
	while(mapfile[++i])
		checkmapcomponent(mapfile[i],&s);	
	checkstructcontent(&s,1);
}
