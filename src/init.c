#include "../inc/cub3d.h"

void	init_structs(t_main *main)
{
	
	
	init_color(main->colors);
}

void	init_color(t_color *color)
{
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