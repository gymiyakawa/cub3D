

#include "../inc/cub3d.h"

int	parse_map(t_main *ms)
{
	char	*temp;

	temp = find_identifier(ms, "1");
	if (!temp)
		return (-1);
	ms->map->maze = copy_maze(temp, ms);
	check_if_closed(ms, ms->map);
	if (find_player_start(ms->map->maze, ms)) //rethink the error handling in the find_player_start function?
		check_for_limits(ms->map, ms); //maybe this should be called sooner
	return (0);
}

//goes through the maze and finds the longest string/ sets y_max for width
//also finds maze height and sets x_max for height; checks screen limits
void	check_for_limits(t_map *map, t_main *ms)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map->maze[i] != NULL)
	{
		j = ft_strlen(map->maze[i]);
		if (j > map->y_max)
			map->y_max = j;
		i++;
	}
	map->x_max = i;
	if (map->y_max >= MAX_WIDTH || map->x_max >= MAX_HEIGHT)
		error_and_exit(E_BIG, ms);
}

//extracts the maze from the file_copy, calling the function that checks 
//if each line has only the accepted characters, freeing if needed
char **copy_maze(char *str, t_main *ms)
{
	char	**maze;
	int		i;
	int		j;

	i = 0;
	j = 0;
	maze = ft_calloc(ms->line_count + 1, sizeof(char *)); //the line count is actually for the whole .cub file; should I substract and realloc after we find out the size of the maze itself? or no need because we x_free(maze) in the end anyway?
	if (!maze)
		error_and_exit(E_MALLOC, ms);
	while (ft_strncmp(str, ms->file_copy[j], ft_strlen(str)) != 0 && ms->file_copy[j] != NULL)
		j++;
	while (ms->file_copy && ms->file_copy[j] && ms->file_copy[j][0] != '\0') 
	{
		if (!validate_maze_line(ms->file_copy[j]))
			handle_maze_line_error(maze, ms, j);
		maze[i] = ft_strdup(ms->file_copy[j]);
		if(!maze[i])
			free_partial_maze(maze, ms, i);
		i++;
		j++;
	}
	maze[i] = NULL; 
	return(maze);
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

void	handle_maze_line_error(char **maze, t_main *ms, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		maze[i] = x_free(maze[i]);
			i++;
	}
	maze = x_free(maze);
	error_and_exit(E_INV_CHAR, ms);
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

//checks if there is only one player 
//determines the player's position and orientation
bool	find_player_start(char **maze, t_main *ms)
{//consider the bool in this function
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (maze && maze[i])
	{
		j = 0;
		while (maze[i][j])
		{
			if (ft_strchr("NSEW", maze[i][j]))
			{
				ms->map->p_view = maze[i][j]; 
				ms->map->p_y = j;
				ms->map->p_x = i;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		error_and_exit(E_PLAY, ms);
	return (TRUE);
}

// void	check_if_closed(t_main *ms, char **maze)
// {//checks if the borders are composed of only 1 or spaces (Tristan and Sam's idea of checking 8 points around 0s)	
// 	check walls first //need to check the player, if it is close to an opening as well
	
// }

// int	check_top_and_bottom_walls(t_map *map)
// {
// 	int	i;

// 	i = ft_strlen(map->maze[0]);
// 	map->x_max = ft_strlen(map->maze[map->y_max - 1]);
// 	if (i > 40 || map->x_max > 40)
// 		error_and_message(2, map);
// 	else if (i - 1 != map->x_max)
// 	{
// 		error_and_message(3, map);
// 		return (1);
// 	}
// 	else
// 		map->x_max = 0;
// 	while (map->maze[0][map->x_max] != '\n')
// 	{
// 		if (map->maze[0][map->x_max] != '1')
// 			error_and_message(4, map);
// 		if (map->maze[map->y_max - 1][map->x_max] != '1')
// 			error_and_message(4, map);
// 		map->x_max++;
// 	}
// 	return (0);
// }

// int	check_right_and_left_walls(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = ft_strlen(map->maze[0]);
// 	j = ft_strlen(map->maze[map->y_max - 1]) - 1;
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		if (ft_strlen(map->maze[map->y]) != i)
// 		{
// 			error_and_message(3, map);
// 		}
// 		map->y++;
// 	}
// 	map->y = 1;
// 	while (map->maze[map->y] != map->maze[map->y_max - 1])
// 	{
// 		if (map->maze[map->y][0] != '1' || map->maze[map->y][j] != '1')
// 		{
// 			error_and_message(4, map);
// 		}
// 		map->y++;
// 	}
// 	return (0);
// }
