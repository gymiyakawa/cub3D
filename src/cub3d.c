#include "../inc/cub3d.h"

//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
int	main(int ac, char **av)
{
	t_main *main;
	
	main = x_calloc(sizeof(t_main));
	
	init_structs(main, av);
			(void)ac;
			(void)av;
			main->fd = open(av[1], O_RDONLY);
			if (main->fd < 0)
				return (1);
		if (parse_colors(main) != 0)
			error_and_exit("parsing error\n", main);
	
		print_color_struct(main->colors);
	return 0;
}

