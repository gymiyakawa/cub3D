/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:04:20 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/12 14:29:05 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	bonus_messages(t_map *map)
{
	char	*str;

	map->pixel_max = map->x_max * 64;
	str = ft_itoa(map->moves);
	map->pixel = 0;
	mlx_put_image_to_window(map->mlx, map->win, map->img_w, 62, 0);
	while (map->pixel < map->pixel_max)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_w, map->pixel, 0);
		map->pixel += 64;
	}
	mlx_string_put(map->mlx, map->win, 2, 50, 0x00FFFFFF, "Moves: ");
	mlx_string_put(map->mlx, map->win, 62, 50, 0x00FFFFFF, str);
	free(str);
	map->flag = 0;
	return (0);
}

int	coin_eaten(t_map *map, int y, int x)
{
	map->coin--;
	map->map[y][x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->img_p, x * 64, y * 64);
	if (map->coin == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_e2, map->e_x * 64,
			map->e_y * 64);
		return (0);
	}
	return (0);
}

bool	now_we_move(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1')
	{
		if (map->map[y][x] == 'X')
		{
			end_game(map, 1);
			return (false);
		}
		else if (map->map[y][x] == 'C')
			coin_eaten(map, y, x);
		else if (map->map[y][x] == 'E')
		{
			if (map->coin == 0)
				end_game(map, 2);
			else if (map->coin > 0 && map->flag == 0)
			{
				mlx_string_put(map->mlx, map->win, 2, 20, 0x00FFFFFF,
					"Gotta get all the goodies.\n");
				map->flag = 1;
			}
			return (false);
		}
		now_we_move_ctd(map, y, x);
		return (true);
	}
	return (false);
}

bool	now_we_move_ctd(t_map *map, int y, int x)
{
	map->map[y][x] = 'P';
	mlx_put_image_to_window(map->mlx, map->win, map->img_p, x * 64, y * 64);
	mlx_put_image_to_window(map->mlx, map->win, map->img_z, map->p_x * 64,
		map->p_y * 64);
	map->map[map->p_y][map->p_x] = '0';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	bonus_messages(map);
	return (true);
}

int	alicia_keys(int key, t_map *map)
{
	if (key == 17 || key == 53)
		exit(0);
	if (map->is_dead == true)
		return (0);
	if (key == 13 || key == 6 || key == 126)
	{
		if (now_we_move(map, map->p_y - 1, map->p_x) == true)
			map->p_y--;
	}
	if (key == 0 || key == 12 || key == 123)
	{
		if (now_we_move(map, map->p_y, map->p_x - 1) == true)
			map->p_x--;
	}
	if (key == 1 || key == 125)
	{
		if (now_we_move(map, map->p_y + 1, map->p_x) == true)
			map->p_y++;
	}
	if (key == 2 || key == 124)
	{
		if (now_we_move(map, map->p_y, map->p_x + 1) == true)
			map->p_x++;
	}
	return (0);
}
