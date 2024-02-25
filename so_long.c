#include "so_long.h"

char	**readfromap(char **mapfile, int fd)
{
	char	*str;
	char	*onelinemap;

	str = get_next_line(fd);
	if (!str && write(1, "map khawia", 11))
		exit(EXIT_FAILURE);
	onelinemap = NULL;
	while (str)
	{
		if (*str == '\n' && write(1,"star zayd", 10))
			exit(EXIT_FAILURE);
		onelinemap = ft_strjoin(onelinemap, str);
		free(str);
		str = get_next_line(fd);
	}
	if (onelinemap && onelinemap[ft_strlen(onelinemap) - 1] == '\n' && write(1, "star zayd", 10))
		exit(EXIT_FAILURE);
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
		if (ft_strcmp (ft_strrchr (argv[1], '.'), ".ber"))
			exit(write(1, "smia mahiach", 13));
		fd = open(*mapfile, O_RDONLY);
		mapfile = readfromap(mapfile, fd);
		checkmapvalidity(mapfile);
		mlx(mapfile);
	}
}
