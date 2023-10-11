

#pragma once

#include "libft/libft.h"
#include "structs.h"
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <fcntl.h>
#include <stdbool.h> 

/*
		DEFINITIONS
*/
#define WIDTH 30
#define HEIGHT 30
#define TRUE 1
#define FALSE 0

//error messages:
#define MAP_E "Input file inexistent or not conforming to .cub extension"
#define AC_E "Only two arguments for cub3d (the first is the program's name)"
#define MAL_E "Error on malloc"

//map_parsing.c
int	    check_map(t_main *data);
int	    open_and_allocate_map(char *str, t_main *data);
int     check_input_extension(char *str, t_main *data);

//error.c
void    error_and_exit(char *str, t_main *data);

//cub3d.c
bool	parsing(char *str, t_main *data);
int     initialize_data(t_main *data);

/*
		ERROR MESSAGES
*/

#define E_PRS_COL "\nparsing error on color section\n"

/*
		FUNCTION PROTOTYPES
*/
	// Initialization
void	init_structs(t_main *main);
void	init_color(t_color *color);


	// error and exit functions
void    error_and_exit(char *str, t_main *data);


	//	color parsing
int		parse_colors(t_main *ms);
char	*find_identifier(int fd, char identifier);
int		parse_floor(t_color *c, char *arg);
int		f_red(t_color *c, char *arg);
