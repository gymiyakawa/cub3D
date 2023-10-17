
#include "../inc/cub3d.h"

bool	valid_up_to_identifier(char *initial, char *identifier)
{
	while (initial != identifier)
	{
		if (*initial != ' ')
		{
			return (FALSE);
		}
		initial++;
	}
	return (TRUE);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char *find_identifier(t_main *ms, char *identifier)
{
	char	*line;
	int		i;
	int		j;

	j = -1;
	while (ms->file_copy[++j] != NULL)
	{
		line = ms->file_copy[j];
		i = 0;
		while (line[i])
		{
			if (ft_strncmp(&line[i], identifier, ft_strlen(identifier)) == 0)
			{
				if (valid_up_to_identifier(&line[0], &line[i]) == false)
					break;
				return (line);
			}
			i++;
		}
	}
	return (NULL);
}

// checks if the path to an img is valid and assigns fd at the correct img structure
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

int	check_input_extension(char *str, t_main *ms)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".cub";
	i = ft_strlen(str) - 1;
	j = 3;
	if (!str)
        error_and_exit(E_MAP, ms);
	while (comp && str && j >= 0)
	{
		if (comp[j] != str[i])
		    error_and_exit(E_MAP, ms);
		i--;
		j--;
	}
	return (0);
}
				// old, deprecated keeping for backup
// char *find_identifier(t_main *ms, char identifier)
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
// 			if (line[i] == identifier)
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
