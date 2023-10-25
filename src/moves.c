/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:15:16 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/25 13:15:18 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_ahead(t_ray *ray)
{
	char	**maze;

	maze = ray->ms->map->maze;
	if (maze[(int)ray->py][(int)(ray->px + ray->dir_x * \
		(ray->mov_speed + 0.1))] != '1')
		ray->px += ray->dir_x * ray->mov_speed;
	if (maze[(int)(ray->py + ray->dir_y * \
		(ray->mov_speed + 0.1))][(int)ray->px] != '1')
		ray->py += ray->dir_y * ray->mov_speed;
}

void	move_back(t_ray *ray)
{
	char	**maze;

	maze = ray->ms->map->maze;
	if (maze[(int)ray->py][(int)(ray->px - ray->dir_x * \
		ray->mov_speed)] != '1')
		ray->px -= ray->dir_x * ray->mov_speed;
	if (maze[(int)(ray->py - ray->dir_y * \
		ray->mov_speed)][(int)ray->px] != '1')
		ray->py -= ray->dir_y * ray->mov_speed;
}

void	move_right(t_ray *ray)
{
	char	**maze;

	maze = ray->ms->map->maze;
	if (maze[(int)ray->py][(int)(ray->px + ray->plane_x * \
		ray->mov_speed)] != '1')
		ray->px += ray->plane_x * ray->mov_speed;
	if (maze[(int)(ray->py + ray->plane_y * \
		ray->mov_speed)][(int)ray->px] != '1')
		ray->py += ray->plane_y * ray->mov_speed;
}

void	move_left(t_ray *ray)
{
	char	**maze;

	maze = ray->ms->map->maze;
	if (maze[(int)ray->py][(int)(ray->px - ray->plane_x * \
		ray->mov_speed)] != '1')
		ray->px -= ray->plane_x * ray->mov_speed;
	if (maze[(int)(ray->py - ray->plane_y * \
		ray->mov_speed)][(int)ray->px] != '1')
		ray->py -= ray->plane_y * ray->mov_speed;
}
