
#include "../inc/cub3d.h"
//commented this out to compile at home

/*
		NEED TO BE SETUP PRIOR

				EXAMPLE FROM TUTORIAL. USE AS REFERENCE ONLY
		double posX = 22.0, posY = 11.5;  //x and y start position
		double dirX = -1.0, dirY = 0.0; //initial direction vector
		double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane



*/

void	set_raycasting_vars(t_ray *ray)
{
	ray->px = ray->ms->map->p_x + 0.5;
	ray->py = ray->ms->map->p_y + 0.5;   // OG
	
	// ray->px = ray->ms->map->p_y + 0.5;  // from reference, segfaults on S. fucks up dda.
	// ray->py = ray->ms->map->p_x + 0.5;
	
	
	// ray->map_x = (int)ray->px; // og
	// ray->map_y = (int)ray->py;
	
	ray->map_x = ray->ms->map->p_x;
	ray->map_y = ray->ms->map->p_y;
	
										// printf("%d\n", ray->ms->map->p_view);
	ray->direction = get_direction(ray->ms->map->p_view);
	if (ray->direction < 0)
		error_and_exit(E_PARS, ray->ms);
	set_orientation(ray);
}

int	get_direction(int	p_view)
{
		// OG
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



				// remove the 0s;
void	set_orientation(t_ray *ray)
{
	if (ray->direction == NORTH)
	{
		ray->dir_x = 0;			//og north
		ray->dir_y = -1;
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
	if (ray->direction == SOUTH)
	{
		ray->dir_x = 0;			//og south
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


						//		RAYCASTING PROPER


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
		ray->hit = FALSE;
		set_ray_directions(ray, i);
		set_step(ray);
		run_dda(ray);
		calculate_columns(ray);
		
					// NO TEXTURES
		// (void)text;
		// no_texture(ray, i);
		
					// WITH TEXTURES
		texture_calculations(ray, text);
		render_texture(ray, text, i);
		
									// linha laranja horizonte
									// mlx_put_pixel(ray->ms->game, i, HEIGHT / 2, ray->ms->colors->c_color);

	}
	ms->game_inst = mlx_image_to_window(ray->ms->mlx, ray->ms->game, 0, 0);
	return ;
}

void	set_ray_directions(t_ray *ray, int i)
{
		ray->camera_x = 2 * i / (double)WIDTH - 1;

		ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;	// og
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
									// print_str_array(ray->ms->map->maze);
									// printf("direction: %d\n", ray->direction);
									// printf("maze x: |%d|\n", (int)ray->map_x);
									// printf("maze y: |%d|\n", (int)ray->map_y);
									// printf("maze[y][x]: %c\n", ray->ms->map->maze[ray->map_y][ray->map_x]);
									// printf("maze[x][y]: %c\n", ray->ms->map->maze[ray->map_x][ray->map_y]);
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;

			// if (ray->raydir_x > 0) // og
			// 	ray->side = EAST;
			// else
			// 	ray->side = WEST;

			if (ray->raydir_x < 0)
				ray->side = WEST;
			else
				ray->side = EAST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;

			// if (ray->raydir_y > 0)  // og
			// 	ray->side = SOUTH;
			// else
			// 	ray->side = NORTH;
			
			if (ray->raydir_y < 0)
				ray->side = NORTH;
			else
				ray->side = SOUTH;

		}
		// if (ray->ms->map->maze[ray->map_x][ray->map_y] == '1')

		if (ray->ms->map->maze[ray->map_y][ray->map_x] == '1') // OG
			ray->hit = TRUE;
	}
									// exit(1);
	return ;
}


void	calculate_columns(t_ray *ray)
{
	
	// if (ray->side == 0 || ray->side == 1)	//og
	// 	ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	// else
	// 	ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;

	if (ray->side == 0 || ray->side == 1)				// THIS ONE!!!!!! FUCK YEAH HOLY SMOKES HALLELUJAH AMEN GEEEBUS ALLMIGHTY LAWD!!!
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
	else
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;




	// if (ray->side == 0)
	// 	ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
	// else
	// 	ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;


	// if (ray->side == 1)
	// 	ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
	// else
	// 	ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;

				// wall being too high, fix here
	ray->line_height = (int)(HEIGHT / ray->perpwalldist) * 0.75;
	
	
	
	
	
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT;
	return ;
}


void	texture_calculations(t_ray *ray, t_texture *text)
{
	double	wall_x;
	int		text_i;
	// if (ray->side == NORTH || ray->side == SOUTH)		// not sure if better
	if (ray->side == EAST || ray->side == WEST)	// og
		wall_x = ray->py + ray->perpwalldist * ray->raydir_y;
	else
		wall_x = ray->px + ray->perpwalldist * ray->raydir_x;
	wall_x -= floor(wall_x); // reference had floor((wall_x)) for some reason
	
	text_i = get_text_index(ray);
	
									// printf("texture width %d\n", text->mlx_textures[0]->width);
									// print_textures(text);

	text->text_x = (int)(wall_x * text->mlx_textures[text_i]->width);
	
				// int texX = int(wallX * double(texWidth));

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

/*
MISSING STEPS
create a buffer,
populate it with 

the color values at each texture coordinates text[x][y]
draw start to draw end


*/

void	render_texture(t_ray *ray, t_texture *text, int i)
{
	int		text_i;
	double	step;
	double	tex_pos;
	int		line;
	uint32_t		px_color;
	mlx_texture_t	*t;

	text_i = get_text_index(ray);
	t = text->mlx_textures[text_i];

	step = 1.0 * (double)t->height / (double)ray->line_height;	// og
	
	tex_pos = ((double) ray->draw_start - (double) HEIGHT / 2
			+ (double) ray->line_height / 2) * step;		// og
			
	// tex_pos = ((double) ray->draw_start - (double) HEIGHT / 2
	// 		+ (double) ray->line_height / 2) * step;
			
	// tex_pos = ((double) ray->draw_start - (double) WIDTH / 2
	// 	+ (double) ray->line_height / 2) * step;

	// tex_pos = (ray->draw_start - HEIGHT / 2
	// 		+ ray->line_height / 2) * step;

	line = ray->draw_start - 1;

	while (++line < ray->draw_end)
	{
		// if (tex_pos > t->height - 1) 	//og
		// 	tex_pos = t->height -1;
		// text->text_y = (int) tex_pos;
		
		text->text_y = (int) tex_pos % t->height;
		
		tex_pos += step;
		px_color = make_px_color(text, t);


		// px_color = 0xFF0000FF; 	//color = red
		
		
		
		// RENDERING ONLY EAST TEXTURES
					
				// if (ray->side == NORTH)
				// 	mlx_put_pixel(ray->ms->game, i, line, 0XFF0000FF);	// RED
				// if (ray->side == SOUTH)
				// 	mlx_put_pixel(ray->ms->game, i, line, 0X0000FFFF);	// BLUE
				// if (ray->side == WEST)
				// 	mlx_put_pixel(ray->ms->game, i, line, 0X00FF00FF);	// GREEN
		
						
				// 	if (ray->side == EAST)
						mlx_put_pixel(ray->ms->game, i, line, px_color);
		
		
		
		
		
		
		
		
	}
	

								// printf("text x: %d\n", text->text_x);
								// printf("text y: %d\n", text->text_y);
								// printf("print color %X\n", px_color);
								
							// printf("value of line: %d\n", line);
							// printf("draw start: %d\n draw end: %d\n", ray->draw_start, ray->draw_end);
							// printf("draww range: %d\n",  ray->draw_end - ray->draw_start);
								// printf("i: %d, line: %d\n", i, line);
}

uint32_t	make_px_color(t_texture *text_strt, mlx_texture_t *t)
{
	uint32_t	color;
	int			r;
	int			g;
	int			b;
	int			a;


					//lets fuck around with values
					// text_strt->text_y += 1;
					// text_strt->text_x += 3;


						// OG
	// r = t->pixels[(t->height * text_strt->text_y) + \
	// 	(text_strt->text_x * t->bytes_per_pixel)];
	// g = t->pixels[(t->height * text_strt->text_y) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 1];
	// b = t->pixels[(t->height * text_strt->text_y) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 2];
	// a = t->pixels[(t->height * text_strt->text_y) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 3];

	
	
	
							// kinda working but reversed
	// r = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) + \
	// 	(text_strt->text_x * t->bytes_per_pixel)];
		
	// g = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 1];
		
	// b = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 2];
		
	// a = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) + \
	// 	(text_strt->text_x * t->bytes_per_pixel) + 3];
	
	
	
	
	
	


	text_strt->text_y++;



	r = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel)];
		
	g = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 1];
		
	b = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 2];
		
	a = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 3];
	
	
	
	
	
	// 0x000000FF
	// 0xFFFFFFFF
	
	// r = t->pixels[(t->width * text_strt->text_x * t->bytes_per_pixel) + \
	// 	(text_strt->text_y * t->bytes_per_pixel)];
		
	// g = t->pixels[(t->width * text_strt->text_x * t->bytes_per_pixel) + \
	// 	(text_strt->text_y * t->bytes_per_pixel) + 1];
		
	// b = t->pixels[(t->width * text_strt->text_x * t->bytes_per_pixel) + \
	// 	(text_strt->text_y * t->bytes_per_pixel) + 2];
		
	// a = t->pixels[(t->width * text_strt->text_x * t->bytes_per_pixel) + \
	// 	(text_strt->text_y * t->bytes_per_pixel) + 3];z
	
	
	

	// size of pixture = WITDH * HEIGHT * bbp;
	
	// y = 1;
	// x = 2 * bpp;
	
	
	// 10  9  8  7  6  5  4  3  2  1
	// 20 19 18 17 16 15 14 13 12 11
	// 30 29 282 72...         12.1 12.2 
	
	
	
	
	
	// 1  2  3  4  5  6  7  8  9  10
	// 11 12 13 14 15 16 17 18 19 20
	//
	
	
	
	
	color = create_rgba(r, g, b, a);
	
						// printf("color: %d\n", color);
	return (color);
}

void	no_texture(t_ray *ray, int i)
{
	int	line;

	line = ray->draw_start - 1;
	while (++line < ray->draw_end)
	{
	if (ray->side == NORTH)
		mlx_put_pixel(ray->ms->game, i, line, 0XFF0000FF);	// RED
	if (ray->side == SOUTH)
		mlx_put_pixel(ray->ms->game, i, line, 0X0000FFFF);	// BLUE
	if (ray->side == EAST)
		mlx_put_pixel(ray->ms->game, i, line, 0XFFFF00FF);	// YELLOW
	if (ray->side == WEST)
		mlx_put_pixel(ray->ms->game, i, line, 0X00FF00FF);	// GREEN
	}
}
