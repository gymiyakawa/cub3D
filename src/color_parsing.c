/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:01 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/11 11:21:22 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



// F 220,100,0
// C 225,30,0

/*
	find CHAR.
		go through the line and build a f_red until a "," is found.
			check if it's valid.
		do the same for f_green
		do the same for f_blue, but using \n 
				build f_color and free all f.
	do the same for C

*/

int parse_colors(t_main *ms)
{
	char	*arg;

	arg = find_identifier(ms->fd, 'F');
	if (arg == NULL)
		error_and_exit(E_PRS_COL, ms);
	if (parse_floor(ms->colors, arg) != 0)
		error_and_exit(E_PRS_COL, ms);
	arg = x_free(arg);
	arg = find_identifier(ms->fd, 'C');
	if (arg == NULL)
		error_and_exit(E_PRS_COL, ms);
	
	return (0);
}

char *find_identifier(int fd, char identifier)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i = 0;
		while (line[i++])
		{
			if (line[i] == identifier)
				return (&line[i]);
		}
	}
	return (NULL);
}

int	parse_floor(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != 'F')
		i++;
	if (f_red(c, arg) != 0)
		return (-1);

	return (0);
}

int	f_red(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != ',')
	{
		if (ft_isprint(arg[i] + '0') == true)
		{
			if (c->f_red != 0)
				c->f_red *= 10;
			c->f_red = arg[i] + '0';
			
		}
		
		
	}
	return (0);
}
