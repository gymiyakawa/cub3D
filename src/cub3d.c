

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
	file_copy = ft_calloc(ms->line_count + 1, sizeof(char *));
	if(!file_copy)
		error_and_exit(E_MALLOC, ms);
	ms->fd = open_fd(str, ms);
	temp = get_next_line(ms->fd);
	while (temp)
	{
		file_copy[i] = ft_strdup(temp);
		i++;
		temp = x_free(temp);
		temp = get_next_line(ms->fd);
	}
	close(ms->fd);
	temp = x_free(temp);
	file_copy[i] = NULL;
	return (file_copy);
}

bool	parsing(char *str, t_main *ms)
{
	check_input_extension(str, ms);
	if (parse_map(ms) != 0)
		error_and_exit(E_PARS, ms);
	elements_check(ms);
	if (parse_colors(ms) != 0)
		error_and_exit(E_PARS, ms);
	if (parse_texture(ms) != 0)
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
			mlx_set_setting(MLX_STRETCH_IMAGE, true);
			ms->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
			if (!ms->mlx)
				error_and_exit(E_MLX_INI, ms);
			make_background(ms->mlx, ms->colors, ms->bg);
			
			
			
			// for testing purposes only, feel free to delete/relocate
			// int test_map[] = {
			// 1, 1, 1, 1, 1, 1, 1, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 0, 0, 0, 0, 0, 0, 1,
			// 1, 1, 1, 1, 1, 1, 1, 1,
			// };
			//  ms->map->test_map = test_map;
			// raycasting(ms->ray, ms->plyr);
	
			// ms->map->m_img = make_test_map_img(ms, ms->map);
			// int32_t testmap = mlx_image_to_window(ms->mlx, ms->map->m_img, 0, 0);
			// 						printf("did it get to here?\n");
			// (void)testmap;
		
		
			mlx_key_hook(ms->mlx, &key_bindings, ms);
			mlx_loop(ms->mlx);
		}
	}
	else
		perror(E_AC);
	clean_exit(ms);
	return 0;
	// add headers
	//norminette
	//test with valgrind and leaks
}


void	close_fds(void)
{
	int i;

	i = 3;
	while (i++ < MAX_FILES)
		close(i);
	return;
}
