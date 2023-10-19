
#include "../inc/cub3d.h"
//commented this out to compile at home

// int	raycasting(t_ray *ray, t_player *plyr)
// {
// 	check_horizontal(ray, plyr);
	
	
// 	return 0;
// }

// void	check_horizontal(t_ray *ray, t_player *plyr)
// {
// 	float	a_tan;

// 	ray->h_dist = 1000000;
// 	ray->hx = plyr->pos_x;
// 	ray->hy = plyr->pos_y;
// 	a_tan = 1 / tan(ray->angle);
// 	if (ray->angle > PI)	/// means player is looking up
// 	{
// 		ray->ry = (((int)plyr->pos_y >> 6) << 6) - 0.0001;  // magic number here
// 		ray->rx = (plyr->pos_y - ray->ry) * a_tan + plyr->pos_x;
// 		ray->yo = -64;		// magic number here
// 		ray->xo = ray->yo * a_tan;
// 	}
// 	if (ray->angle < PI) // means player is looking down
// 	{
// 		ray->ry = (((int)plyr->pos_y >> 6) << 6) + 64;	// magic number here
// 		ray->rx = (plyr->pos_y - ray->ry) * a_tan + plyr->pos_x;
// 		ray->yo = 64;	// magic number here
// 		ray->xo = ray->yo * a_tan;
// 	}
// 	if (ray->angle == 0 || ray->angle == PI)
// 	{
// 		ray->rx = plyr->pos_x;
// 		ray->ry = plyr->pos_y;
// 		ray->dof = 8;	// magic number here
// 		while (ray->dof < 8)	// and here
// 		{
// 			ray->mx = (int) (ray->rx) >> 6;
// 			ray->ry = (int) (ray->ry) >> 6;
// 			ray->mp = ray->my * ray->ms->map->x;
// 			if ( ray->mp > 0 && ray->mp < ray->ms->map->x * ray->ms->map->y 
// 				&& ray->ms->map->test_map[ray->mp] == 1)	//ray hits a wall / finds a 1
// 			{
// 				ray->hx = ray->rx;
// 				ray->hy = ray->ry;
// 				ray->h_dist = calc_dist(plyr->pos_x, plyr->pos_y, ray->hx, ray->hy);
// 				ray->dof = 8;
// 			}
// 			else	// advances to the next line, adding the offset and incrementing dof
// 			{
// 				ray->rx += ray->xo;
// 				ray->rx += ray->yo;
// 				ray->dof += 1;
// 			}
// 		}


// 		// print ray
// 		// print from plyr (x,y) to ray (x,y)
		
	
// 		mlx_image_t *ray_img = mlx_new_image(ray->ms->mlx, HEIGHT, WIDTH);
		
// 		for (int i = 0; i < 50; i++)
// 		{
// 			for (int j = 0; j < 50; j++)
// 			{
// 				mlx_put_pixel(ray_img, ray->rx + i, ray->ry + j, 0xFF0000FF);
// 			}
// 		}
// 		mlx_image_to_window(ray->ms->mlx, ray_img, 0, 0);

// 	}
	
// }

// // maybe too many variables, send a struct instead
// float	calc_dist(float ax, float ay, float bx, float by)
// {
// 	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
// }