
#include "../inc/cub3d.h"

// NO ./path_to_the_north_texture
// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture



int	parse_texture(t_main *ms)
{
	char *arg;

	arg = find_identifier_variant(ms, "NO");
			printf("\narg: %s\n", arg);
	if (parse_indiv_textures(ms, "NO") != 0)
		error_and_exit(E_PRS_TXT, ms);
		
		
	return (0);
}

int	parse_indiv_textures(t_main *ms, char *direction)
{
	t_img	*img;

	img = which_texture(ms, direction);
	if (!img)
		return (-1);
	return (0);
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

char *find_identifier_variant(t_main *ms, char *identifier)
{
	char	*line;
	char	*tmp;
	int		i;

	close(ms->fd);
	ms->fd = open(ms->filename, O_RDONLY);
	line = get_next_line(ms->fd);
	while (line)
	{
		tmp = line;
		i = 0;
		while (line[i])
		{
			if (ft_strncmp(&line[i], identifier, ft_strlen(identifier)) == 0)
			{
				if (valid_up_to_identifier(tmp, &line[i]) == false)
					break;
				return (line);
			}
			i++;
		}
		if (line)
			line = x_free(line);
		line = get_next_line(ms->fd);
	}
	close(ms->fd);
	return (NULL);
}