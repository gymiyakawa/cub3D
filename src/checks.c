
#include "../inc/cub3d.h"

bool	detect_loose_char(t_main *ms)
{
	int		i;

	i = -1;
	while (ms->file_copy[++i] && i < ms->map->i_first_line)
	{
		if (is_valid_line(ms->file_copy[i]) == true)
			continue ;
		if (is_empty_line(ms->file_copy[i]) == false)
			return (true);
	}
	return (false);
}

void	elements_check(t_main *ms)
{
	ms->valid_lines = find_valid_lines(ms);
	if (are_there_repeats(ms) == true)
		error_and_exit(E_RPT_ELEM, ms);
	if (detect_loose_char(ms) == true)
		error_and_exit(E_INV_LINE, ms);
	ms->valid_lines = ft_free_array((*ms).valid_lines);
}

char	**find_valid_lines(t_main *ms)
{
	char	**valid_lines;

	valid_lines = ft_calloc(7, sizeof(char *));
	if (!valid_lines)
		error_and_exit(E_MALLOC, ms);
	valid_lines[0] = ft_strdup(find_identifier(ms, "NO"));
	if (!valid_lines[0])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[1] = ft_strdup(find_identifier(ms, "SO"));
	if (!valid_lines[1])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[2] = ft_strdup(find_identifier(ms, "WE"));
	if (!valid_lines[2])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[3] = ft_strdup(find_identifier(ms, "EA"));
	if (!valid_lines[3])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[4] = ft_strdup(find_identifier(ms, "F"));
	if (!valid_lines[4])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[5] = ft_strdup(find_identifier(ms, "C"));
	if (!valid_lines[5])
		error_and_exit(E_MSS_ELEM, ms);
	valid_lines[6] = NULL;
	return (valid_lines);
}

char	**make_charset(void)
{
	char	**charset;

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

bool	is_valid_line(char *line)
{
	char	**charset;
	int		i;
	int		j;

	charset = make_charset();
	i = 0;
	while (charset[i] != NULL)
	{
		j = -1;
		while (line[++j])
		{
			if (valid_up_to_identifier(&line[0], &line[j]) == false)
				continue ;
			if (ft_strncmp(charset[i], &line[j], ft_strlen(charset[i])) == 0)
			{
				charset = x_free(charset);
				return (true);
			}
		}
		i++;
	}
	charset = x_free(charset);
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

// bool	is_map_last(t_main *ms)
// {
// 	int		i;
// 	int		j;
// 	char	*map_line;

// 	map_line = find_identifier(ms, "1");
// 	i = 0;
// 	while (ms->file_copy[i])
// 	{
// 		j = 0;
// 		while (j < 6)
// 		{
// 		}
// 		i++;
// 	}
// }