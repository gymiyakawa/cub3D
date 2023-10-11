/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:00:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/11 16:43:35 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <fcntl.h>
#include <stdbool.h> 
#include "structs.h"

/*
		DEFINITIONS
*/
#define WIDTH 30
#define HEIGHT 30
#define TRUE 1
#define FALSE 0


/*
		ERROR MESSAGES
*/

#define E_PRS_COL "error: invalid color parameter\n"

/*
		FUNCTION PROTOTYPES
*/
	// Initialization
void	init_structs(t_main *main, char **av);
void	init_color(t_color *color);


	// error and exit functions
void	free_main_struct(t_main *ms);
void    error_and_exit(char *str, t_main *data);


	//	color parsing
int		parse_colors(t_main *ms);
char	*find_identifier(t_main *ms, char identifier);
bool	valid_up_to_identifier(char *initial, char *identifier);
int		parse_floor(t_color *c, char *arg);
int		parse_ceiling(t_color *c, char *arg);
int		set_color_bit(char *arg, int *color_bit, int *i);
int		create_trgb(int t, int r, int g, int b);
	// printing functions
void	print_color_struct(t_color *c);