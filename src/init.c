#include "../inc/cub3d.h"

int	open_fd(char *str, t_main *ms)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_and_exit(E_OPEN, ms);
	return(fd);
}

void	init_ms(t_main **ms, char **av)
{
	*ms = ft_calloc(1, sizeof(t_main));
	if (!*ms)
		error_and_exit(E_MALLOC, *ms);
	(*ms)->filename = ft_strdup(av[1]);
	(*ms)->fd = open_fd(av[1], *ms);
	init_color(&(*ms)->colors, *ms);
	init_texture(&(*ms)->texture, *ms);
	init_map(&(*ms)->map, *ms);
	return ;
}

void	init_color(t_color **color, t_main *ms)
{
	*color = ft_calloc(1, sizeof(t_color));
	if (!*color)
		error_and_exit(E_MALLOC, ms);
	(*color)->floor_ceiling = ft_calloc(2, sizeof(char *));
	if (!(*color)->floor_ceiling)
		error_and_exit(E_MALLOC, ms);
	(*color)->f_red = 0;
	(*color)->f_blue = 0;
	(*color)->f_green = 0;
	(*color)->c_red = 0;
	(*color)->c_blue = 0;
	(*color)->c_green = 0;
	(*color)->f_color = 0;
	(*color)->c_color = 0;
	(*color)->ms = ms;
	return ;
}

void	init_texture(t_texture **texture, t_main *ms)
{
	*texture = ft_calloc(1, sizeof(t_texture));
	if ((*texture) == NULL)
		error_and_exit(E_MALLOC, ms);
	(*texture)->paths = ft_calloc(4, sizeof(char *));
	if ((*texture)->paths == NULL)
		error_and_exit(E_MALLOC, ms);
	(*texture)->mlx_textures = ft_calloc(4, sizeof(mlx_texture_t *));
	// if ((*texture)->mlx_textures)		// how to check malloc? currently flaggig error
	// 	error_and_exit(E_MALLOC, ms);
	(*texture)->ms = ms;
	return ;
}

void	init_map(t_map **map, t_main *ms)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_and_exit(E_MALLOC, ms);
	(*map)->maze = ft_calloc(1, sizeof(char **));
	if (!(*map)->maze)
		error_and_exit(E_MALLOC, ms); 
	(*map)->y_max = 0;
	(*map)->x_max = 0;
	(*map)->ms = ms;
	return ;
}
