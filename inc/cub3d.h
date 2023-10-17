
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

// ERROR MESSAGES

#define E_MAP "Input file inexistent or not conforming to .cub extension\n"
#define E_INV_MAP "Invalid map\n"
#define E_AC "Only two arguments for cub3d (the first is the program's name)\n"
#define E_MALLOC "Error on malloc\n"
#define E_OPEN "Error opening fd\n"
#define E_BIG "Map too big for this screen\n"
#define E_PRS_COL "Invalid color parameter\n"
#define E_PRS_TXT "Invalid texture parameter\n"
#define E_PARS "Parsing error\n"
#define E_INV_CHAR "Invalid character in maze line or .cub out of order\n"
#define E_PLAY "Wrong or insufficient player number\n"
#define E_MAZ_OP "Maze or player is not within closed walls\n"
#define E_DUP "Unable to duplicate maze\n"
#define TEST "TESTY TEST!\n" //delete this later

// FUNCTION PROTOTYPES

//map_parsing.c
int	    parse_map(t_main *ms);
char    **copy_maze(char *str, t_main *ms);
bool	validate_maze_line(char *line);
void	handle_maze_line_error(char **maze, t_main *ms, int i);
bool	find_player_start(char **maze, t_main *ms);
void	free_partial_maze(char **maze, t_main *ms, int i);
char	**clean_maze(char **maze, int lines, t_main *ms);
bool    only_spaces_or_new_lines(char *str);
char	*trim_end_spaces(char *str);
bool	check_if_closed(t_main *ms, char **m);
void	check_for_limits(t_map *map, t_main *ms);


//error.c
void    error_and_exit(char *str, t_main *ms);
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
int		set_color_bit(char *arg, int *color_bit, int *i);

//texture parsing
int		parse_texture(t_main *ms);
int		parse_indiv_textures(t_main *ms, char *direction);
t_img	*which_texture(t_main *ms, char *direction);
int	    texture_pathfinder(char *arg, t_main *ms, t_img *img);

//parsing utils.c
bool	valid_up_to_identifier(char *initial, char *identifier);
int		create_trgb(int t, int r, int g, int b);
char	*find_identifier(t_main *ms, char *identifier);
void	check_valid_path(char *path, t_main *ms, t_img *img);
int     check_input_extension(char *str, t_main *ms);

//printing functions
void	print_color_struct(t_color *c);
void	print_textures(t_texture *t);
void	print_img_struct(t_img *img);

