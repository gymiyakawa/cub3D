/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:15:39 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/11/03 14:32:16 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft/libft.h"
#include "structs.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdbool.h> 
#include <fcntl.h>

// game config
#define WIDTH 1920
#define HEIGHT 1080
#define ROT_SPEED 0.15
#define MOV_SPEED 0.1

// general macros
#define TRUE 1
#define FALSE 0
#define MAX_FILES 256
#define INI_C_B 256

//	directions
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

// colors
#define RED 0XFF0000FF
#define BLUE 0X0000FFFF
#define YELLOW 0XFFFF00FF
#define GREEN 0X00FF00FF

// ERROR MESSAGES
#define E_MAP "Input file inexistent or not conforming to .cub extension\n"
#define E_MAP_NFD "Map not found\n"
#define E_INV_MAP "Invalid map\n"
#define E_MALLOC "Malloc failed\n"
#define E_OPEN "Invalid file descriptor, file not found\n"
#define E_PRS_COL "Invalid color parameter\n"
#define E_PRS_TXT "Invalid texture parameter\n"
#define E_RPT_TXT "Repeated textures are not allowed\n"
#define E_INV_CHAR "Invalid character in maze line or .cub file out of order\n"
#define E_PLAY "Wrong or insufficient player number\n"
#define E_MSS_ELEM "Missing required element: NO, SO, EA, WE, F, C or map\n"
#define E_RPT_ELEM "No element can be repeated\n"
#define E_INV_LINE "All non-identified lines must be empty\n"
#define E_MLX_INI "MLX42 failed to initialize\n"
#define E_MAZ_OP "Floor or player square must be contained\n"
#define E_DUP "Unable to duplicate maze\n"
#define E_PAD "Unable to pad maze\n"
#define E_AC "Wrong number of arguments\n"
#define E_WIN "Error with rendering game image\n"
#define E_RAY "Error setting ray direction\n"
#define E_PVIEW "p_view not set\n"
#define E_TEX_IND "Error in get_text_index\n"

// FUNCTION PROTOTYPES

//checks.c
bool		detect_loose_char(t_main *ms);
void		elements_check(t_main *ms);
char		**find_valid_lines(t_main *ms);
char		**make_charset(void);
bool		are_there_repeats(t_main *ms);

//color_parsing.c
int			parse_colors(t_main *ms);
int			set_floor_ceiling(t_main *ms);
int			parse_ceiling(t_color *c, char *arg);
int			parse_floor(t_color *c, char *arg);
int			set_color_bit(char *arg, u_int32_t *color_bit, int *i);

//cub3d.c
bool		parsing(char *str, t_main *ms);
void		init_mlx(t_main *ms);

//exit.c
void		clean_exit(t_main *ms);
void		*free_map(t_map *map);
void		*free_ms(t_main *ms);
void		*free_color(t_color *colors);
void		*free_texture(t_texture *texture);

//exit_2.c
void		error_and_exit(char *str, t_main *ms);
void		handle_maze_line_error(char **maze, t_main *ms, int i);
void		close_fds(void);

//flood_fill.c
char		**duplicate_maze(char **maze, t_main *ms);
bool		flood_fill(t_main *ms, char **dup, int y, int x);
bool		check_if_closed(t_main *ms, char **m, int y, int x);
void		pad_maze(t_main *ms, char **maze);
char		*add_padding(char *str, int len);

//init.c
int			open_fd(char *str, t_main *ms);
void		init_ms(t_main **ms, char **av);
void		init_ray(t_ray **ray, t_main *ms);
void		init_background(t_background **bg, t_main *ms);
void		init_color(t_color **color, t_main *ms);

//init_2.c
void		init_texture(t_texture **texture, t_main *ms);
void		init_map(t_map **map, t_main *ms);

//map_parsing.c
int			parse_map(t_main *ms);
void		check_for_limits(t_map *map);
char		**copy_maze(char *str, t_main *ms);
int			get_first_line_i(t_map *map);
bool		find_player_start(char **maze, t_main *ms);

//map_parsing_2.c
char		**clean_maze(char **maze, t_main *ms, int lines);
char		*trim_end_spaces(char *str);
bool		only_new_lines(char *str);
void		free_partial_maze(char **maze, t_main *ms, int i);
bool		validate_maze_line(char *line);

//mlx_control.c
void		key_bindings(mlx_key_data_t input, void *ms);
void		refresh_game(t_main *ms);
void		rotate_right(t_ray *ray);
void		rotate_left(t_ray *ray);
void		make_background(mlx_t *mlx, t_color *c, t_background *bg);

//moves.c
void		move_ahead(t_ray *ray);
void		move_back(t_ray *ray);
void		move_right(t_ray *ray);
void		move_left(t_ray *ray);

//parsing utils.c
bool		valid_up_to_identifier(char *initial, char *identifier);
u_int32_t	create_rgba(int r, int g, int b, int a);
char		*find_identifier(t_main *ms, char *identifier);
int			find_identifier_pos(t_main *ms, char *identifier);
void		check_valid_path(char *path, t_main *ms);

//parsing_utils_2.c
int			line_count(char *str, t_main *ms);
char		**copy_file(char *str, t_main *ms);
int			check_input_extension(char *str, t_main *ms);
bool		is_valid_line(char *line);
void		count_commas(char *arg, t_main *ms);

//print.c
void		print_color_struct(t_color *c);
void		print_textures(t_texture *t);

//raycasting_init.c
void		set_raycasting_vars(t_ray *ray);
int			get_direction(int p_view);
void		set_orientation(t_ray *ray);

// raycasting
void		raycasting(t_main *ms);
void		set_ray_directions(t_ray *ray, int i);
void		set_step(t_ray *ray);
void		run_dda(t_ray *ray);
void		calculate_columns(t_ray *ray);

//texture parsing
int			parse_texture(t_main *ms);
int			parse_indiv_textures(t_texture *t, char *direction);
int			texture_pathsetter(char *arg, t_main *ms, int path_i, char *dir);
int			which_path(char *direction);
void		check_repeat_textures(t_texture *t);

//texture parsing2
void		check_remaining_arg(char *arg, int i, t_main *ms);

// texture rendering 
void		texture_calculations(t_ray *ray, t_texture *text);
int			get_text_index(t_ray *ray);
void		render_texture(t_ray *ray, t_texture *text, int i);
uint32_t	make_px_color(t_texture *text_strt, mlx_texture_t *t);
void		no_texture(t_ray *ray, int i);
