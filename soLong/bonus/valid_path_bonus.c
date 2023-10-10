/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:22:49 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/12 14:29:16 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	**duplicate_map(t_map *map)
{
	char	**dup_map;
	int		i;

	i = 0;
	dup_map = ft_calloc(sizeof(char *), (map->y_max + 1));
	if (!dup_map)
		return (NULL);
	while (i < map->y_max)
	{
		dup_map[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (dup_map);
}

int	exit_check(t_map *map, char **dup_map, int y, int x)
{
	if (dup_map[y][x + 1] == 'E')
		map->exit_check++;
	if (dup_map[y][x - 1] == 'E')
		map->exit_check++;
	if (dup_map[y + 1][x] == 'E')
		map->exit_check++;
	if (dup_map[y - 1][x] == 'E')
		map->exit_check++;
	return (0);
}

int	replace_assets(t_map *map, char **dup_map, int y, int x)
{
	exit_check(map, dup_map, y, x);
	if (ft_strchr("0C", dup_map[y][x + 1]))
	{
		dup_map[y][x + 1] = 'A';
		replace_assets(map, dup_map, y, x + 1);
	}
	if (ft_strchr("0C", dup_map[y][x - 1]))
	{
		dup_map[y][x - 1] = 'A';
		replace_assets(map, dup_map, y, x - 1);
	}
	if (ft_strchr("0C", dup_map[y + 1][x]))
	{
		dup_map[y + 1][x] = 'A';
		replace_assets(map, dup_map, y + 1, x);
	}
	if (ft_strchr("0C", dup_map[y - 1][x]))
	{
		dup_map[y - 1][x] = 'A';
		replace_assets(map, dup_map, y - 1, x);
	}
	return (0);
}

int	check_valid_path(t_map *map)
{
	char	**dup_map;
	int		y;
	int		x;

	y = 1;
	x = 1;
	dup_map = duplicate_map(map);
	replace_assets(map, dup_map, map->p_y, map->p_x);
	while (y < map->y_max)
	{
		x = 1;
		while (x < map->x_max)
		{
			if (dup_map[y][x] == 'C' || map->exit_check == 0)
			{
				free_table(dup_map);
				error_and_message(6, map);
			}
			x++;
		}
		y++;
	}
	free_table(dup_map);
	return (0);
}
