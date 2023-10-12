#include "../inc/cub3d.h"

void	init_ms(t_main **ms, char **av)
{
	*ms = ft_calloc(1, sizeof(t_main));
	if (!*ms)
		error_and_exit(E_MALLOC, *ms);
	(*ms)->filename = ft_strdup(av[1]);
	(*ms)->fd = open(av[1], O_RDONLY);
	if ((*ms)->fd < 0)
		error_and_exit(E_OPEN, *ms);
	init_color(&(*ms)->colors);
	init_texture(&(*ms)->texture);
	init_map(&(*ms)->map);
	return ;
}

void	init_color(t_color **color)
{
	*color = malloc(sizeof(t_color));
	if (!*color)
		error_and_exit(E_MALLOC, (*color)->ms);
	(*color)->floor_ceiling = ft_calloc(2, sizeof(char *));
	if (!(*color)->floor_ceiling)
		error_and_exit(E_MALLOC, (*color)->ms);
	(*color)->f_red = 0;
	(*color)->f_blue = 0;
	(*color)->f_green = 0;
	(*color)->c_red = 0;
	(*color)->c_blue = 0;
	(*color)->c_green = 0;
	(*color)->f_color = 0;
	(*color)->c_color = 0;
	return ;
}

void	init_texture(t_texture **texture)
{
	(void)texture;
	return ;
}

void	init_map(t_map **map)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_and_exit(E_MALLOC, (*map)->ms);
	(*map)->maze = ft_calloc(1, sizeof(char **));
	if (!(*map)->maze)
		error_and_exit(E_MALLOC, (*map)->ms); 
	(*map)->y_max = 0;
	(*map)->x_max = 0;
	return ;
}