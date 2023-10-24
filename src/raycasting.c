
#include "../inc/cub3d.h"

void	raycasting(t_main *ms)
{
	t_ray *ray = ms->ray;
	t_texture *text = ms->texture;
	int	i;

	i = -1;
	while (++i < WIDTH) // og
	{
		ray->hit = FALSE;
		set_ray_directions(ray, i);
		set_step(ray);
		run_dda(ray);
		calculate_columns(ray);
		texture_calculations(ray, text);
		render_texture(ray, text, i);
	}
	ms->game_inst = mlx_image_to_window(ray->ms->mlx, ray->ms->game, 0, 0);
	return ;
}

void	set_ray_directions(t_ray *ray, int i)
{
		ray->camera_x = 2 * i / (double)WIDTH - 1;	// og
		ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		ray->map_x = (int)ray->px;
		ray->map_y = (int)ray->py;
		if (ray->raydir_x == 0)
			ray->deltadist_x = 1e30;
		else
			ray->deltadist_x = fabs(1 / ray->raydir_x);
		if (ray->raydir_y == 0)
			ray->deltadist_y = 1e30;
		else
			ray->deltadist_y = fabs(1 / ray->raydir_y);
		return ;
}

void	set_step(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->px - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->px) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->py - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->py) * ray->deltadist_y;
	}
}

void	run_dda(t_ray *ray)
{
	while (ray->hit == FALSE)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			if (ray->raydir_x > 0)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			if (ray->raydir_y < 0)
				ray->side = NORTH;
			else
				ray->side = SOUTH;
		}
		if (ray->ms->map->maze[ray->map_y][ray->map_x] == '1')
			ray->hit = TRUE;
	}
	return ;
}

void	calculate_columns(t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
	else
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;

	ray->line_height = (int)(HEIGHT / ray->perpwalldist);	// 0.75 as a ratio seems arbitrtary
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT;
	return ;
}
