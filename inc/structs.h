/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:44 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/10 17:17:10 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


typedef struct s_color
{
	int	f_red;
	int	f_blue;
	int	f_green;
	
	int	c_red;
	int _blue;
	int	c_green;
	
	int	f_color;
	int	c_color;
	
}	t_color;


typedef struct s_img
{
	int	height;
	int	width;
	//pointer/instance/context/count??

}	t_img;


typedef struct s_texture
{
	t_img	n_tex;
	t_img	s_tex;
	t_img	e_tex;
	t_img	w_tex;
}	t_texture;

typedef struct s_map
{
	mlx_t*	mlx;
	// void	*mlx;
	void	*win;
	char	**map;
	int		flag;
	int		x;
	int		y;
	int		p_y;
	int		p_x;
	int		e_x;
	int		e_y;
	int		exit_check;
	int		x_max;
	int		y_max;
	void	*img_p;
	void	*img_e;
	void	*img_e2;
	void	*img_w;
	void	*img_c;
	void	*img_z;
	int		img_width;
	int		img_height;
	int		player;
	int		coin;
	int		exit;
	int		moves;
	int		pixel;
	int		pixel_max;
	bool	is_dead;
	
}	t_map;

typedef struct s_main
{
	t_color		*colors;
	t_map		*map;
	t_texture	*texture;
	void		*mlx;
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
<<<<<<< HEAD

=======
>>>>>>> main
