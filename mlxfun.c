#include "so_long.h"
void    put_img(char **map, t_data *d)
{
    int i;
    int j;

    j = 0;
    while(map[j])
    {
        i = 0;
        printf("%s\n",map[j]);
        while(map[j][i])
        {
            if (map[j][i] == '1')
                mlx_put_image_to_window(d->mlx, d->win, d->wall, i * 60, j * 60);
            else if (map[j][i] == '0')
                mlx_put_image_to_window(d->mlx, d->win, d->grnd, i * 60, j * 60);
            else if (map[j][i] == 'P')
                mlx_put_image_to_window(d->mlx, d->win, d->pd, i * 60, j * 60);
            else if (map[j][i] == 'C')
                mlx_put_image_to_window(d->mlx, d->win, d->yc, i * 60, j * 60);
            else if (map[j][i] == 'E')
                mlx_put_image_to_window(d->mlx, d->win, d->cd, i * 60, j * 60);
            i++;
        }
        j++;
    }

}
void    xmp_to_img(t_data *d)
{
    d->cd = mlx_xpm_file_to_image(d->mlx,"textures/doorClosed.xpm",&d->width,&d->height);
    d->od = mlx_xpm_file_to_image(d->mlx,"textures/doorOpened.xpm",&d->width,&d->height);
    d->grnd = mlx_xpm_file_to_image(d->mlx,"textures/ground.xpm",&d->width,&d->height);
    d->pd = mlx_xpm_file_to_image(d->mlx,"textures/playerDown.xpm",&d->width,&d->height);
    d->pu = mlx_xpm_file_to_image(d->mlx,"textures/playerUp.xpm",&d->width,&d->height);
    d->pl = mlx_xpm_file_to_image(d->mlx,"textures/playerLeft.xpm",&d->width,&d->height);
    d->pr = mlx_xpm_file_to_image(d->mlx,"textures/playerRight.xpm",&d->width,&d->height);
    d->rc = mlx_xpm_file_to_image(d->mlx,"textures/RedCollectible.xpm",&d->width,&d->height);
    d->yc = mlx_xpm_file_to_image(d->mlx,"textures/YellowCollectible.xpm",&d->width,&d->height);
    d->wall = mlx_xpm_file_to_image(d->mlx,"textures/wall.xpm",&d->width,&d->height);
}
void    mlx(char **map)
{
    t_data  d;

    d.rows = checklenoflines(map);
    d.len = ft_strlen(map[0]);
    printf("stora :%d o kol star fih %d\n",d.rows, d.len);
    d.mlx = mlx_init();
    d.win = mlx_new_window(d.mlx, 60 * d.len, 60 * d.rows, "So_long");
    xmp_to_img(&d);
    put_img(map,&d);

    mlx_loop(d.mlx);
}