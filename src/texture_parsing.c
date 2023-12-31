/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:15:22 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/11/02 10:34:47 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
	Texture parsing is organized around identifying and populating
	the right index of the array:
	
	typedef struct s_texture
	{
		char			**paths;
		mlx_texture_t	**mlx_textures;
		t_main	*ms;
	}	t_texture;

	both paths and mlx_textures contain 4 elements, coded in the same
	order. North, south, east, west.
	once identfied by which_path(), an integer will be given. 
	This integer (defined in cub3d.h) is the index for both arrays.
	From then on it's a simple process of parsing the correct file path
	and valdating that it leads to a file, assigning it to the correct
	element in the array if all is good.
*/

int	parse_texture(t_main *ms)
{
	if (parse_indiv_textures(ms->texture, "NO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "SO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "EA") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "WE") != 0)
		error_and_exit(E_PRS_TXT, ms);
	check_repeat_textures(ms->texture);
	return (0);
}

void	check_repeat_textures(t_texture *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->paths[++i])
	{
		j = 0 + i;
		while (t->paths[++j])
		{
			if (!ft_strncmp(t->paths[i], t->paths[j], ft_strlen(t->paths[j])))
				error_and_exit(E_RPT_TXT, t->ms);
		}
	}
	return ;
}

int	parse_indiv_textures(t_texture *t, char *direction)
{
	int		path_i;
	char	*arg;

	path_i = which_path(direction);
	if (path_i < 0)
		error_and_exit(E_PRS_TXT, t->ms);
	arg = find_identifier(t->ms, direction);
	if (!arg)
		return (-1);
	if (texture_pathsetter(arg, t->ms, path_i, direction) != 0)
		return (-2);
	t->mlx_textures[path_i] = mlx_load_png(t->paths[path_i]);
	if (t->mlx_textures[path_i] == NULL)
		error_and_exit(E_PRS_TXT, t->ms);
	return (0);
}

int	texture_pathsetter(char *arg, t_main *ms, int path_i, char *dir)
{
	int		i;
	int		j;
	char	*path;

	path = ft_calloc(ft_strlen(arg), sizeof(char));
	if (!path)
		error_and_exit(E_MALLOC, ms);
	j = 0;
	i = find_identifier_pos(ms, dir) + 2;
	while (arg[i] == ' ')
		i++;
	while (arg[i])
	{
		if (arg[i] == ' ' || arg[i] == '\n')
			break ;
		else
			path[j++] = arg[i++];
	}
	check_remaining_arg(arg, i, ms);
	check_valid_path(path, ms);
	ms->texture->paths[path_i] = ft_strdup(path);
	path = x_free(path);
	return (0);
}

int	which_path(char *direction)
{
	if (ft_strcmp(direction, "NO") == 0)
		return (NORTH);
	if (ft_strcmp(direction, "SO") == 0)
		return (SOUTH);
	if (ft_strcmp(direction, "EA") == 0)
		return (EAST);
	if (ft_strcmp(direction, "WE") == 0)
		return (WEST);
	else
		return (-1);
}
