
#include "../inc/cub3d.h"

void	set_raycasting_vars(t_ray *ray)
{
	ray->px = ray->ms->map->p_x + 0.5;
	ray->py = ray->ms->map->p_y + 0.5;
	ray->map_x = ray->ms->map->p_x;
	ray->map_y = ray->ms->map->p_y;
	ray->direction = get_direction(ray->ms->map->p_view);
	if (ray->direction < 0)
		error_and_exit(E_PARS, ray->ms);
	set_orientation(ray);
}

int	get_direction(int	p_view)
{
	if (p_view == 'N')
		return (NORTH);
	if (p_view == 'S')
		return (SOUTH);
	if (p_view == 'E')
		return (EAST);
	if (p_view == 'W')
		return (WEST);
	else
	{
		perror(E_PVIEW);
		return (-1);
	}
}

void	set_orientation(t_ray *ray)
{
	if (ray->direction == NORTH)
	{
		ray->dir_y = -1;
		ray->plane_x = 0.66;
	}
	if (ray->direction == SOUTH)
	{
		ray->dir_y = 1;
		ray->plane_x = -0.66;
	}
	if (ray->direction == EAST)
	{
		ray->dir_x = 1;
		ray->plane_y = 0.66;
	}
	if (ray->direction == WEST)
	{
		ray->dir_x = -1;
		ray->plane_y = -0.66;
	}
	return ;
}

