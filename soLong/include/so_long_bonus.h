/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:23:26 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/12 13:38:14 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./gnl/get_next_line.h"
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**map;
	int		flag;
	int		x;
	int		y;
	int		loop;
	int		loop2;
	int		pinball;
	int		img;
	int		p_y;
	int		p_x;
	int		x_y;
	int		x_x;
	int		e_x;
	int		e_y;
	int		exit_check;
	int		x_max;
	int		y_max;
	void	*img_p;
	void	*img_p1;
	void	*img_p2;
	void	*img_p3;
	void	*img_e;
	void	*img_e2;
	void	*img_w;
	void	*img_c;
	void	*img_z;
	void	*img_x;
	int		img_width;
	int		img_height;
	int		player;
	int		coin;
	int		exit;
	int		enemy;
	int		moves;
	int		pixel;
	int		pixel_max;
	bool	is_dead;
}			t_map;

int			open_and_allocate_map(char *str, t_map *map);
int			initialize_map(t_map *map);
int			check_map_extension(char *str);
int			check_map(t_map *map);
int			check_top_and_bottom_walls(t_map *map);
int			check_right_and_left_walls(t_map *map);
int			check_map_inside(t_map *map);
int			check_map_inside_ctd(t_map *map);
int			check_assets(t_map *map);
int			check_valid_path(t_map *map);
bool		open_image(char *str);
int			check_image_path(t_map *map);
bool		assets_to_images(t_map *map);
bool		assets_to_images_ctd(t_map *map);
int			error_and_message(int nb, t_map *map);
int			exit_check(t_map *map, char **dup_map, int y, int x);
int			replace_assets(t_map *map, char **dup_map, int y, int x);
char		*ft_strdup(const char *s1);
char		*ft_strchr(char *s, int c);
char		**duplicate_map(t_map *map);
int			free_table(char **tab);
int			images_to_screen(t_map *map);
int			alicia_keys(int key, t_map *map);
bool		now_we_move(t_map *map, int y, int x);
bool		now_we_move_ctd(t_map *map, int y, int x);
int			end_game(t_map *map, int flag);
int			bonus_messages(t_map *map);
char		*ft_itoa(int n);
int			detsign(int n);
int			intlen(int nbr);
int			exit_win(void);
int			display_image(t_map *map, int asset);
int			enemy_moves(t_map *map);
int			player_bounces(t_map *map);
int			player_bounces_ctd(t_map *map);
int			move_right(t_map *map);
int			move_left(t_map *map);

#endif