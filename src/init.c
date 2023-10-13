#include "../inc/cub3d.h"

int	open_fd(char *str, t_main *ms)
{
	ms->fd = open(str, O_RDONLY);
	if (ms->fd < 0)
		error_and_exit(E_OPEN, ms);
	return(ms->fd);
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
	if (!*texture)
		error_and_exit(E_MALLOC, ms);
	(*texture)->n_tex.height = 0;
	(*texture)->n_tex.width = 0;
	(*texture)->n_tex.text_fd = 0;
	(*texture)->n_tex.path = NULL;
	(*texture)->s_tex.height = 0;
	(*texture)->s_tex.width = 0;
	(*texture)->s_tex.text_fd = 0;
	(*texture)->s_tex.path = NULL;
	(*texture)->e_tex.height = 0;
	(*texture)->e_tex.width = 0;
	(*texture)->e_tex.text_fd = 0;
	(*texture)->e_tex.path = NULL;
	(*texture)->w_tex.height = 0;
	(*texture)->w_tex.width = 0;
	(*texture)->w_tex.text_fd = 0;
	(*texture)->w_tex.path = NULL;
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
	(*map)->p_view = 0;
	(*map)->p_y = 0;
	(*map)->p_x = 0;
	//add more stuff as needed
	(*map)->ms = ms;
	return ;
}
