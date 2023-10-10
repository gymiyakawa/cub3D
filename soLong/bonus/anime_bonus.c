/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:06:12 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/13 14:37:33 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	enemy_moves(t_map *map)
{
	static int	counter = 0;
	static int	direction = 0;

	player_bounces(map);
	if (map->is_dead == false)
	{
		map->loop++;
		counter = map->loop % 4500;
		if (counter == 4000 && direction == 0)
			direction = move_left(map);
		else if (counter == 4000 && direction == 1)
			direction = move_right(map);
	}
	return (0);
}

int	player_bounces(t_map *map)
{
	if (map->is_dead == false)
	{
		map->loop2++;
		map->pinball = map->loop2 % 4500;
		player_bounces_ctd(map);
	}
	return (0);
}

int	player_bounces_ctd(t_map *map)
{
	if (map->pinball == 4000 && map->img == 0)
	{
		map->img++;
		mlx_put_image_to_window(map->mlx, map->win, map->img_p, map->p_x * 64,
			map->p_y * 64);
	}
	else if (map->pinball == 4000 && map->img == 1)
	{
		map->img++;
		mlx_put_image_to_window(map->mlx, map->win, map->img_p1, map->p_x * 64,
			map->p_y * 64);
	}
	else if (map->pinball == 4000 && map->img == 2)
	{
		map->img++;
		mlx_put_image_to_window(map->mlx, map->win, map->img_p2, map->p_x * 64,
			map->p_y * 64);
	}
	else if (map->pinball == 4000 && map->img == 3)
	{
		map->img = 0;
		mlx_put_image_to_window(map->mlx, map->win, map->img_p3, map->p_x * 64,
			map->p_y * 64);
	}
	return (0);
}

int	move_right(t_map *map)
{
	if (map->map[map->x_y][map->x_x + 1] == '0')
	{
		map->map[map->x_y][map->x_x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img_z, map->x_x * 64,
			map->x_y * 64);
		map->map[map->x_y][map->x_x + 1] = 'X';
		mlx_put_image_to_window(map->mlx, map->win, map->img_x, (map->x_x + 1)
			* 64, map->x_y * 64);
		map->x_x++;
		return (1);
	}
	if (map->map[map->x_y][map->x_x + 1] == 'P')
		end_game(map, 1);
	return (0);
}

int	move_left(t_map *map)
{
	if (map->map[map->x_y][map->x_x - 1] == '0')
	{
		map->map[map->x_y][map->x_x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img_z, map->x_x * 64,
			map->x_y * 64);
		map->map[map->x_y][map->x_x - 1] = 'X';
		mlx_put_image_to_window(map->mlx, map->win, map->img_x, (map->x_x - 1)
			* 64, map->x_y * 64);
		map->x_x--;
		return (0);
	}
	if (map->map[map->x_y][map->x_x - 1] == 'P')
		end_game(map, 1);
	return (1);
}
