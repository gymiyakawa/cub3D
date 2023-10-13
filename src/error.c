
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

void    *free_color(t_color *colors)
{
    if (colors->floor_ceiling)
    {
        colors->floor_ceiling[0] = x_free(colors->floor_ceiling[0]);
        colors->floor_ceiling[1] = x_free(colors->floor_ceiling[1]);
        colors->floor_ceiling = x_free(colors->floor_ceiling);
    }
    colors = x_free(colors);
    return(colors);
}

void    *free_texture(t_texture *t)
{
    //need to free images? see if there's a mlx function for it
	if (t->paths)
	{
		t->paths[0] = x_free(t->paths[0]);
		t->paths[1] = x_free(t->paths[1]);
		t->paths[2] = x_free(t->paths[2]);
		t->paths[3] = x_free(t->paths[3]);
		t->paths = x_free(t->paths);
	}
	if (t->mlx_textures)
	{
		t->mlx_textures[0] = x_free(t->mlx_textures[0]);
		t->mlx_textures[1] = x_free(t->mlx_textures[1]);
		t->mlx_textures[2] = x_free(t->mlx_textures[2]);
		t->mlx_textures[3] = x_free(t->mlx_textures[3]);
	}
    t = x_free(t);
    return(NULL);
}

void    *free_map(t_map *map)
{
    if (map->maze)
    {
        //liberar cada linha depois da leitura
        map->maze = x_free((*map).maze);
    }
    //need to do anything about void *win? check mlx functions
    map = x_free(map);
    return(map);
}

// void    *free_ms(t_main *ms);
void    *free_ms(t_main *ms)
{
    if (ms->filename)
        ms->filename = x_free(ms->filename);
    // mlx_terminate(ms->mlx); //keep this here?
    if (ms)
        ms = x_free(ms);
    return(NULL);
}