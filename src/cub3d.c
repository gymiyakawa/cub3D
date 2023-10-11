

#include "../inc/cub3d.h"

bool	parsing(char *str, t_main *data)
{
	check_input_extension(str, data);
	// open_and_allocate_map(str, data);
	check_map(data);
	return (TRUE);
}

int	initialize_data(t_main *data)
{
	data->colors = malloc(sizeof(t_colors));
	if (!data->colors)
		error_and_exit(MAL_E, data);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		error_and_exit(MAL_E, data); // would need to free colors too - maybe add code to the function?	
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
		error_and_exit(MAL_E, data); // would need to free colors and map too - maybe add code to the function?	
	// map->pixel = 0;
	// map->y_max = 0;
	// map->x_max = 0;
	// map->flag = 0;
	// map->y = 0;
	// map->x = 0;
	// map->p_y = 0;
	// map->p_x = 0;
	// map->e_y = 0;
	// map->e_x = 0;
	return (0);
}

//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_main	data;
	
	// if (ac == 2)
	{
		initialize_data(&data);
		if (parsing(av[1], &data))
		{
			data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
			if (!data.mlx)
				exit(0);
			// map.win = mlx_new_window(map.mlx, (map.x_max * 64), (map.y_max * 64),
			// 		"./so_long");
			// if (!map.win)
			// 	exit(0);
			// if (assets_to_images(&map) == false)
			// 	error_and_message(1, &map);
			// images_to_screen(&map);
			// mlx_key_hook(map.win, alicia_keys, &map); //same name; check parameters
			// mlx_loop_hook(map.win, 17, 2, exit_win, &map); //change parameters //bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
			// mlx_loop(map.mlx); //this seems fine; parameter is mlx_t* mlx
			//free data here?
		}
	}
	mlx_terminate();
	return (0);
	// else
	// 	perror(AC_E);
	// add headers
	//norminette
	//test with valgrind and leaks
}
