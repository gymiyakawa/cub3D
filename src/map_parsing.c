

#include "../inc/cub3d.h"

int	parse_map(t_main *ms)
{
	char	*temp;

	temp = find_identifier(ms, "1");
	if (!temp)
		error_and_exit(E_INV_MAP, ms);
	//should I add an identify first line of maze function here? sending temp and doing a ft_strncmp (so I can allocate properly in the function below)
	ms->map->maze = copy_maze(temp, ms);
	if (find_player_start(ms->map->maze, ms))
		check_for_limits(ms->map, ms);
	if (!check_if_closed(ms, ms->map->maze, 0, 0))
		error_and_exit(E_MAZ_OP, ms);
	pad_maze(ms, ms->map->maze);
	return (0);
}

//this function checks screen limits; it goes through the maze,
//finds the longest string and sets y_max for width;
//also finds maze height and sets x_max for height
void	check_for_limits(t_map *map, t_main *ms)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->maze[i] != NULL)
	{
		j = ft_strlen(map->maze[i]);
		if (j > map->x_max)
			map->x_max = j;
		i++;
	}
	map->y_max = i;
	if (map->y_max >= MAX_WIDTH || map->y_max >= MAX_HEIGHT)
		error_and_exit(E_BIG, ms);
}

//extracts the maze from the file_copy, calling the function that checks
//if each line has only the accepted characters, freeing lines if needed
char	**copy_maze(char *str, t_main *ms)
{
	char	**maze;
	int		i;
	int		j;

	i = 0;
	j = 0;
	maze = ft_calloc(ms->line_count + 1, sizeof(char *)); //the line count is actually for the whole .cub file; should I substract and realloc after we find out the size of the maze itself? or no need because we x_free(maze) in the end anyway?
	if (!maze)
		error_and_exit(E_MALLOC, ms);
	while (ft_strncmp(str, ms->file_copy[j], ft_strlen(str)) != 0
		&& ms->file_copy[j] != NULL)
		j++;
	while (ms->file_copy[j] && ms->file_copy[j][0] != '\0')
	{
		if (!validate_maze_line(ms->file_copy[j]))
			handle_maze_line_error(maze, ms, j);
		maze[i] = ft_strdup(ms->file_copy[j]);
		if (!maze[i])
			free_partial_maze(maze, ms, i);
		i++;
		j++;
	}
	maze[i] = NULL;
	maze = clean_maze(maze, i, ms);
	return (maze);
}

void	handle_maze_line_error(char **maze, t_main *ms, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		maze[i] = x_free(maze[i]);
		i++;
	}
	maze = x_free(maze);
	error_and_exit(E_INV_CHAR, ms);
}

//checks if there is only one player
//determines the player's position and orientation
bool	find_player_start(char **maze, t_main *ms)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (maze && maze[y])
	{
		x = 0;
		while (maze[y][x])
		{
			if (ft_strchr("NSEW", maze[y][x]))
			{
				ms->map->p_view = maze[y][x];
				ms->map->p_x = x;
				ms->map->p_y = y;
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		error_and_exit(E_PLAY, ms);
	return (TRUE);
}
