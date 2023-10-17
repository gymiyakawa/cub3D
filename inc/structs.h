#pragma once

#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_main t_main;

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


//	direction order: NO, SO, EA, WE;
typedef struct s_texture
{
	char			**paths;
	mlx_texture_t	**mlx_textures;
	t_main	*ms;
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
	// int		e_x;
	// int		e_y;
	// int		exit_check;
	int		x_max;
	int		y_max;
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
	int		pixel;
	// int		pixel_max;
	// bool	is_dead;
	int		i_first_line;
	t_main	*ms;
}	t_map;

typedef struct s_main
{
	t_color		*colors;
	t_map		*map;
	t_texture	*texture;
	mlx_t		*mlx;
	int			fd;
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
