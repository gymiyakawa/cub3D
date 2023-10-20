/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:06:55 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/20 12:07:14 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42/include/MLX42/MLX42.h"

typedef struct	s_main t_main;

typedef struct s_color
{
	char		**floor_ceiling;
	u_int32_t	f_red;
	u_int32_t	f_blue;
	u_int32_t	f_green;
	u_int32_t	c_red;
	u_int32_t	c_blue;
	u_int32_t	c_green;
	u_int32_t	f_color;
	u_int32_t	c_color;
	t_main		*ms;
}	t_color;

typedef struct s_background
{
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;
	t_main		*ms;
} t_background;

//	direction order: NO, SO, EA, WE;
typedef struct s_texture
{
	char			**paths;
	mlx_texture_t	**mlx_textures;
	int				text_x;
	int				text_y;
	int				text_num;
	t_main			*ms;
}	t_texture;

typedef struct s_map
{
	// mlx_t*	mlx;
	// void	*mlx;
	void	*win;
	char	**maze;
	int		flag;
	int		x;
	int		y;
	int		p_view;
	int		p_y;
	int		p_x;
	int		m_size;
	// int		e_x;
	// int		e_y;
	// int		exit_check;
	mlx_image_t	*m_img;
	int		*test_map;
	int		x_max;
	int		y_max;
	int		last_line;
	// void	*img_p;
	// void	*img_e;
	// void	*img_e2;
	// void	*img_w;
	// void	*img_c;
	// void	*img_z;
	// int		img_width;
	// int		img_height;
	// int		player;
	// int		coin;
	// int		exit;
	// int		moves;
	// int		pixel;
	// int		pixel_max;
	// bool	is_dead;
	int		i_first_line;
	t_main	*ms;
}	t_map;
/*
px / py = player position.

dir_x / dir_y = direction player is facing. must be set before DDA start

plane_x/plane_y = coordinates on the "screen" plane

camera_x = the coordinates on the x axis. "where we are looking".
goes from -1 to the left, 0 at center, and 1 on the right.

raydir_x/raydir_y = direction of the ray, calculated using direction vector
plane coordinates, and camera_x

map_x/map_y = which square in the grid we are. less accurate then player position

sidedist_x/sidedist_y = distance the ray has to travel until it finds a x or y
line.

delta_x/delta_y = distance the ray has to travel to fully cross a square

perpwalldist = distance from a perpendicular wall created at out POV

step_x/step_y = in what direction DDA algo is moving, always increments of 
1 or -1

side = which wall is reached: 0 for x, 1 for y

line_height = height of the line relative to ray length

draw_start/draw_end = initial and final point of start and end of wall section

pitch = goes unchanged at 100 for this version

wall_x = exact point on the x axis on the wall where the ray hit. used to
map which section of the texture to render

*/
typedef struct s_ray
{
	double	px;
	double	py;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		direction;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		pitch;
	double	rot_speed;
	double	mov_speed;
	t_main	*ms;
} t_ray;

typedef struct s_main
{
	t_color		*colors;
	t_map		*map;
	t_texture	*texture;
	t_background *bg;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*game;
	int			fd;
	bool		game_over;
	char		**file_copy;
	char		*filename;
	int			line_count;
	char		**valid_lines;
}	t_main;

			// from so_long
// typedef struct s_map
// {
// 	void	*mlx;
// 	void	*win;
// 	char	**map;
// 	int		flag;
// 	int		x;
// 	int		y;
// 	int		p_y;
// 	int		p_x;
// 	int		e_x;
// 	int		e_y;
// 	int		exit_check;
// 	int		x_max;
// 	int		y_max;
// 	void	*img_p;
// 	void	*img_e;
// 	void	*img_e2;
// 	void	*img_w;
// 	void	*img_c;
// 	void	*img_z;
// 	int		img_width;
// 	int		img_height;
// 	int		player;
// 	int		coin;
// 	int		exit;
// 	int		moves;
// 	int		pixel;
// 	int		pixel_max;
// 	bool	is_dead;
// }			t_map;
