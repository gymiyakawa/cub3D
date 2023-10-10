/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:23:41 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/10 20:21:56 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_and_message(int nb, t_map *map)
{
	ft_printf("Error\n");
	if (nb == 1)
		ft_printf("There's an issue with your fd.\n");
	else if (nb == 2)
		ft_printf("Map doesn't fit this screen.\n");
	else if (nb == 3)
		ft_printf("Map is not rectangular.\n");
	else if (nb == 4)
		ft_printf("Gimme 1s or get lost.\n");
	else if (nb == 5)
		ft_printf("Not the right asssets here, bud.\n");
	else if (nb == 6)
		ft_printf("Path no goodo. Gimme a map I can use, buddy.\n");
	else if (nb == 7)
		ft_printf("An issue with your assets has been detected.\n");
	free_table(map->map);
	exit(1);
}

int	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	return (0);
}

int	exit_win(void)
{
	exit(1);
}
