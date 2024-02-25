#include "so_long.h"
char **arrdup(char **map,int rows)
{
    char **mapp;
    int i;

    i = 0;
    mapp = (char **)malloc((rows + 1) * sizeof(char *));
    while(map[i])
    {
        mapp[i] = ft_strdup(map[i]);
        printf("%s\n",mapp[i]);
        i++;
    }
    mapp[i] = NULL;
    return (mapp);
}