/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:15:53 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/11/02 12:16:49 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_exit(t_main *ms)
{
	if (ms->mlx)
		mlx_terminate(ms->mlx);
	close_fds();
	if (ms->texture)
		ms->texture = free_texture(ms->texture);
	if (ms->colors)
		ms->colors = free_color(ms->colors);
	if (ms->map)
		ms->map = free_map(ms->map);
	if (ms->bg)
		ms->bg = x_free(ms->bg);
	if (ms->ray)
		ms->ray = x_free(ms->ray);
	if (ms)
		ms = free_ms(ms);
	return ;
}

void	*free_map(t_map *map)
{
	if (map->maze)
		map->maze = ft_free_array(map->maze);
	map = x_free(map);
	return (map);
}

void	*free_ms(t_main *ms)
{
	if (ms->file_copy)
		ms->file_copy = ft_free_array(ms->file_copy);
	if (ms->valid_lines)
		ms->valid_lines = ft_free_array(ms->valid_lines);
	if (ms)
		ms = x_free(ms);
	return (NULL);
}

void	*free_color(t_color *colors)
{
	if (colors->floor_ceiling)
	{
		colors->floor_ceiling[0] = x_free(colors->floor_ceiling[0]);
		colors->floor_ceiling[1] = x_free(colors->floor_ceiling[1]);
		colors->floor_ceiling = x_free(colors->floor_ceiling);
	}
	colors = x_free(colors);
	return (NULL);
}

void	*free_texture(t_texture *t)
{
	if (t->paths)
		t->paths = ft_free_array(t->paths);
	if (t->mlx_textures)
	{
		if (t->mlx_textures[0])
			mlx_delete_texture(t->mlx_textures[0]);
		if (t->mlx_textures[1])
			mlx_delete_texture(t->mlx_textures[1]);
		if (t->mlx_textures[2])
			mlx_delete_texture(t->mlx_textures[2]);
		if (t->mlx_textures[3])
			mlx_delete_texture(t->mlx_textures[3]);
		t->mlx_textures = x_free(t->mlx_textures);
	}
	t = x_free(t);
	return (NULL);
}
