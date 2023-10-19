
#include "../inc/cub3d.h"

//deletes the extra strings at the end of the maze
//and calls function that trims end of strings
char	**clean_maze(char **maze, t_main *ms, int lines)
{
	int	i;
	int	last_line;

	i = 0;
	last_line = 0;
	while (i < lines)
	{
		if (!only_new_lines(maze[i]))
			last_line = i;
		i++;
	}
	i = 0;
	while (i <= last_line)
	{
						
		maze[i] = trim_end_spaces(maze[i]);
		if (!maze[i])
			free_partial_maze(maze, ms, i);
		i++;
	}
	maze[last_line + 1] = NULL;
	return (maze);
}

char	*trim_end_spaces(char *str)
{
	int		end;
	char	*trimmed_str;

	if (!str)
		return (NULL);
	trimmed_str = NULL;
	end = ft_strlen(str) - 1;
	while (end >= 0 && (str[end] == ' ' || str[end] == '\n'))
		end--;
	trimmed_str = ft_substr(str, 0, end + 1);
	str = x_free(str);
	return (trimmed_str);
}

bool	only_new_lines(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0' || (str[0] == '\n' && str[1] == '\0'))
		return (TRUE);
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	free_partial_maze(char **maze, t_main *ms, int i)
{
	while (i >= 0)
	{
		maze[i] = x_free(maze[i]);
		i--;
	}
	maze = x_free(maze);
	error_and_exit(E_MALLOC, ms);
}

//checks if each line has only the accepted characters
bool	validate_maze_line(char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr("NSEW10 \n", line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
