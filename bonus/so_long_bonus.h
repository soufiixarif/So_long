#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <strings.h>
# include <mlx.h>
# include "/Users/sarif/Desktop/so_long_git/printf/ft_printf.h"

typedef struct s_data
{
	char	**map;
	int		p;
	int		c;
	int		e;
	int		n;
	int		xp;
	int		yp;
	int		xd;
	int		yd;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		rows;
	int		len;
	void	*cd;
	void	*od;
	void	*grnd;
	void	*pd;
	void	*pu;
	void	*pl;
	void	*pr;
	void	*rc;
	void	*yc;
	void	*wall;
	void	*n1;
	int		moves;
}	t_data;

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
// parsing
void	checkforone(t_data *d, char *line);
void	checkmapcomponent(char **map, t_data *d);
void	checkstructcontent(t_data *d, int n);
int		checklenoflines(char **gamap);
void	checkmapvalidity(t_data *d);
void	checklenmap(t_data *d, char **mapfile);
size_t	so_long_strlen(char *str);
char	**ft_split(char *s, char c);
char	**readfromap(char **mapfile, int fd);
void	posplayer(char **map, t_data *d);
void	floodfill(char **map, int xp, int yp, int rows);
// mlx
void	mlx(t_data *d);
void	xmp_to_img(t_data *d);
void	put_img(char **map, t_data *d, int kaycode);
int		moves(int keycode, t_data *d);
void	moveright(t_data *d, int j, int i, int keycode);
void	moveleft(t_data *d, int j, int i, int keycode);
void	moveup(t_data *d, int j, int i, int keycode);
void	movedown(t_data *d, int j, int i, int keycode);
int		close_win(t_data *d);
void	put_img_player(t_data *d, int keycode, int i, int j);
void	checkdoorpos(t_data *d);
void	opendoor(t_data *d);

// LIBFT FUNCTIONS
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
char	*ft_strrchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);

//TOOLS
char	**arrdup(char **map, int rows);
int		checkforcoin(char **map);
int		ft_free(char *s);
int		ft_2dfree(char **s);
void	printerror(t_data *d);

#endif