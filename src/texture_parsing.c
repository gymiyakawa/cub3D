
#include "../inc/cub3d.h"

// NO ./path_to_the_north_texture
// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture

//find how to extract WIDTH / HEIGHT from the file in the address.
//
//pointer/instance/context/count??



int	parse_texture(t_main *ms)
{
	if (parse_indiv_textures(ms, "NO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms, "SO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms, "WE") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms, "EA") != 0)
		error_and_exit(E_PRS_TXT, ms);
	return (0);
}

int	parse_indiv_textures(t_main *ms, char *direction)
{
	t_img	*img;
	char	*arg;

	img = which_texture(ms, direction);
	if (!img)
		return (-1);
	arg = find_identifier(ms, direction);
	if (!arg)
		return (-2);
	if (texture_pathfinder(arg, ms, img) != 0)
		return (-3);
	return (0);
}

int	texture_pathfinder(char *arg, t_main *ms, t_img *img)
{
	char	*path;
	int		i;
	int		j;

	path = ft_calloc(ft_strlen(arg), sizeof(char));
	if (!path)
		error_and_exit(E_MALLOC, ms);
	i = -1;
	j = 0;
	while (arg[++i])
	{
		if (arg[i] == ' ')
			continue ;
		else
			path[j++] = arg[i];
	}
	check_valid_path(path, ms, img);
	(*img).path = ft_strdup(path);
	path = x_free(path);
	return (0);
}

// checks if the path is valid and assigns fd at the correct img structure
void	check_valid_path(char *path, t_main *ms, t_img *img)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (!fd)
	{
		path = x_free(path);
		error_and_exit(E_OPEN, ms);
	}
	(*img).text_fd = fd;
	return ;
}

t_img	*which_texture(t_main *ms, char *direction)
{
	if (ft_strcmp(direction, "NO") == 0)
		return (&ms->texture->n_tex);
	if (ft_strcmp(direction, "SO") == 0)
		return (&ms->texture->s_tex);
	if (ft_strcmp(direction, "WE") == 0)
		return (&ms->texture->w_tex);
	if (ft_strcmp(direction, "EA") == 0)
		return (&ms->texture->e_tex);
	else
		return (NULL);
}



		// old, deprecated. keeping for backup
// char *find_identifier_variant(t_main *ms, char *identifier)
// {
// 	char	*line;
// 	char	*tmp;
// 	int		i;

// 	close(ms->fd);
// 	ms->fd = open(ms->filename, O_RDONLY);
// 	line = get_next_line(ms->fd);
// 	while (line)
// 	{
// 		tmp = line;
// 		i = 0;
// 		while (line[i])
// 		{
// 			if (ft_strncmp(&line[i], identifier, ft_strlen(identifier)) == 0)
// 			{
// 				if (valid_up_to_identifier(tmp, &line[i]) == false)
// 					break;
// 				return (line);
// 			}
// 			i++;
// 		}
// 		if (line)
// 			line = x_free(line);
// 		line = get_next_line(ms->fd);
// 	}
// 	close(ms->fd);
// 	return (NULL);
// }