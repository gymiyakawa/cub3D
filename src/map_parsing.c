

#include "../inc/cub3d.h"

int	parse_map(t_main *ms)
{
	int		i;
	char	*temp;

	i = 0;
	temp = find_identifier(ms, "1");
	if (!temp)
		error_and_exit(E_INV_MAP, ms);
	i = check_maze_size(temp, ms);
	ms->map->maze = copy_maze(temp, ms, i);
	ms->map->i_first_line = get_first_line_i(ms->map);
	if (find_player_start(ms->map->maze, ms))
		check_for_limits(ms->map, ms);
	if (!check_if_closed(ms, ms->map->maze, 0, 0))
		error_and_exit(E_MAZ_OP, ms);
	pad_maze(ms, ms->map->maze);
	return (0);
}

int check_maze_size(char *str, t_main *ms)
{
    int start;
	int line_count;
	
	start = 0;
    while (ft_strncmp(str, ms->file_copy[start], ft_strlen(str)) != 0
		&& (ms->file_copy[start] != NULL || *ms->file_copy[start] != '\n'))
        start++;
    line_count = count_maze_lines(ms->file_copy, start + 2);
    ms->map->last_line = start + line_count;
									printf("MAZE LINES: %d\n", line_count);
									printf("LAST LINE: %d\n", ms->map->last_line);
    return (line_count);
}

int count_maze_lines(char **file_copy, int start)
{
    int count;
	
	count = 0;
    while (file_copy[start] && file_copy[start][0] != '\0') 
	{
        count++;
        start++;
    }
    return (count);
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
// char	**copy_maze(char *str, t_main *ms)
// {
// 	char	**maze;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	maze = ft_calloc(ms->line_count + 1, sizeof(char *)); //the line count is actually for the whole .cub file; should I substract and realloc after we find out the size of the maze itself? or no need because we x_free(maze) in the end anyway?
// 	if (!maze)
// 		error_and_exit(E_MALLOC, ms);
// 	while (ft_strncmp(str, ms->file_copy[j], ft_strlen(str)) != 0
// 		&& ms->file_copy[j] != NULL)
// 		j++;
// 	while (ms->file_copy[j] && ms->file_copy[j][0] != '\0')
// 	{
// 		if (!validate_maze_line(ms->file_copy[j]))
// 			handle_maze_line_error(maze, ms, j);
// 		maze[i] = ft_strdup(ms->file_copy[j]);
// 		if (!maze[i])
// 			free_partial_maze(maze, ms, i);
// 		i++;
// 		j++;
// 	}
// 	maze[i] = NULL;
// 	maze = clean_maze(maze, i, ms);
// 	return (maze);
// }
char	**copy_maze(char *str, t_main *ms, int line_count)
{
	int		i;
	int		j;
	char	**maze;

	i = 0;
	j = 0;
	maze = ft_calloc(line_count + 1, sizeof(char *));
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
							i = 0;
							while(maze[i] != NULL)
								printf("MAZE BEFORE CLEAN: %s\n", maze[i++]);
	maze = clean_maze(maze, ms);
							i = 0;
							while(maze[i] != NULL)
								printf("MAZE AFTER CLEAN: %s\n", maze[i++]);
	return (maze);
}

int	get_first_line_i(t_map *map)
{
	int	i;

	i = -1;
	while (map->ms->file_copy[++i])
	{
		if (!ft_strcmp(map->ms->file_copy[i], map->maze[0]))
			return (i);
	}
	return (-1);
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
