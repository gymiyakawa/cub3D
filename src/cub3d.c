/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:16:35 by raruiz-r          #+#    #+#             */
/*   Updated: 2023/10/25 15:03:38 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	parsing(char *str, t_main *ms)
{
	check_input_extension(str, ms);
	parse_map(ms);
	elements_check(ms);
	parse_colors(ms);
	parse_texture(ms);
	return (TRUE);
}

void	init_mlx(t_main *ms)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ms->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!ms->mlx)
		error_and_exit(E_MLX_INI, ms);
	ms->game = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	if (!ms->game)
	{
		mlx_close_window(ms->mlx);
		error_and_exit(E_WIN, ms);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_main	*ms;

	if (ac == 2)
	{
		init_ms(&ms, av);
		if (parsing(av[1], ms))
		{
			init_mlx(ms);
			make_background(ms->mlx, ms->colors, ms->bg);
			set_raycasting_vars(ms->ray);
			raycasting(ms);
			mlx_key_hook(ms->mlx, &key_bindings, ms);
			mlx_loop(ms->mlx);
		}
	}
	else
	{
		printf("Error\n");
		printf(E_AC);
		exit(1);
	}
	return (0);
}
