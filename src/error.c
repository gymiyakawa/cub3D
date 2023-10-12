/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:29 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/12 16:30:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *ms)
{
    printf("Error\n");
    printf("%s\n",str);
				(void)ms; // delete this once free ms is functional
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

void    *free_texture(t_texture *texture)
{
    //need to free images? see if there's a mlx function for it
	texture->n_tex.path = x_free(texture->n_tex.path);
	texture->s_tex.path = x_free(texture->s_tex.path);
	texture->w_tex.path = x_free(texture->w_tex.path);
	texture->e_tex.path = x_free(texture->e_tex.path);
    texture = x_free(texture);
    return(texture);
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

void    *free_ms(t_main *ms)
{
    if (ms->filename)
        ms->filename = x_free(ms->filename);
    // mlx_terminate(ms->mlx); //keep this here?
    ms = x_free(ms);
    return(ms);
}