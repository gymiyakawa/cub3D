

#include "../inc/cub3d.h"

int	line_count(char *str, t_main *ms)
{
	char	*temp;
	int		i;

	i = 0;
	if (ms->fd < 2)
		ms->fd = open_fd(str, ms);
	// temp = get_next_line(ms->fd);
	temp = "str";
	while (temp)
	{
		i++;
		temp = get_next_line(ms->fd);
				// printf("BOOOOYA %d\n", i);
		free(temp);
	}
	close(ms->fd);
	// temp = x_free(temp);
									// printf("return from linecount %d\n", i);
	return (i);
}

char	**copy_file(char *str, t_main *ms)
{
	char 	**file_copy;
	char	*temp;
	int		i;

	i = 0;
											// printf("linecount: %d\n", ms->line_count);
	file_copy = ft_calloc(ms->line_count + 1, sizeof(char *));
	if(!file_copy)
		error_and_exit(E_MALLOC, ms);
	ms->fd = open_fd(str, ms);
	temp = get_next_line(ms->fd);
	while (temp != NULL)
	{
		file_copy[i] = ft_strdup(temp);
											// printf("filecopy[%d]: %s\n", i, file_copy[i]);
		i++;
		temp = x_free(temp);
		temp = get_next_line(ms->fd);
	}
	close(ms->fd);
	temp = x_free(temp);
	file_copy[i] = NULL;
											// printf("null terminating filecopy[%d]: %s\n", i, file_copy[i]);

											// print_str_array(file_copy);
	return (file_copy);
}

bool	parsing(char *str, t_main *ms)
{
	check_input_extension(str, ms);
	if (parse_map(ms) != 0)
		error_and_exit(E_PARS, ms);
	elements_check(ms); //commented this out to compile at home
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
			ms->game = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
			make_background(ms->mlx, ms->colors, ms->bg);

			set_raycasting_vars(ms->ray);

			raycasting(ms);
			mlx_key_hook(ms->mlx, &key_bindings, ms);
			mlx_loop(ms->mlx);
		}
	}
	else
		perror(E_AC);
	clean_exit(ms);
	return (0);
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
