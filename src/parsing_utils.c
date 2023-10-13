
#include "../inc/cub3d.h"

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

//	creates a color integer, using bit shifting as per MLX42
//	standards
u_int32_t	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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
void	check_valid_path(char *path, t_main *ms)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		path = x_free(path);
		error_and_exit(E_OPEN, ms);
	}
	close (fd);
	return ;
}
