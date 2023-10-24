
#include "../inc/cub3d.h"

/* The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.
◦ The W, A, S, and D keys must allow you to move the point of view through
the maze.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.*/
void	key_bindings(mlx_key_data_t input, void *main_struct)
{
	t_main	*ms;

	ms = main_struct;
	refresh_game(ms);
	if (input.key == MLX_KEY_ESCAPE && input.action == MLX_PRESS)
		mlx_close_window(ms->mlx);
	if (input.key == MLX_KEY_W && (input.action == MLX_PRESS
		|| input.action == MLX_REPEAT))
		move_ahead(ms->ray);
	if (input.key == MLX_KEY_S && (input.action == MLX_PRESS
		|| input.action == MLX_REPEAT))
		move_back(ms->ray);
	if (input.key == MLX_KEY_D && (input.action == MLX_PRESS
		|| input.action == MLX_REPEAT))
		move_right(ms->ray);
	if (input.key == MLX_KEY_A && (input.action == MLX_PRESS
		|| input.action == MLX_REPEAT))
		move_left(ms->ray);
	if (input.key == MLX_KEY_RIGHT && (input.action == MLX_PRESS
		|| input.action == MLX_REPEAT))
		rotate_right(ms->ray);
	 if (input.key == MLX_KEY_LEFT && (input.action == MLX_PRESS
	 	|| input.action == MLX_REPEAT))
		rotate_left(ms->ray);
	raycasting(ms);
	return ;
}

void	refresh_game(t_main *ms)
{
	mlx_delete_image(ms->mlx, ms->game);
	ms->game = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	if (!ms->game) // or (!ms->game || mlx_image_to_window(ms->mlx, ms->game, 0, 0) < 0)?
	{
		mlx_close_window(ms->mlx);
		error_and_exit(E_WIN, ms);
	}
}

void	move_ahead(t_ray *ray)
{
	char **maze;
	maze = ray->ms->map->maze;

	if(maze[(int)ray->py][(int)(ray->px + ray->dir_x * (ray->mov_speed + 0.1))] != '1')
		ray->px += ray->dir_x * ray->mov_speed;
	if(maze[(int)(ray->py + ray->dir_y * (ray->mov_speed + 0.1))][(int)ray->px] != '1')
		ray->py += ray->dir_y * ray->mov_speed;
}

void	move_back(t_ray *ray)
{
	char **maze;
	
	maze = ray->ms->map->maze;
	if(maze[(int)ray->py][(int)(ray->px - ray->dir_x * ray->mov_speed)] != '1')
		ray->px -= ray->dir_x * ray->mov_speed;
	if(maze[(int)(ray->py - ray->dir_y * ray->mov_speed)][(int)ray->px] != '1')
		ray->py -= ray->dir_y * ray->mov_speed;
}

void	move_right(t_ray *ray)
{
	char **maze;
	
	maze = ray->ms->map->maze;
	if(maze[(int)ray->py][(int)(ray->px + ray->plane_x * ray->mov_speed)] != '1')
		ray->px += ray->plane_x * ray->mov_speed;
	if(maze[(int)(ray->py + ray->plane_y * ray->mov_speed)][(int)ray->px] != '1')
		ray->py += ray->plane_y * ray->mov_speed;
}

void	move_left(t_ray *ray)
{
	char **maze;
	
	maze = ray->ms->map->maze;
	if(maze[(int)ray->py][(int)(ray->px - ray->plane_x * ray->mov_speed)] != '1')
		ray->px -= ray->plane_x * ray->mov_speed;
	if(maze[(int)(ray->py - ray->plane_y * ray->mov_speed)][(int)ray->px] != '1')
		ray->py -= ray->plane_y * ray->mov_speed;
}

void	rotate_right(t_ray *ray)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(ray->rot_speed) \
				- ray->dir_y * sin(ray->rot_speed);
	ray->dir_y = old_dir_x * sin (ray->rot_speed) \
				+ ray->dir_y * cos (ray->rot_speed);
	ray->plane_x = ray->plane_x * cos(ray->rot_speed) \
				- ray->plane_y * sin(ray->rot_speed);
	ray->plane_y = old_plane_x * sin (ray->rot_speed) \
				+ ray->plane_y * cos (ray->rot_speed);
}

void	rotate_left(t_ray *ray)
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
	mlx_image_to_window(mlx, bg->ceiling, 0, 0);
	// bg->floor = mlx_new_image(mlx, WIDTH, MAX_HEIGHT);
	bg->floor = mlx_new_image(mlx, WIDTH, HEIGHT);
	x = -1;
	while (++x < bg->floor->width)
	{
		y = -1;
		while (++y < bg->floor->height)
			mlx_put_pixel(bg->floor, x, y, c->f_color);
	}
	mlx_image_to_window(mlx, bg->floor, 0, mlx->height / 2);
}
