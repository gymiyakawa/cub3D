/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:16:08 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/25 13:16:17 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
}

void	refresh_game(t_main *ms)
{
	mlx_delete_image(ms->mlx, ms->game);
	ms->game = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	if (!ms->game)
	{
		mlx_close_window(ms->mlx);
		error_and_exit(E_WIN, ms);
	}
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

void	make_background(mlx_t *mlx, t_color *c, t_background *bg)
{
	uint32_t	x;
	uint32_t	y;

	bg->ceiling = mlx_new_image(mlx, mlx->width, mlx->height / 2);
	x = -1;
	while (++x < bg->ceiling->width)
	{
		y = -1;
		while (++y < bg->ceiling->height)
			mlx_put_pixel(bg->ceiling, x, y, c->c_color);
	}
	mlx_image_to_window(mlx, bg->ceiling, 0, 0);
	bg->floor = mlx_new_image(mlx, mlx->width, mlx->height);
	x = -1;
	while (++x < bg->floor->width)
	{
		y = -1;
		while (++y < bg->floor->height)
			mlx_put_pixel(bg->floor, x, y, c->f_color);
	}
	mlx_image_to_window(mlx, bg->floor, 0, mlx->height / 2);
}
