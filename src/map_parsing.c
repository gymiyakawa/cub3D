

#include "../inc/cub3d.h"

int	parse_map(t_main *ms)
{
	char	*temp;

	temp = find_identifier(ms, "1");
	if (!temp)
		return (-1);
	ms->map->maze = copy_maze(temp, ms);
	if (find_player_start(ms->map->maze, ms)) //rethink the error handling in the find_player_start function?
		check_for_limits(ms->map, ms); //maybe this should be called sooner
	check_if_closed(ms, ms->map->maze);
	return (0);
}

//this function checks screen limits; it goes through the maze,
//finds the longest string and sets y_max for width 
//also finds maze height and sets x_max for height
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
//if each line has only the accepted characters, freeing lines if needed
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
	maze = clean_maze(maze, i, ms); // I should delete the extra spaces at the end of the strings too
	return(maze);
}

//deletes the extra strings at the end of the maze
//and calls function that trims end of strings
char **clean_maze(char **maze, int lines, t_main *ms)
{
	int		i;
	int		last_line;
	char	**clean_maze;

	i = 0;
	last_line = 0;
	while(i < lines)
	{
		if (!only_spaces_or_new_lines(maze[i]))
			last_line = i;
		i++;
	}
	clean_maze = ft_calloc(last_line + 2, sizeof(char *));
	if (!clean_maze)
		error_and_exit(E_MALLOC, ms);
	i = 0;
	while(i <= last_line)
	{
		clean_maze[i] = trim_end_spaces(maze[i]);
		if(!clean_maze[i])
			free_partial_maze(clean_maze, ms, i);
		maze[i] = x_free(maze[i]);
		i++;
	}
	ms->map->y_max = last_line + 1; //maybe I don't need this because check_for_limits comes after
	maze = x_free(maze);
	clean_maze[last_line + 1] = NULL;
	return(clean_maze);
}

char	*trim_end_spaces(char *str)
{
	int		end;
	char	*trimmed_str;

	if (!str)
		return (NULL);
	trimmed_str = NULL;
	end = ft_strlen(str) - 1;
	while (end >= 0 && str[end] == ' ')
		end--;
	trimmed_str = ft_substr(str, 0, end + 1);
	return(trimmed_str);
}

bool only_spaces_or_new_lines(char *str)
{//check this function
    int i = 0;

    if (!str || str[0] == '\0' || (str[0] == '\n' && str[1] == '\0'))
        return (TRUE);
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
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
	error_and_exit(E_INV_CHAR, ms); //how come this is signaling the wrong order of elements?
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
				ms->map->p_view = maze[y][x]; //double check the position of our x and y according to the mlx (and see check if closed function below)
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

//checks if the 0s and the player do not touch a space
// void check_if_closed(t_main *ms, char **m)
// {//work on this function
//     int x;
//     int y;

//     x = 0;
// 	y = 0;
//     while (m[y])
//     {
//         x = 0;
//         while (m[y][x] && m[y][x] != '\n')
//         {
//             if (m[y][x] == '0' || (y == ms->map->p_y && x == ms->map->p_x))
//             {
//                 if (y == 0 || y == ms->map->y_max || x == 0
// 					|| (x + 1) == ms->map->x_max)
//                     error_and_exit(E_MAZ_OP, ms);
//             }
//             x++;
//         }
//         y++;
//     }
// }

//APPLY FLOOD FILL BECAUSE THE OTHER APPROACH IS NOT WORKING (ACTUALLY, TEST TRISTAN AND SAM'S CODE TO SEE IF IT WORKS)