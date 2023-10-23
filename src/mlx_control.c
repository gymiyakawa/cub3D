
#include "../inc/cub3d.h"

void	key_bindings(mlx_key_data_t input, void *main_struct)
{
	t_main	*ms;

	ms = main_struct;
	if (input.key == MLX_KEY_ESCAPE) //input.key or mlx_is_key_down??
		mlx_close_window(ms->mlx);
	if (input.key == MLX_KEY_W)
	{
		// go up; 
	}
	// if (input.key == MLX_KEY_UP)
	// 	ms->ray->px = 

	
	raycasting(ms);
	return ;
}


// will probably need to keep track of the return variable from mlx_new_image. 
void	make_background(mlx_t *mlx, t_color *c, t_background *bg) //commented this out to compile at home
{
	uint32_t	x;
	uint32_t	y;

	bg->ceiling = mlx_new_image(mlx, WIDTH, mlx->height / 2);
	x = -1;
	while (++x < bg->ceiling->width)
	{
		y = -1;
		while (++y < bg->ceiling->height)
			mlx_put_pixel(bg->ceiling, x, y, c->c_color);
	}
	int32_t ceiling_inst;
	ceiling_inst = mlx_image_to_window(mlx, bg->ceiling, 0, 0);
	bg->floor = mlx_new_image(mlx, WIDTH, MAX_HEIGHT);
	x = -1;
	while (++x < bg->floor->width)
	{
		y = -1;
		while (++y < bg->floor->height)
			mlx_put_pixel(bg->floor, x, y, c->f_color);
	}
	int32_t floor_inst;
	floor_inst = mlx_image_to_window(mlx, bg->floor, 0, mlx->height / 2);
}
