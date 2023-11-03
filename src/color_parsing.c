/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:26 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/11/03 14:25:00 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
	color parsing starts by identifying the lines in the file that contain
	the identifiers F and C, storing these lines in floor_ceiling[0] and [1],
	respectively.
	from there, both parse_floor() and parse_ceiling() are called where each
	bit that makes up a color number will be parsed and set before being
	assembled, via bit shifting, into the format MLX42 requires:

						RED		GREEN		BLUE		A(transparency)
						24 <<	16 <<		8 <<
*/

int	parse_colors(t_main *ms)
{
	if (set_floor_ceiling(ms) != 0)
		error_and_exit(E_PRS_COL, ms);
	if (parse_floor(ms->colors, ms->colors->floor_ceiling[0]) != 0)
		error_and_exit(E_PRS_COL, ms);
	if (parse_ceiling(ms->colors, ms->colors->floor_ceiling[1]) != 0)
		error_and_exit(E_PRS_COL, ms);
	return (0);
}

int	set_floor_ceiling(t_main *ms)
{
	char	*arg;

	arg = find_identifier(ms, "F");
	if (!arg)
		return (-1);
	count_commas(arg, ms);
	ms->colors->floor_ceiling[0] = ft_strdup(arg);
	arg = NULL;
	arg = find_identifier(ms, "C");
	if (!arg)
		return (-1);
	count_commas(arg, ms);
	ms->colors->floor_ceiling[1] = ft_strdup(arg);
	arg = NULL;
	return (0);
}

int	parse_ceiling(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != 'C' && arg[i])
		i++;
	if (set_color_bit(arg, &c->c_red, &i) != 0)
		return (-1);
	if (set_color_bit(arg, &c->c_green, &i) != 0)
		return (-2);
	if (set_color_bit(arg, &c->c_blue, &i) != 0)
		return (-3);
	c->c_color = create_rgba(c->c_red, c->c_green, c->c_blue, 255);
	return (0);
}

int	parse_floor(t_color *c, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != 'F' && arg[i])
		i++;
	if (set_color_bit(arg, &c->f_red, &i) != 0)
		return (-1);
	if (set_color_bit(arg, &c->f_green, &i) != 0)
		return (-2);
	if (set_color_bit(arg, &c->f_blue, &i) != 0)
		return (-3);
	c->f_color = create_rgba(c->f_red, c->f_green, c->f_blue, 255);
	return (0);
}

int	set_color_bit(char *arg, u_int32_t *color_bit, int *i)
{
	(*i)++;
	while (arg[*i] == ' ')
		(*i)++;
	while (ft_isdigit(arg[*i]) == true)
	{
		if (arg[*i] == ' ')
			return (1);
		if (*color_bit != INI_C_B)
			*color_bit *= 10;
		else
			*color_bit -= INI_C_B;
		*color_bit += (int)arg[*i] - '0';
		(*i)++;
	}
	if (*color_bit > 255)
		return (2);
	while (arg[*i] != ',' && arg[*i] != '\n')
	{
		if (arg[*i] != ' ')
			return (3);
		(*i)++;
	}
	return (0);
}
