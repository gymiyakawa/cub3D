/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:23:03 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/12 15:32:13 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(t_map *map)
{
	check_top_and_bottom_walls(map);
	check_right_and_left_walls(map);
	check_map_inside(map);
	check_assets(map);
	check_valid_path(map);
	return (0);
}

int	end_game(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_string_put(map->mlx, map->win, 62, 80, 0xFFFAFAFA, "You won!\n");
	ft_printf("Congrats! You are rich!\n");
	map->is_dead = true;
	return (0);
}

int	open_and_allocate_map(char *str, t_map *map)
{
	char	*temp;
	int		fd;

	map->map = ft_calloc(sizeof(char *), 20);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_and_message(1, map);
	temp = get_next_line(fd);
	while (temp && map->y_max < 20)
	{
		map->map[map->y_max] = ft_strdup(temp);
		map->y_max++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	free(temp);
	if (map->y_max >= 20)
		error_and_message(2, map);
	return (0);
}

int	initialize_map(t_map *map)
{
	map->is_dead = false;
	map->pixel = 0;
	map->y_max = 0;
	map->x_max = 0;
	map->flag = 0;
	map->y = 0;
	map->x = 0;
	map->p_y = 0;
	map->p_x = 0;
	map->e_y = 0;
	map->e_x = 0;
	map->exit_check = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		initialize_map(&map);
		check_map_extension(argv[1]);
		open_and_allocate_map(argv[1], &map);
		check_map(&map);
		map.mlx = mlx_init();
		if (!map.mlx)
			exit(0);
		map.win = mlx_new_window(map.mlx, (map.x_max * 64), (map.y_max * 64),
				"./so_long");
		if (!map.win)
			exit(0);
		if (assets_to_images(&map) == false)
			error_and_message(1, &map);
		images_to_screen(&map);
		mlx_key_hook(map.win, alicia_keys, &map);
		mlx_hook(map.win, 17, 2, exit_win, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_printf("Gimme a map I can use, buddy.\n");
}
