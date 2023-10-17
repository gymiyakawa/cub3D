
#include "../inc/cub3d.h"

void	key_bindings(mlx_key_data_t input, void *ms)
{
	if (input.key == MLX_KEY_ESCAPE)
		clean_exit(ms);
	
	return ;
}

void	make_background(mlx_t *mlx, t_color *c, t_background *bg)
{
	uint32_t	x;
	uint32_t	y;

	bg->floor = mlx_new_image(mlx, MAX_WIDTH, MAX_HEIGHT);
	x = -1;
	while (++x < bg->floor->width)
	{
		y = -1;
		while (++y < bg->floor->height)
		{
			mlx_put_pixel(bg->floor, x, y, c->f_color);
		}
	}
	int32_t floor_inst;
	floor_inst = mlx_image_to_window(mlx, bg->floor, 0, 0);
	
	// bg->ceiling = mlx_new_image(mlx, MAX_WIDTH, MAX_HEIGHT);
	
}
