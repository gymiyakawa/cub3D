

#include "../inc/cub3d.h"

bool	parsing(char *str, t_main *ms)
{
	// check_input_extension(str, ms);
	//color & texture parsing
	//keep a pointer to end of color & texture input and send it to the next function?
	// open_and_allocate_map(str, ms);
	// check_map(ms);

	(void)str;
	if (parse_colors(ms) != 0)
		error_and_exit("parsing error\n", ms);
	print_color_struct(ms->colors);
	return (TRUE);
}

//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
int	main(int ac, char **av)
{
	t_main *ms;
	
	ms = NULL;
	if (ac == 2)
	{
		init_ms(&ms, av);
		if (parsing(av[1], ms))
		{
			// ms->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
			// if (!ms->mlx)
				// exit(0);
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
			//free ms here?
		}
	}
	// mlx_terminate(ms->mlx);

	return 0;
}
	// else
	// 	perror(AC_E);
	// add headers
	//norminette
	//test with valgrind and leaks
	// (void)ac;
	// (void)av;
