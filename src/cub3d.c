/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:18:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/10 17:06:02 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	parsing(char *str, t_main *data)
{
	check_input_extension(str, data);
	open_and_allocate_map(str, data);
	check_map(data);
	return (TRUE);
}

// int	initialize_data(t_main *data)
// {
	// map->pixel = 0;
	// map->y_max = 0;
	// map->x_max = 0;
	// map->flag = 0;
	// map->y = 0;
	// map->x = 0;
	// map->p_y = 0;
	// map->p_x = 0;
	// map->e_y = 0;
	// map->e_x = 0;
	// return (0);
// }

//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
int	main(int ac, char **av)
{
	// (void)ac;
	// (void)av;
	t_main	data;
	
	if (ac == 2)
	{
		initialize_data(&data);
		if (parsing(av[1], &data))
		{
			data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
			if (!data.mlx)
				exit(0);
			map.win = mlx_new_window(map.mlx, (map.x_max * 64), (map.y_max * 64),
					"./so_long");
			if (!map.win)
				exit(0);
			if (assets_to_images(&map) == false)
				error_and_message(1, &map);
			images_to_screen(&map);
			mlx_key_hook(map.win, alicia_keys, &map); //same name; check parameters
			mlx_loop_hook(map.win, 17, 2, exit_win, &map); //change parameters //bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
			mlx_loop(map.mlx); //this seems fine; parameter is mlx_t* mlx
		}
	}
	else
		ft_printf("Gimme a map I can use, buddy.\n");
	//free data here?
}
