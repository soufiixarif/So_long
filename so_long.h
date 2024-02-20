#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
#include <strings.h>

// P = Player // C = Coin // E = Exit // xp && yp = pose player 

typedef struct checkmapbvld
{
	int	p;
	int	c;
	int	e;
	int xp;
	int yp;
}	t_check;

// GET_NEXT_LINE FUNCTIONS

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_getline(char *reserve);
char	*ft_update(char *reserve);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *reserve, char *buffer);
size_t	ft_strlen(char *str);

// SO_LONG FUNCTIONS

void	checkforone(char *line);
void	checkmapcomponent(char *line, t_check *n);
void	checkmiddlemap(char *line);
void	checkstructcontent(t_check *s, int n);
int		checklenoflines(char **gamap);
void	checkmapvalidity(char **mapfile);
void	checklenmap(char **mapfile);
size_t	so_long_strlen(char *str);
char	**ft_split(char *s, char c);
char	**readfromap(char **mapfile, int fd);
void posplayer(char **map, t_check *s);
void floodfill(char **map, int xp, int yp, int rows);


// LIBFT FUNCTIONS
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
char	*ft_strrchr(char *s, int c);
int	ft_strcmp(char *s1, char *s2);

#endif