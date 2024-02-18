#include "so_long.h"

void	checkstructcontent(t_check *s)
{
	if (s->c < 1)
		exit (write (1, "coins na9sin", 14));
	if (s->e != 1)
		exit (write (1, "lkharja mahiach", 17));
	if (s->p != 1)
		exit (write (1, "le3ab mahowach", 16));
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

void	chackmapcomponent(char *line, t_check *n)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'p')
		{
			n->p += 1;
		}
		if (line[i] == 'c')
		{
			n->c += 1;
		}
		if (line[i] == 'e')
		{
			n->e += 1;
		}
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
	int		linesnb;
	t_check	s;

	s.p = 0;
	s.c = 0;
	s.e = 0;
	linesnb = checklenoflines(mapfile);
	i = 0;
	checklenmap(mapfile);
	checkforone(mapfile[0]);
	checkforone(mapfile[linesnb - 1]);
	while (mapfile[i])
	{
		checkmiddlemap(mapfile[i]);
		chackmapcomponent(mapfile[i], &s);
		i++;
	}
	checkstructcontent(&s);
}
