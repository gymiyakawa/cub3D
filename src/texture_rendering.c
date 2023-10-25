/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:15:28 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/25 13:15:31 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	texture_calculations(t_ray *ray, t_texture *text)
{
	double	wall_x;
	int		text_i;

	if (ray->side == EAST || ray->side == WEST)
		wall_x = ray->py + ray->perpwalldist * ray->raydir_y;
	else
		wall_x = ray->px + ray->perpwalldist * ray->raydir_x;
	wall_x -= floor(wall_x);
	text_i = get_text_index(ray);
	text->text_x = (int)(wall_x * text->mlx_textures[text_i]->width);
	if ((ray->side == EAST || ray->side == WEST) && ray->raydir_x > 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->raydir_y < 0)
		text->text_x = text->mlx_textures[text_i]->width - text->text_x - 1;
	return ;
}

int	get_text_index(t_ray *ray)
{
	if (ray->side == NORTH)
		return (NORTH);
	if (ray->side == SOUTH)
		return (SOUTH);
	if (ray->side == EAST)
		return (EAST);
	if (ray->side == WEST)
		return (WEST);
	else
	{
		perror(E_TEX_IND);
		return (0);
	}
}

void	render_texture(t_ray *ray, t_texture *text, int i)
{
	double			step;
	double			tex_pos;
	int				line;
	uint32_t		px_color;
	mlx_texture_t	*t;

	text->text_i = get_text_index(ray);
	t = text->mlx_textures[text->text_i];
	step = 1.0 * (double)t->height / (double)ray->line_height;
	tex_pos = ((double) ray->draw_start - (double) HEIGHT / 2
			+ (double) ray->line_height / 2) * step;
	line = ray->draw_start - 1;
	while (++line < ray->draw_end)
	{
		text->text_y = (int) tex_pos % t->height;
		tex_pos += step;
		px_color = make_px_color(text, t);
		mlx_put_pixel(ray->ms->game, i, line, px_color);
	}
}

uint32_t	make_px_color(t_texture *text_strt, mlx_texture_t *t)
{
	uint32_t	color;
	int			r;
	int			g;
	int			b;
	int			a;

	text_strt->text_y++;
	if (text_strt->text_x == 0)
		text_strt->text_x = 1;
	r = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel)];
	g = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 1];
	b = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 2];
	a = t->pixels[(t->width * text_strt->text_y * t->bytes_per_pixel) - \
		(text_strt->text_x * t->bytes_per_pixel) + 3];
	color = create_rgba(r, g, b, a);
	return (color);
}

// option to render without any textures
void	no_texture(t_ray *ray, int i)
{
	int	line;

	line = ray->draw_start - 1;
	while (++line < ray->draw_end)
	{
		if (ray->side == NORTH)
			mlx_put_pixel(ray->ms->game, i, line, RED);
		if (ray->side == SOUTH)
			mlx_put_pixel(ray->ms->game, i, line, BLUE);
		if (ray->side == EAST)
			mlx_put_pixel(ray->ms->game, i, line, YELLOW);
		if (ray->side == WEST)
			mlx_put_pixel(ray->ms->game, i, line, GREEN);
	}
}
