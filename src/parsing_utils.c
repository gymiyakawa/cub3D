
#include "../inc/cub3d.h"

char *find_identifier(t_main *ms, char identifier)
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
			if (line[i] == identifier)
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

bool	valid_up_to_identifier(char *initial, char *identifier)
{
	while (initial != identifier)
	{
		if (*initial != ' ')
		{
			return (false);
		}
		initial++;
	}
	return (true);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char *find_identifier_array(t_main *ms, char *identifier)
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