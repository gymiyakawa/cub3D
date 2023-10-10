/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:18:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/10/10 16:42:23 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int main (int ac, char **av) {
	
// 	(void) ac;
// 	(void) av;
	
// 	char *str = {"hello"};
	
	
// 	printf("%s \n", str);
	
// 	char *str2 = ft_strdup(str);
	
// 	printf("%s \n", str2);
	
// 	return (0);
// }


//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
int	main(int ac, char **av)
{
	// t_map	map;

	if (ac == 2)
	{
		
	// 	initialize_map(&map);
	// 	check_map_extension(argv[1]);
	// 	open_and_allocate_map(argv[1], &map);
	// 	check_map(&map);
	// 	map.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", TRUE);
	// 	if (!map.mlx)
	// 		exit(0);
	// 	map.win = mlx_new_window(map.mlx, (map.x_max * 64), (map.y_max * 64),
	// 			"./so_long");
	// 	if (!map.win)
	// 		exit(0);
	// 	if (assets_to_images(&map) == false)
	// 		error_and_message(1, &map);
	// 	images_to_screen(&map);
	// 	mlx_key_hook(map.win, alicia_keys, &map); //same name; check parameters
	// 	mlx_loop_hook(map.win, 17, 2, exit_win, &map); //change parameters //bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
	// 	mlx_loop(map.mlx); //this seems fine; parameter is mlx_t* mlx
		(void)av;
		
	}
	else
		printf("hello you\n");
	// 	ft_printf("Gimme a map I can use, buddy.\n");
	return 0;
}
