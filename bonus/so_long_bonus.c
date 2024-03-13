#include "so_long_bonus.h"

char	**readfromap(char **mapfile, int fd)
{
	char	*str;
	char	*onelinemap;

	str = get_next_line(fd);
	if (!str && write(1, "Error\nmap invalide", 19))
		exit(EXIT_FAILURE);
	onelinemap = NULL;
	while (str)
	{
		if (*str == '\n' && write(1, "Error\nmap invalide", 19))
			exit(EXIT_FAILURE);
		onelinemap = ft_strjoin(onelinemap, str);
		free(str);
		str = get_next_line(fd);
	}
	if (onelinemap && onelinemap[ft_strlen(onelinemap) - 1] == '\n')
	{
		write(1, "Error\nmap invalide", 19);
		ft_free(onelinemap);
		exit(EXIT_FAILURE);
	}
	mapfile = ft_split(onelinemap, '\n');
	ft_free(onelinemap);
	return (mapfile);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		fd;

	if (argc > 1)
	{
		d.map = &argv[1];
		if (ft_strcmp (ft_strrchr (argv[1], '.'), ".ber"))
			exit(write(1, "Error\nmap invalide", 19));
		fd = open(*d.map, O_RDONLY);
		d.map = readfromap(d.map, fd);
		checkmapvalidity(&d);
		mlx(&d);
	}
}
