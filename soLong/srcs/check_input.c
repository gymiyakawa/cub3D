/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:10:52 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/10 22:33:45 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_top_and_bottom_walls(t_map *map)
{
	int	i;

	i = ft_strlen(map->map[0]);
	map->x_max = ft_strlen(map->map[map->y_max - 1]);
	if (i > 40 || map->x_max > 40)
		error_and_message(2, map);
	else if (i - 1 != map->x_max)
	{
		error_and_message(3, map);
		return (1);
	}
	else
		map->x_max = 0;
	while (map->map[0][map->x_max] != '\n')
	{
		if (map->map[0][map->x_max] != '1')
			error_and_message(4, map);
		if (map->map[map->y_max - 1][map->x_max] != '1')
			error_and_message(4, map);
		map->x_max++;
	}
	return (0);
}

int	check_right_and_left_walls(t_map *map)
{
	int	i;
	int	j;

	i = ft_strlen(map->map[0]);
	j = ft_strlen(map->map[map->y_max - 1]) - 1;
	map->y = 1;
	while (map->map[map->y] != map->map[map->y_max - 1])
	{
		if (ft_strlen(map->map[map->y]) != i)
		{
			error_and_message(3, map);
		}
		map->y++;
	}
	map->y = 1;
	while (map->map[map->y] != map->map[map->y_max - 1])
	{
		if (map->map[map->y][0] != '1' || map->map[map->y][j] != '1')
		{
			error_and_message(4, map);
		}
		map->y++;
	}
	return (0);
}

int	check_map_inside(t_map *map)
{
	map->y = 1;
	while (map->map[map->y] != map->map[map->y_max - 1])
	{
		map->x = 0;
		while (map->map[map->y][map->x] != '\n')
		{
			if (ft_strchr("P", map->map[map->y][map->x]))
			{
				map->p_y = map->y;
				map->p_x = map->x;
			}
			else if (ft_strchr("E", map->map[map->y][map->x]))
			{
				map->e_y = map->y;
				map->e_x = map->x;
			}
			else if (!(ft_strchr("01CEP", map->map[map->y][map->x])))
				error_and_message(5, map);
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int	check_assets(t_map *map)
{
	map->y = 1;
	while (map->map[map->y] != map->map[map->y_max - 1])
	{
		map->x = 1;
		while (map->map[map->y][map->x] != '\n')
		{
			if (map->map[map->y][map->x] == 'P')
				map->player++;
			if (map->map[map->y][map->x] == 'C')
				map->coin++;
			if (map->map[map->y][map->x] == 'E')
				map->exit++;
			map->x++;
		}
		map->y++;
	}
	if (map->player == 0 || map->coin == 0 || map->exit == 0 || map->player > 1
		|| map->exit > 1)
	{
		error_and_message(5, map);
	}
	return (0);
}

int	check_map_extension(char *str)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".ber";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
	{
		ft_printf("You failed to deliver the goodies. Bye!\n");
		exit(0);
	}
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
		{
			ft_printf("No soup for you until you give me a proper map.\n");
			exit(0);
		}
		i--;
		j--;
	}
	return (0);
}
