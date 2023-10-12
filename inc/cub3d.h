
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

// ERROR MESSAGES

#define E_MAP "Input file inexistent or not conforming to .cub extension\n"
#define E_AC "Only two arguments for cub3d (the first is the program's name)\n"
#define E_MALLOC "Error on malloc\n"
#define E_OPEN "Error opening fd\n"
#define E_BIG "Map too big for this screen\n"
#define E_PRS_COL "Invalid color parameter\n"

// FUNCTION PROTOTYPES

//map_parsing.c
int	    check_map(t_main *ms);
int	    open_and_allocate_map(char *str, t_main *ms);
int     check_input_extension(char *str, t_main *ms);

//error.c
void    error_and_exit(char *str, t_main *ms);

//cub3d.c
bool	parsing(char *str, t_main *ms);

//init.c
void    init_ms(t_main **ms, char **av);
void	init_color(t_color **color);
void	init_texture(t_texture *texture);
void	init_map(t_map **map);

//color_parsing.c
int		parse_colors(t_main *ms);
int		set_floor_ceiling(t_main *ms);
char	*find_identifier(t_main *ms, char identifier);
bool	valid_up_to_identifier(char *initial, char *identifier);
int		parse_floor(t_color *c, char *arg);
int		parse_ceiling(t_color *c, char *arg);
int		set_color_bit(char *arg, int *color_bit, int *i);
int		create_trgb(int t, int r, int g, int b);

	// printing functions
void	print_color_struct(t_color *c);

