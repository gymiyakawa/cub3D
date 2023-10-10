/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:00:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:23 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft/libft.h"
#include "structs.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h> 

#define WIDTH 30
#define HEIGHT 30
#define TRUE 1
#define FALSE 0

//error messages:
#define MAP_E "Input file inexistent or not conforming to .cub extension"


//map_parsing.c
int	check_map(t_main *data);
int	open_and_allocate_map(char *str, t_main *data);
int	check_input_extension(char *str, t_main *data);

//error.c
void    error_and_exit(char *str, t_main *data);

//cub3d.c
bool	parsing(char *str, t_main *data);