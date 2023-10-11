

#include "../inc/cub3d.h"

// int	check_map(t_main *data)
// {
// 	check_top_and_bottom_walls(data->map);
// 	check_right_and_left_walls(data->map);
// 	check_map_inside(data->map);
// 	check_assets(data->map);
// 	check_valid_path(data->map);
// 	return (0);
// }

// int	open_and_allocate_map(char *str, t_main *data)
// {//work on this function
// 	char	*temp;
// 	int		fd;

// 	data->map = ft_calloc(sizeof(char *), 20);
// 	fd = open(str, O_RDONLY);
// 	if (fd == -1)
// 		error_and_message(1, data->map); //or error_and_exit?
// 	temp = get_next_line(fd);
// 	while (temp && data->map->y_max < 20)
// 	{
// 		data->map[map->y_max] = ft_strdup(temp);
// 		data->map->y_max++;
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	close(fd);
// 	free(temp);
// 	if (map->y_max >= 20)
// 		error_and_message(2, map);
// 	return (0);
// }

int	check_input_extension(char *str, t_main *data)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".cub";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
        error_and_exit(MAP_E, data);
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
		    error_and_exit(MAP_E, data);
		i--;
		j--;
	}
	return (0);
}
