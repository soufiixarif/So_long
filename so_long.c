#include "so_long.h"

char	**readfromap(char **mapfile, int fd)
{
	char	*str;
	char	*onelinemap;

	str = get_next_line(fd);
	if (str[0] == '\n')
	{
		printf("line lowel khawi");
		exit(EXIT_FAILURE);
	}
	onelinemap = NULL;
	onelinemap = ft_strjoin(onelinemap, str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		onelinemap = ft_strjoin(onelinemap, str);
	}
	mapfile = ft_split(onelinemap, '\n');
	return (mapfile);
}

int	main(int argc, char **argv)
{
	char	**mapfile;
	int		fd;

	if (argc > 1)
	{
		mapfile = &argv[1];
		fd = open(*mapfile, O_RDONLY);
		mapfile = readfromap(mapfile, fd);
		checkmapvalidity(mapfile);
	}
}
