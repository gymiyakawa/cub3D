

#include "../inc/cub3d.h"

// int	check_map(t_main *ms)
// {
// 	check_top_and_bottom_walls(ms->map);
// 	check_right_and_left_walls(ms->map);
// 	check_map_inside(ms->map);
// 	check_assets(ms->map);
// 	check_valid_path(ms->map);
// 	return (0);
// }

int	open_and_allocate_map(char *str, t_main *ms)
{
	char	*temp;
	int		fd;

	// ms->map = ft_calloc(sizeof(char *), MAX_WIDTH);
	// if (!ms->map)
	// 	error_and_exit(E_MALLOC, ms);
	// ms->map->maze = ft_calloc(sizeof(char **), 1);
	// if (!ms->map->maze)
	// 	error_and_exit(E_MALLOC, ms); //should free map here as well use code?
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_and_exit(E_OPEN, ms); //free previously malloced stuff ? use code?
	temp = get_next_line(fd);
	// printf("Y MAX: %d\n", ms->map->y_max);
	while (temp && ms->map->y_max < MAX_WIDTH)
	{
		ms->map->maze[ms->map->y_max] = ft_strdup(temp);
		ms->map->y_max++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	free(temp);
	if (ms->map->y_max >= MAX_WIDTH)
		error_and_exit(E_BIG, ms); // or error and error to free ms?
	return (0);
}

int	check_input_extension(char *str, t_main *ms)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".cub";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
        error_and_exit(E_MAP, ms);
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
		    error_and_exit(E_MAP, ms);
		i--;
		j--;
	}
	return (0);
}


// int	check_top_and_bottom_walls(t_map *map)
// {
// 	int	i;

// 	i = ft_strlen(map->maze[0]);
// 	map->x_max = ft_strlen(map->maze[map->y_max - 1]);
// 	if (i > 40 || map->x_max > 40)
// 		error_and_message(2, map);
// 	else if (i - 1 != map->x_max)
// 	{
// 		error_and_message(3, map);
// 		return (1);
// 	}
// 	else
// 		map->x_max = 0;
// 	while (map->maze[0][map->x_max] != '\n')
// 	{
// 		if (map->maze[0][map->x_max] != '1')
// 			error_and_message(4, map);
// 		if (map->maze[map->y_max - 1][map->x_max] != '1')
// 			error_and_message(4, map);
// 		map->x_max++;
// 	}
// 	return (0);
// }

// int	check_right_and_left_walls(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = ft_strlen(map->maze[0]);
// 	j = ft_strlen(map->maze[map->y_max - 1]) - 1;
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		if (ft_strlen(map->maze[map->y]) != i)
// 		{
// 			error_and_message(3, map);
// 		}
// 		map->y++;
// 	}
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		if (map->maze[map->y][0] != '1' || map->maze[map->y][j] != '1')
// 		{
// 			error_and_message(4, map);
// 		}
// 		map->y++;
// 	}
// 	return (0);
// }

// int	check_map_inside(t_map *map)
// {
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		map->x = 0;
// 		while (map->maze[map->y][map->x] != '\n')
// 		{
// 			if (ft_strchr("P", map->maze[map->y][map->x]))
// 			{
// 				map->p_y = map->y;
// 				map->p_x = map->x;
// 			}
// 			else if (ft_strchr("E", map->maze[map->y][map->x]))
// 			{
// 				map->e_y = map->y;
// 				map->e_x = map->x;
// 			}
// 			else if (!(ft_strchr("01CEP", map->maze[map->y][map->x])))
// 				error_and_message(5, map);
// 			map->x++;
// 		}
// 		map->y++;
// 	}
// 	return (0);
// }

// int	check_assets(t_map *map)
// {
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		map->x = 1;
// 		while (map->maze[map->y][map->x] != '\n')
// 		{
// 			if (map->maze[map->y][map->x] == 'P')
// 				map->player++;
// 			if (map->maze[map->y][map->x] == 'C')
// 				map->coin++;
// 			if (map->maze[map->y][map->x] == 'E')
// 				map->exit++;
// 			map->x++;
// 		}
// 		map->y++;
// 	}
// 	if (map->player == 0 || map->coin == 0 || map->exit == 0 || map->player > 1
// 		|| map->exit > 1)
// 	{
// 		error_and_message(5, map);
// 	}
// 	return (0);
// }