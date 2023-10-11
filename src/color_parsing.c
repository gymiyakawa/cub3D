/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:01 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/11 15:32:07 by gmiyakaw         ###   ########.fr       */
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
	
						printf("arg: %s\n", arg);
	
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
	char	*tmp;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		tmp = line;
		i = 0;
		while (line[i])
		{
						// printf("line i %s\n", &line[i]);
						// printf("identifier %s\n", identifier);
						// printf("strlen %zu\n", ft_strlen(identifier));
						// if (ft_strncmp(&line[i], identifier, ft_strlen(identifier) == 0))
			if (line[i] == identifier)
			{
				if (valid_up_to_identifier(tmp, &line[i]) == false)
					break;
				return (&line[i]);
			}
			i++;
		}
		line = x_free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

bool	valid_up_to_identifier(char *initial, char *identifier)
{
	while (initial != identifier)
	{
		if (*initial != ' ')
		{
									printf("found invalid characters pre identifier\n");
			return (false);
		}
		initial++;
	}
	return (true);
}

int	parse_floor(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != 'F' && arg[i])
		i++;
	if (f_red(c, arg) != 0)
		return (-1);
							printf("f_red: %d\n", c->f_red);

	return (0);
}

int	f_red(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[++i] != ',' && arg[i] != '\n')
	{
		if (arg[i] == ' ')
			continue ;
		if (ft_isdigit(arg[i]) == false)
			return (1);
		if (c->f_red != 0)
			c->f_red *= 10;
		c->f_red += (int)arg[i] - '0';
	}
	return (0);
}
