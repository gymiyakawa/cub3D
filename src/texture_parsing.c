
#include "../inc/cub3d.h"

int	parse_texture(t_main *ms)
{
	if (parse_indiv_textures(ms->texture, "NO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "SO") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "WE") != 0)
		error_and_exit(E_PRS_TXT, ms);
	if (parse_indiv_textures(ms->texture, "EA") != 0)
		error_and_exit(E_PRS_TXT, ms);
	return (0);
}

int	parse_indiv_textures(t_texture *t, char *direction)
{
	int		path_index;
	char	*arg;

	path_index = which_path(direction);
	if (path_index < 0)
		error_and_exit(E_PRS_TXT, t->ms);
	arg = find_identifier(t->ms, direction);
	if (!arg)
		return (-1);
	if (texture_pathfinder(arg, t->ms, path_index) != 0)
		return (-2);
	t->mlx_textures[path_index] = mlx_load_png(t->paths[path_index]);
	if (t->mlx_textures[path_index] == NULL)
		error_and_exit(E_PRS_TXT, t->ms);
	return (0);
}

int	texture_pathfinder(char *arg, t_main *ms, int path_index)
{
	int		i;
	int		j;
	char	*path;

	path = ft_calloc(ft_strlen(arg), sizeof(char));
	if (!path)
		error_and_exit(E_MALLOC, ms);
	i = 2;
	j = 0;
	while (arg[++i])
	{
		if (arg[i] == ' ' || arg[i] == '\n')
			continue ;
		else
			path[j++] = arg[i];
	}
	check_valid_path(path, ms);
	ms->texture->paths[path_index] = ft_strdup(path);
	path = x_free(path);
	return (0);
}

int	which_path(char *direction)
{
	if (ft_strcmp(direction, "NO") == 0)
		return (NO_INDEX);
	if (ft_strcmp(direction, "SO") == 0)
		return (SO_INDEX);
	if (ft_strcmp(direction, "EA") == 0)
		return (EA_INDEX);
	if (ft_strcmp(direction, "WE") == 0)
		return (WE_INDEX);
	else
		return (-1);
}

