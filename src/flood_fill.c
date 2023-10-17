#include "../inc/cub3d.h"

// char	**duplicate_maze(char **maze, t_main *ms)
// {
// 	int		i;
// 	char	**dup_maze;

// 	i = 0;
// 	dup_maze = ft_calloc(sizeof(char *), (ms->map->y_max + 1));
// 	if (!dup_maze)
// 		return (NULL);
// 	while (i < ms->map->y_max)
// 	{
// 		dup_maze[i] = ft_strdup(maze[i]);
// 		i++;
// 	}
//     dup_maze[i] = NULL;
// 	return (dup_maze);
// }

//flood fill - checks if the 0s and the player do not touch a space
int	look_for_spaces(t_main *ms, char **dup, int y, int x)
{
    if (y < 0 || x < 0 || y > ms->map->y_max || x > ms->map->x_max)
        return (0);
	if (ft_strchr(" ", dup[y][x + 1]) || ft_strchr(" ", dup[y][x - 1])    
        || (ft_strchr(" ", dup[y + 1][x]) || ft_strchr(" ", dup[y - 1][x])
        || ft_strchr(" ", dup[y][x + 1]) || ft_strchr(" ", dup[y][x - 1])
        || ft_strchr(" ", dup[y + 1][x]) || ft_strchr(" ", dup[y - 1][x])))
        error_and_exit(TEST, ms);
	look_for_spaces(ms, dup, y, x + 1); 
    look_for_spaces(ms, dup, y, x - 1);
	look_for_spaces(ms, dup, y + 1, x);
	look_for_spaces(ms, dup, y - 1, x);
	look_for_spaces(ms, dup, y + 1, x + 1);
	look_for_spaces(ms, dup, y - 1, x - 1);
	look_for_spaces(ms, dup, y + 1, x - 1);
	look_for_spaces(ms, dup, y - 1, x + 1);
	return (0);
}

bool	check_if_closed(t_main *ms, char **m)
{//work on this function
    int 	y;
    int 	x;
	// char	**dup_maze;

	y = 0;
    x = 0;
	// dup_maze = duplicate_maze(m, ms);
	// if(!dup_maze)
	// 	error_and_exit(E_DUP, ms);
	while (m[y])
    {
        x = 0;
        while (m[y][x] != '\n')
        {
            if (m[y][x] == '0' || (y == ms->map->p_y && x == ms->map->p_x))
			{
                if (y == 0 || y == ms->map->y_max || (x + 1) == ms->map->x_max) //omitting x == 0 because it could be a space
                    return(FALSE);
                else
                    look_for_spaces(ms, m, y, x);
            }
            x++;
        }
        y++;
    }
	// dup_maze = x_free(dup_maze);
	return (TRUE);
}
