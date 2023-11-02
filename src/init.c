/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:21:46 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/11/02 10:23:58 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	open_fd(char *str, t_main *ms)
{
	ms->fd = open(str, O_RDONLY);
	if (ms->fd < 0)
		error_and_exit(E_OPEN, ms);
	return (ms->fd);
}

void	init_ms(t_main **ms, char **av)
{
	*ms = ft_calloc(1, sizeof(t_main));
	if (!*ms)
		error_and_exit(E_MALLOC, *ms);
	(*ms)->line_count = line_count(av[1], *ms);
	(*ms)->file_copy = copy_file(av[1], *ms);
	(*ms)->valid_lines = NULL;
	(*ms)->game = NULL;
	init_color(&(*ms)->colors, *ms);
	init_texture(&(*ms)->texture, *ms);
	init_map(&(*ms)->map, *ms);
	init_background(&(*ms)->bg, *ms);
	init_ray(&(*ms)->ray, *ms);
	(*ms)->mlx = NULL;
	return ;
}

void	init_ray(t_ray **ray, t_main *ms)
{
	*ray = ft_calloc(1, sizeof(t_ray));
	if (!*ray)
		error_and_exit(E_MALLOC, ms);
	(*ray)->rot_speed = ROT_SPEED;
	(*ray)->mov_speed = MOV_SPEED;
	(*ray)->ms = ms;
	return ;
}

void	init_background(t_background **bg, t_main *ms)
{
	*bg = ft_calloc(1, sizeof(t_background));
	if (!*bg)
		error_and_exit(E_MALLOC, ms);
	(*bg)->ceiling = NULL;
	(*bg)->floor = NULL;
	(*bg)->ms = ms;
	return ;
}

void	init_color(t_color **color, t_main *ms)
{
	*color = ft_calloc(1, sizeof(t_color));
	if (!*color)
		error_and_exit(E_MALLOC, ms);
	(*color)->floor_ceiling = ft_calloc(2, sizeof(char *));
	if (!(*color)->floor_ceiling)
		error_and_exit(E_MALLOC, ms);
	(*color)->f_red = 256;
	(*color)->f_blue = 256;
	(*color)->f_green = 256;
	(*color)->c_red = 256;
	(*color)->c_blue = 256;
	(*color)->c_green = 256;
	(*color)->ms = ms;
	return ;
}
