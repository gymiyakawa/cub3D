
#include "../inc/cub3d.h"

/*
		NEED TO BE SETUP PRIOR
	set px/py
	set dir_x/dir_y
	set plane_x/plane_y
				EXAMPLE FROM TUTORIAL. USE AS REFERENCE ONLY
		double posX = 22.0, posY = 11.5;  //x and y start position
		double dirX = -1.0, dirY = 0.0; //initial direction vector
		double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane



*/


void	raycasting(t_ray *ray, t_texture *text)
{
	int	i;

	i = 0;
	while (i++ < WIDTH)
	{
		ray->camera_x = 2 * i / (double)WIDTH - 1;
		ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		
		ray->map_x = (int)ray->px;
		ray->map_y = (int)ray->py;
		
		ray->deltadist_x = get_delta_dist(ray->dir_x);
		ray->deltadist_x = get_delta_dist(ray->dir_y);
		
		set_step(ray);
		run_dda(ray);
		calculate_columns(ray);
		texture_calculations(ray, text);
		render_texture(ray, text, i);
		
	}
	mlx_image_to_window(ray->ms->mlx, ray->ms->game, 0, 0);
	return ;
}

void	render_texture(t_ray *ray, t_texture *text, int i)
{
	int	text_i;
	double	step;
	double	tex_pos;
	int		line;
	int		px_i;
	mlx_texture_t	*texture;

	text_i = get_text_index(ray);
	texture = text->mlx_textures[text_i];
	// draw_texture(text->mlx_textures[text_i], ray);
	step = 1.0 * texture->height / ray->line_height;
	tex_pos = ((double) ray->draw_start - (double) HEIGHT / 2
			+ (double) ray->line_height / 2) * step;
	line = ray->draw_start - 1;
	while (++line < ray->draw_end)
	{
		text->text_y = (int) tex_pos;
		if (tex_pos > texture->height - 1)
			tex_pos = texture->height -1;
		tex_pos += step;
		px_i = line * texture->width * texture->bytes_per_pixel;
		mlx_put_pixel(ray->ms->game, i, line, texture->pixels[px_i]);
	}
	
}

void	texture_calculations(t_ray *ray, t_texture *text)
{
	double	wall_x;
	int		text_i;
	
	text->text_num = (int) ray->ms->map->maze[ray->map_x][ray->map_y] - 1; // original was not casted, but he used a int map
	
	if (ray->side == EA_INDEX || ray->side == WE_INDEX)
		wall_x = ray->py + ray->perpwalldist * ray->dir_y;
	else
		wall_x = ray->px + ray->perpwalldist * ray->dir_x;
	wall_x -= floor((wall_x)); // reference had floor((wall_x)) for some reason
	text_i = get_text_index(ray);
	
	text->text_x = (int)(wall_x * text->mlx_textures[text_i]->width);
	
	if ((ray->side == EA_INDEX || ray->side == WE_INDEX) && ray->raydir_x > 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	
	if ((ray->side == NO_INDEX || ray->side == SO_INDEX) && ray->raydir_y < 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	return ;
}

int	get_text_index(t_ray *ray)
{
	if (ray->side == NO_INDEX)
		return (NO_INDEX);
	if (ray->side == SO_INDEX)
		return (SO_INDEX);
	if (ray->side == EA_INDEX)
		return (EA_INDEX);
	if (ray->side == WE_INDEX)
		return (WE_INDEX);
	else
	{
		printf("error in get_text_index\n");
		return (0);
	}
}


void	calculate_columns(t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x; // original had the result in brack for some reason
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;

	ray->line_height = (int)(HEIGHT / ray->perpwalldist);
	
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2 + ray->pitch;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2 + ray->pitch;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	return ;
}


void	run_dda(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->sidedist_y;
			ray->map_x += ray->step_x;
			
			
						// experimental, referenced from ana and cesars. helps determine which texture
			if (ray->raydir_x > 0)
				ray->side = EA_INDEX;	// east
			else
				ray->side = WE_INDEX;	// west
			
			
			
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			
			if (ray->raydir_y > 0)
				ray->side = SO_INDEX;	//south
			else
				ray->side = NO_INDEX; 	//north
				
				
		}
		if (ray->ms->map->maze[(int)ray->map_x][(int)ray->map_y] == '1')   /// might be a problem
			ray->hit = 1;
	}
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
		ray->sidedist_y = (ray->map_y + 1.0 - ray->py) *ray->deltadist_y;
	}
}


double	get_delta_dist(double dir)
{
	if (dir == 0)
		return (1e30);
	else
	{
		return (1 / fabs(dir));
	}
}