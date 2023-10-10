/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <raruiz-r@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:23:41 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/12/12 14:28:58 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

bool	open_image(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 1)
		return (false);
	close(fd);
	return (true);
}

int	error_and_message(int nb, t_map *map)
{
	ft_printf("Error\n");
	if (nb == 1)
		ft_printf("We identified an issue with your fd.\n");
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
	exit(0);
}

int	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

int	exit_win(void)
{
	exit(0);
}

int	check_map_extension(char *str)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".ber";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
	{
		ft_printf("You failed to deliver the goodies. Bye!\n");
		exit(0);
	}
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
		{
			ft_printf("No soup for you until you give me a proper map.\n");
			exit(0);
		}
		i--;
		j--;
	}
	return (0);
}
