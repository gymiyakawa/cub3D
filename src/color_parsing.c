
#include "../inc/cub3d.h"


int parse_colors(t_main *ms)
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
	ms->colors->floor_ceiling[0] = ft_strdup(arg);
	if (arg)
		arg = x_free(arg);
	
	arg = find_identifier(ms, "C");
	if (!arg)
		return (-1);
	ms->colors->floor_ceiling[1] = ft_strdup(arg);
	if (arg)
		arg = x_free(arg);
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
	c->c_color = create_trgb(0, c->c_red, c->c_green, c->c_blue);
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
	c->f_color = create_trgb(0, c->f_red, c->f_green, c->f_blue);
	return (0);
}

int	set_color_bit(char *arg, int *color_bit, int *i)
{
	while (arg[++*i] != ',' && arg[*i] != '\n')
	{
		if (arg[*i] == ' ')
			continue ;
		if (ft_isdigit(arg[*i]) == false)
			return (1);
		if (*color_bit != 0)
			*color_bit *= 10;
		*color_bit += (int)arg[*i] - '0';
	}
	if (*color_bit < 0 || *color_bit > 255)
		return (2);
	else
		return (0);
}
