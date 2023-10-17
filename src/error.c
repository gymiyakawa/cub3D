
#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *ms)
{
                        // printf("MS: %p\n", ms);
    printf("Error\n");
    printf("%s\n",str);
    if (ms->colors)
        ms->colors = free_color(ms->colors);
    if (ms->texture)
        ms->texture = free_texture(ms->texture);
    if (ms->map)
        ms->map = free_map(ms->map);
    if(ms)  
        ms = free_ms(ms);
    exit(1);
}


