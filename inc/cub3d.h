
#pragma once

#include "libft/libft.h"
#include "structs.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdbool.h> 
#include <fcntl.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 35
#define WIDTH 30
#define HEIGHT 30
#define TRUE 1
#define FALSE 0
#define MAX_FILES 256

//	index values for texture parsing
#define NO_INDEX 0
#define SO_INDEX 1
#define EA_INDEX 2
#define WE_INDEX 3

// ERROR MESSAGES

#define E_MAP "Input file inexistent or not conforming to .cub extension\n"
#define E_MAP_NFD "Map not found\n"
#define E_AC "Only two arguments for cub3d (the first is the program's name)\n"
#define E_MALLOC "Error on malloc\n"
#define E_OPEN "Error opening fd\n"
#define E_BIG "Map too big for this screen\n"
#define E_PRS_COL "Invalid color parameter\n"
#define E_PRS_TXT "Invalid texture parameter\n"
#define E_PARS "Parsing error\n"
#define E_INV_CHAR "Invalid character in maze line\n"
#define E_PLAY "Wrong or insufficient number for the player\n"
#define E_MSS_ELEM "Missing required element: NO, SO, EA, WE, F, C or Map\n"
#define E_WRG_ORD "Wrong order of elements. Map must be last\n"
#define	E_RPT_ELEM "No element can be repeated\n"
#define E_INV_LINE "All non-identified lines must be empty\n"
// FUNCTION PROTOTYPES

//map_parsing.c
int	    parse_map(t_main *ms);
// int	    open_and_allocate_map(char *str, t_main *ms);
int     check_input_extension(char *str, t_main *ms);
char    **copy_maze(char *str, t_main *ms);
bool	validate_maze_line(char *line);
void	handle_maze_line_error(char **maze, t_main *ms, int i);
bool	find_player_start(char **maze, t_main *ms);
void	free_partial_maze(char **maze, t_main *ms, int i);
// char	*set_maze(t_main *ms);
int		get_first_line_i(t_map *map);

//error.c
void    error_and_exit(char *str, t_main *ms);

//exit.c
void	clean_exit(t_main *ms);
void    *free_color(t_color *colors);
void    *free_texture(t_texture *texture);
void    *free_map(t_map *map);
void    *free_ms(t_main *ms);

//cub3d.c
int     line_count(char *str, t_main *ms);
char	**copy_file(char *str, t_main *ms);
bool	parsing(char *str, t_main *ms);
void	close_fds(void);

//init.c
int     open_fd(char *str, t_main *ms);
void    init_ms(t_main **ms, char **av);
void	init_color(t_color **color, t_main *ms);
void	init_texture(t_texture **texture, t_main *ms);
void	init_map(t_map **map, t_main *ms);

//color_parsing.c
int		parse_colors(t_main *ms);
int		set_floor_ceiling(t_main *ms);
int		parse_floor(t_color *c, char *arg);
int		parse_ceiling(t_color *c, char *arg);
int		set_color_bit(char *arg, u_int32_t *color_bit, int *i);

//texture parsing
int		parse_texture(t_main *ms);
int		parse_indiv_textures(t_texture *t, char *direction);
int		texture_pathfinder(char *arg, t_main *ms, int path_i, char *dir);
void	check_valid_path(char *path, t_main *ms);
int		which_path(char *direction);

//parsing utils.c
char		*find_identifier(t_main *ms, char *identifier);
bool		valid_up_to_identifier(char *initial, char *identifier);
u_int32_t	create_rgba(int r, int g, int b, int a);
int			find_identifier_pos(t_main *ms, char *identifier);

//checks.c
void	elements_check(t_main *ms);
bool	detect_loose_char(t_main *ms);
char	**find_valid_lines(t_main *ms);
bool	is_valid_line(char *line);
bool	is_map_last(t_main *ms);
bool	are_there_repeats(t_main *ms);

//printing functions
void	print_color_struct(t_color *c);
void	print_textures(t_texture *t);


