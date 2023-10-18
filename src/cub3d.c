

#include "../inc/cub3d.h"

int	line_count(char *str, t_main *ms)
{
	char	*temp;
	int		i;

	i = 0;
	ms->fd = open_fd(str, ms);
	temp = get_next_line(ms->fd);
	while (temp)
	{
		i++;
		temp = get_next_line(ms->fd);
		free(temp);
	}
	close(ms->fd);
	free(temp);
	return (i);
}

char	**copy_file(char *str, t_main *ms)
{
	char 	**file_copy;
	char	*temp;
	int		i;

	i = 0;
	ms->line_count = line_count(str, ms);
	file_copy = ft_calloc(ms->line_count + 1, sizeof(char *));
	if(!file_copy)
		error_and_exit(E_MALLOC, ms);
	ms->fd = open_fd(str, ms);
	temp = get_next_line(ms->fd);
	while (temp)
	{
		file_copy[i] = ft_strdup(temp);
		i++;
		free(temp);
		temp = get_next_line(ms->fd);
	}
	close(ms->fd);
	free(temp);
	file_copy[i] = NULL;
	return (file_copy);
}

bool	parsing(char *str, t_main *ms)
{
	check_input_extension(str, ms);
	ms->file_copy = copy_file(str, ms);
	if (parse_colors(ms) != 0)
		error_and_exit(E_PARS, ms);
	if (parse_texture(ms) != 0)
		error_and_exit(E_PARS, ms);
	if (parse_map(ms) != 0)
		error_and_exit(E_PARS, ms);
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
			
			
		// 	// ms->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
		// 	// if (!ms->mlx)
		// 		// exit(0);
		// 	// map.win = mlx_new_window(map.mlx, (map.x_max * 64), (map.y_max * 64),
		// 	// 		"./so_long");
		// 	// if (!map.win)
		// 	// 	exit(0);
		// 	// if (assets_to_images(&map) == false)
		// 	// 	error_and_message(1, &map);
		// 	// images_to_screen(&map);
		// 	// mlx_key_hook(map.win, alicia_keys, &map); //same name; check parameters
		// 	// mlx_loop_hook(map.win, 17, 2, exit_win, &map); //change parameters //bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
		// 	// mlx_loop(map.mlx); //this seems fine; parameter is mlx_t* mlx
		// 	//free ms here?
			
			
			
		}
	}
	// mlx_terminate(ms->mlx);
	close_fds();
	return 0;
	// else
	// 	perror(AC_E);
	
	//spaces after maze are accepted or not?
	
	// add headers
	//norminette
	//test with valgrind and leaks
	// (void)ac;
	// (void)av;
}

void	close_fds(void)
{
	int i;

	i = 3;
	while (i++ < MAX_FILES)
		close(i);
	return;
}
//run valgrind on all parsing cases before proceeding


//In computer graphics (and 2D arrays in C), y usually references the row (vertical),
//and x references the column (horizontal). So m[y][x] implies m[row][column]. 
/*Rows are indeed horizontal and typically represent the y-coordinate. When you increment the row number, you go down vertically on the 2D grid.

Columns are vertical and typically represent the x-coordinate. When you increment the column number, you move horizontally to the right on the 2D grid.

So, m[y][x] is m[row][column], with y being the vertical coordinate (going down as it increases) and x being the horizontal coordinate (going right as it increases). 

This might seem somewhat inverted if you're used to Cartesian coordinates, but it's a common way to address 2D arrays and grids in computing because screens render from the top-left corner. So (0,0) is usually top-left.*/
