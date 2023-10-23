
#include "../inc/cub3d.h"

void	key_bindings(mlx_key_data_t input, void *main_struct)
{
	t_main	*ms;

					// refresh image

	ms = main_struct;

						//provisorio
			mlx_delete_image(ms->mlx, ms->game);
			ms->game = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
			if (!ms->game) // or (!ms->game || mlx_image_to_window(ms->mlx, ms->game, 0, 0) < 0)?
			{
				mlx_close_window(ms->mlx);
				error_and_exit(E_WIN, ms);
			}
			
			
			
			
	if (input.key == MLX_KEY_ESCAPE) //input.key or mlx_is_key_down??
		mlx_close_window(ms->mlx);
	// if (input.key == MLX_KEY_W)
	// {
	// 	// go up; 
	// }
	// if (input.key == MLX_KEY_W)
	// {
	// 	// go up; 
	// }
	// if (input.key == MLX_KEY_UP)
	// 	ms->ray->px = 

	
	if (input.key == MLX_KEY_D)
	{
		look_left(ms->ray); // funcao da Ana
	}


	raycasting(ms);
	return ;
}

				// borrowing turn function for testing. make our own
void	look_left(t_ray *ray)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(-ray->rot_speed) \
				- ray->dir_y * sin(-ray->rot_speed);
	ray->dir_y = old_dir_x * sin (-ray->rot_speed) \
				+ ray->dir_y * cos (-ray->rot_speed);
	ray->plane_x = ray->plane_x * cos(-ray->rot_speed) \
				- ray->plane_y * sin(-ray->rot_speed);
	ray->plane_y = old_plane_x * sin (-ray->rot_speed) \
				+ ray->plane_y * cos (-ray->rot_speed);
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
	(void)ceiling_inst;
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
	(void)floor_inst;
}
