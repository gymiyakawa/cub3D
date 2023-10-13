
#include "../inc/cub3d.h"

bool	check_loose_char(t_main *ms)
{
	char	**valid_lines;
	int		i;
	int		j;

	valid_lines = ft_calloc(6, sizeof(char *));
	if (!valid_lines)
		error_and_exit(E_MALLOC, ms);
	valid_lines = find_valid_lines(ms);
	i = 0;
	while (ms->file_copy[i])
	{
		j = 0;
		while (j < 7)
		{
			if (!ft_strcmp(ms->file_copy[i], valid_lines[j]))
				break;
		}
		
	}
}

void	element_checks(t_main *ms)
{
	ms->valid_lines = find_valid_lines(ms);
	if (are_there_repeats(ms) == true)
		error_and_exit(E_RPT_ELEM, ms);
	if (is_map_last(ms) == false)
		error_and_exit(E_WRG_ORD, ms);
}

char	**find_valid_lines(t_main *ms)
{
	char **valid_lines;

	valid_lines[0] = find_identifier(ms, "NO");
	if (!valid_lines[0])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[1] = find_identifier(ms, "SO");
	if (!valid_lines[1])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[2] = find_identifier(ms, "WE");
	if (!valid_lines[2])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[3] = find_identifier(ms, "EA");
	if (!valid_lines[3])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[4] = find_identifier(ms, "F");
	if (!valid_lines[4])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[5] = find_identifier(ms, "C");
	if (!valid_lines[5])
		error_and_exit(E_MSS_ELEM, ms);
	return (valid_lines);
}

char	**make_charset()
{
	char **charset;

	charset = ft_calloc(7, sizeof(char *));
	charset[0] = "NO";
	charset[1] = "SO";
	charset[2] = "EA";
	charset[3] = "WE";
	charset[4] = "F";
	charset[5] = "C";
	charset[6] = NULL;
	return (charset);
}

// super wrong, must be tired pqp...
bool	is_valid_line(char *line)
{
	char **charset;
	int	i;

	charset = make_charset();
	i = 0;
	while (charset[i] != NULL)
	{
		if (ft_strncmp(charset[i], line, ft_strnlen(line)) == 0)
		{
			if ()
			charset = ft_free_array(charset);
			return (true);
		}
			i++;
	}
	charset = ft_free_array(charset);
	return (false);
}

bool	are_there_repeats(t_main *ms)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (ms->file_copy[i])
	{
		if (is_valid_line(ms->file_copy[i]) == true)
			count++;
		i++;
	}
	if (count > 6)
		return (true);
	return (false);
}

bool	is_map_last(t_main *ms)
{
	int		i;
	int		j;
	char	*map_line;

	map_line = find_identifier(ms, "1");
	i = 0;
	while (ms->file_copy[i])
	{
		j = 0;
		while (j < 6)
		{
			
		}
		i++;
	}
	
	
}