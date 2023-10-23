

#include "../inc/cub3d.h"

int	line_count(char *str, t_main *ms)
{
	char	*temp;
	int		i;

	i = 0;
	if (ms->fd < 2)
		ms->fd = open_fd(str, ms);
	temp = "str";
	while (temp)
	{
		i++;
		temp = get_next_line(ms->fd);
		free(temp);
	}
	close(ms->fd);
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
	while (temp != NULL)
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
			if (!ms->game) // or (!ms->game || mlx_image_to_window(ms->mlx, ms->game, 0, 0) < 0)?
			{
				mlx_close_window(ms->mlx);
				error_and_exit(E_WIN, ms);
			}
			// make_background(ms->mlx, ms->colors, ms->bg);
			// 	from tuto: Even after the image is being displayed, we can still modify the buffer.
			// mlx_put_pixel(img, 0, 0, 0xFF0000FF); // but I think this is handled in make_background, right?
			set_raycasting_vars(ms->ray);
			
	
				raycasting(ms);

			set_raycasting_vars(ms->ray);

			raycasting(ms);
			mlx_key_hook(ms->mlx, &key_bindings, ms);
			mlx_loop(ms->mlx);
			mlx_terminate(ms->mlx);
		}
	}
	else
		perror(E_AC);
	clean_exit(ms);
	return (0);
	//search error_and_exit("") and change to macros
	//main_struct to ms in key bindings function
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
