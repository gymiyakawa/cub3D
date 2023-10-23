
#include "../inc/cub3d.h"
//commented this out to compile at home

/*
		NEED TO BE SETUP PRIOR

				EXAMPLE FROM TUTORIAL. USE AS REFERENCE ONLY
		double posX = 22.0, posY = 11.5;  //x and y start position
		double dirX = -1.0, dirY = 0.0; //initial direction vector
		double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane



*/

void	raycasting(t_main *ms)
{
	t_ray *ray = ms->ray;
	t_texture *text = ms->texture;
	int	i;

	// ms->map->p_x = ms->ray->px;
	// ms->map->p_y = ms->ray->py;

	i = -1;
	while (++i < WIDTH)
	{
		ray->hit = 0;
		set_ray_directions(ray, i);
		set_step(ray);
		run_dda(ray);
		calculate_columns(ray);
		// texture_calculations(ray, text);
											// printf("rendered x position: %d\n", i);
		render_texture(ray, text, i);
		
									// linha laranja horizonte
									// mlx_put_pixel(ray->ms->game, i, HEIGHT / 2, ray->ms->colors->c_color);


	}
	int32_t game_img;
	game_img = mlx_image_to_window(ray->ms->mlx, ray->ms->game, 0, 0);
	return ;
}

void	set_ray_directions(t_ray *ray, int i)
{
		ray->camera_x = 2 * i / (double)WIDTH - 1;
		ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		
		ray->map_x = (int)ray->px;
		ray->map_y = (int)ray->py;
		
				// ray->deltadist_x = get_delta_dist(ray->raydir_x);  // seemed to be buggy chech needed
				// ray->deltadist_y = get_delta_dist(ray->raydir_y);
				
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

double	get_delta_dist(double dir)
{
	if (dir == 0)
		return (1e30);
	else
	{
		return (fabs(1 / dir));
	}
}

void	set_raycasting_vars(t_ray *ray)
{
	ray->px = ray->ms->map->p_x + 0.5;
	ray->py = ray->ms->map->p_y + 0.5;   // OG
	
	// ray->px = ray->ms->map->p_y + 0.5;  // from reference, segfaults on S. fucks up dda.
	// ray->py = ray->ms->map->p_x + 0.5;
	
	
	ray->map_x = (int)ray->px; // og
	ray->map_y = (int)ray->py;
	
	// ray->map_x = ray->ms->map->p_x;
	// ray->map_y = ray->ms->map->p_y;
	
										// printf("%d\n", ray->ms->map->p_view);
	ray->direction = get_direction(ray->ms->map->p_view);
	if (ray->direction < 0)
		error_and_exit(E_RAY, ray->ms);
	set_orientation(ray);
}

void	set_orientation(t_ray *ray)
{
	if (ray->direction == NORTH)
	{
		ray->dir_x = 0;			//og
		ray->dir_y = -1;
		ray->plane_x = 0.66;
		ray->plane_y = 0;
		
	}
	if (ray->direction == SOUTH)
	{
		ray->dir_x = 0;			//og
		ray->dir_y = 1;
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
	if (ray->direction == EAST)
	{
		ray->dir_x = 1;		//og west
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = 0.66;
	}
	if (ray->direction == WEST)
	{
		ray->dir_x = -1;	//og east
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = -0.66;
	}
	return ;
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
		perror("p_view not set\n");
		return (-1);
	}
}



void	render_texture(t_ray *ray, t_texture *text, int i)
{
	// int		text_i;
	// double	step;
	// double	tex_pos;
	int		line;
	// int		px_i;
	// mlx_texture_t	*texture;

	// text_i = get_text_index(ray);
	// texture = text->mlx_textures[text_i];
	// draw_texture(text->mlx_textures[text_i], ray);
	
	// step = 1.0 * texture->height / ray->line_height;
	// tex_pos = ((double) ray->draw_start - (double) HEIGHT / 2
	// 		+ (double) ray->line_height / 2) * step;
	line = ray->draw_start - 1;
										//should print a line through the middle;
								// mlx_put_pixel(ray->ms->game, i, line, 0XFF0000FF);
								
	while (++line < ray->draw_end)
	{
		// text->text_y = (int) tex_pos;
		// if (tex_pos > texture->height - 1)
		// 	tex_pos = texture->height -1;
		// tex_pos += step;
		
								// lets try without textures
								(void)text;
							// px_i = line * texture->width * texture->bytes_per_pixel;
							// (void)px_i;
							// mlx_put_pixel(ray->ms->game, i, line, texture->pixels[px_i]);
							// printf("texture equivalent %d\n", texture->pixels[px_i]);

							// printf("i: %d, line: %d\n", i, line);
		mlx_put_pixel(ray->ms->game, i, line, 0XFF0000FF);
	}
								// printf("\nEXITED LOOP\n");

	
}

void	texture_calculations(t_ray *ray, t_texture *text)
{
	double	wall_x;
	int		text_i;
	
	text->text_num = ray->ms->map->maze[ray->map_y][ray->map_x] - 1; // original was not casted, but he used a int map

		//maybe calculate texture.width?

	if (ray->side == EAST || ray->side == WEST)
		wall_x = ray->py + ray->perpwalldist * ray->raydir_y;
	else
		wall_x = ray->px + ray->perpwalldist * ray->raydir_x;
	wall_x -= floor(wall_x); // reference had floor((wall_x)) for some reason
	
	text_i = get_text_index(ray);
	
						
	
									// printf("texture width %d\n", text->mlx_textures[0]->width);
									// print_textures(text);

	text->text_x = (int)(wall_x * text->mlx_textures[text_i]->width);
	
	if ((ray->side == EAST || ray->side == WEST) && ray->raydir_x > 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->raydir_y < 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	return ;
}

int	get_text_index(t_ray *ray)
{
	if (ray->side == NORTH)
		return (NORTH);
	if (ray->side == SOUTH)
		return (SOUTH);
	if (ray->side == EAST)
		return (EAST);
	if (ray->side == WEST)
		return (WEST);
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
	
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT;
	return ;
}


void	run_dda(t_ray *ray)
{
	while (ray->hit == false)
	{
									print_str_array(ray->ms->map->maze);
									printf("direction: %d\n", ray->direction);
									printf("maze x: |%d|\n", (int)ray->map_x);
									printf("maze y: |%d|\n", (int)ray->map_y);
									printf("maze[y][x]: %c\n", ray->ms->map->maze[ray->map_y][ray->map_x]);
									// printf("maze[x][y]: %c\n", ray->ms->map->maze[ray->map_x][ray->map_y]);
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
			if (ray->raydir_y > 0)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		// if (ray->ms->map->maze[ray->map_x][ray->map_y] == '1')
		if (ray->ms->map->maze[ray->map_y][ray->map_x] == '1') // OG
			ray->hit = true;
	}
									// exit(1);
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

