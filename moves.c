#include "so_long.h"
void moveright(t_data *d,char **map)
{
    int i = 0;
    int j = 0;
    while (map[j])
    {
        i = 0;
        while (map[j][i])
        {
            if (map[j][i] == 'P')
            {
                if (map[j][i + 1] != '1' || map[j][i + 1] != 'E')
                {
                    
                }
            }
        }
    }
}