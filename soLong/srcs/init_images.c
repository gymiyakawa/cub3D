/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:00:52 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/10 22:35:43 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	open_image(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 1)
		return (false);
	close(fd);
	return (true);
}

int	check_image_path(t_map *map)
{
	if (open_image("./assets/player.xpm") == false
		|| open_image("./assets/coin.xpm") == false
		|| open_image("./assets/exit.xpm") == false
		|| open_image("./assets/exit2.xpm") == false
		|| open_image("./assets/walls.xpm") == false
		|| open_image("./assets/floor.xpm") == false)
	{
		error_and_message(7, map);
	}
	return (0);
}

bool	assets_to_images(t_map *map)
{
	check_image_path(map);
	map->img_p = mlx_xpm_file_to_image(map->mlx, "./assets/player.xpm",
			&map->img_width, &map->img_height);
	map->img_c = mlx_xpm_file_to_image(map->mlx, "./assets/coin.xpm",
			&map->img_width, &map->img_height);
	map->img_e = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm",
			&map->img_width, &map->img_height);
	map->img_e2 = mlx_xpm_file_to_image(map->mlx, "./assets/exit2.xpm",
			&map->img_width, &map->img_height);
	map->img_w = mlx_xpm_file_to_image(map->mlx, "./assets/walls.xpm",
			&map->img_width, &map->img_height);
	map->img_z = mlx_xpm_file_to_image(map->mlx, "./assets/floor.xpm",
			&map->img_width, &map->img_height);
	if (map->img_p == NULL || map->img_c == NULL || map->img_e == NULL
		|| map->img_w == NULL || map->img_z == NULL)
		return (false);
	return (true);
}

int	images_to_screen(t_map *map)
{
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == 'P')
				display_image(map, 'P');
			else if (map->map[map->y][map->x] == 'C')
				display_image(map, 'C');
			else if (map->map[map->y][map->x] == 'E')
				display_image(map, 'E');
			else if (map->map[map->y][map->x] == '1')
				display_image(map, '1');
			else if (map->map[map->y][map->x] == '0')
				display_image(map, '0');
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int	display_image(t_map *map, int asset)
{
	if (asset == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img_p,
			map->x * 64, map->y * 64);
	else if (asset == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img_c,
			map->x * 64, map->y * 64);
	else if (asset == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->img_e,
			map->x * 64, map->y * 64);
	else if (asset == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img_w,
			map->x * 64, map->y * 64);
	else if (asset == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_z,
			map->x * 64, map->y * 64);
	return (0);
}
