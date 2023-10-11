#include "../inc/cub3d.h"


void	init_ms(t_main *ms)
{
	ms = malloc(sizeof(t_main));
	if (!ms)
		error_and_exit(E_MALLOC, ms);
	// ms->map = malloc(sizeof(t_map));
	// if (!ms->map)
	// 	error_and_exit(E_MALLOC, ms); // would need to free colors too - maybe add code to the function?	
	// ms->texture = malloc(sizeof(t_texture));
	// if (!ms->texture)
	// 	error_and_exit(E_MALLOC, ms); // would need to free colors and map too - maybe add code to the function?	
	// map->pixel = 0;
	// ms->map->y_max = 0;
	// map->x_max = 0;
	// map->flag = 0;
	// map->y = 0;
	// map->x = 0;
	// map->p_y = 0;
	// map->p_x = 0;
	// map->e_y = 0;
	// map->e_x = 0;
	init_color(ms->colors);
	init_texture(ms->texture);
	init_map(&ms->map);
	return ;
}

void	init_color(t_color *color)
{
	color = malloc(sizeof(t_color));
	if (!color)
		error_and_exit(E_MALLOC, color->ms);	
	color->f_red = 0;
	color->f_blue = 0;
	color->f_green = 0;
	color->c_red = 0;
	color->c_blue = 0;
	color->c_green = 0;
	color->f_color = 0;
	color->c_color = 0;
	return ;
}

void	init_texture(t_texture *texture)
{
	(void)texture;
	return ;
}

void	init_map(t_map **map)
{
	(*map) = ft_calloc(sizeof(char *), MAX_WIDTH);
	if (!map)
		error_and_exit(E_MALLOC, (*map)->ms);
	(*map)->maze = ft_calloc(sizeof(char **), 1);
	if (!(*map)->maze)
		error_and_exit(E_MALLOC, (*map)->ms); //should free map here as well /use code?
	(*map)->y_max = 0;
	return ;
}