
#include "../inc/cub3d.h"

void	init_texture(t_texture **texture, t_main *ms)
{
	*texture = ft_calloc(1, sizeof(t_texture));
	if ((*texture) == NULL)
		error_and_exit(E_MALLOC, ms);
	(*texture)->paths = ft_calloc(5, sizeof(char *));
	if ((*texture)->paths == NULL)
		error_and_exit(E_MALLOC, ms);
	(*texture)->paths[4] = NULL;
	(*texture)->mlx_textures = ft_calloc(4, sizeof(mlx_texture_t *));
	if ((*texture)->mlx_textures == NULL)
		error_and_exit(E_MALLOC, ms);
	(*texture)->mlx_textures[0] = NULL;
	(*texture)->mlx_textures[1] = NULL;
	(*texture)->mlx_textures[2] = NULL;
	(*texture)->mlx_textures[3] = NULL;
	(*texture)->text_x = 0;
	(*texture)->text_y = 0;
	(*texture)->text_num = 0;
	(*texture)->ms = ms;
	(*texture)->text_i = 0;
	return ;
}

void	init_map(t_map **map, t_main *ms)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_and_exit(E_MALLOC, ms);
	(*map)->maze = NULL; 
	(*map)->y_max = 0;
	(*map)->x_max = 0;
	(*map)->p_view = 0;
	(*map)->p_y = 0;
	(*map)->p_x = 0;
	(*map)->ms = ms;
	(*map)->i_first_line = 0;
	(*map)->last_line = 0;
	return ;
}
