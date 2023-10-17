#include "../inc/cub3d.h"

char	**duplicate_maze(char **maze, t_main *ms)
{
	int		i;
	char	**dup_maze;

	i = 0;
	dup_maze = ft_calloc((ms->map->y_max + 1), sizeof(char *));
	if (!dup_maze)
		return (NULL);
	while (i < ms->map->y_max)
	{
		dup_maze[i] = ft_strdup(maze[i]);
        if(!dup_maze[i])
            error_and_exit(E_MALLOC, ms);
		i++;
	}
    dup_maze[i] = NULL;
	return (dup_maze);
}

//flood fill - checks if the 0s and the player do not touch a space
int	look_for_spaces(t_main *ms, char **dup, int y, int x)
{
    if (y < 0 || x < 0 || y >= ms->map->y_max || x >= ms->map->x_max
        || dup[y][x] == 'A')
        return (0);
	if (ft_strchr(" ", dup[y][x]))
        error_and_exit(E_MAZ_OP, ms);
    dup[y][x] = 'A';
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
{//when I get here, my trim end of strings doesn't work anymore
    int 	y;
    int 	x;
	char	**dup_maze;

	y = 0;
    x = 0;
	dup_maze = duplicate_maze(m, ms);
	if(!dup_maze)
		error_and_exit(E_DUP, ms);
	int i = 0;
    int j = 0;
    while(dup_maze[i] && (dup_maze[i][j] != '\n' || dup_maze[i][j] != '\0'))
    {
        printf("DUP MAZE %s and length %zu\n", dup_maze[i], ft_strlen(dup_maze[i]));
        i++;
    }
    while (m[y] != NULL)
    {
        x = 0;
        while (m[y][x] && (m[y][x] != '\n' || m[y][x] != '\0'))
        {
            if (m[y][x] == '0' || (y == ms->map->p_y && x == ms->map->p_x))
			{
                if (y == 0 || (y + 1) == ms->map->y_max || (x + 1) == ms->map->x_max
                    || x == 0)
                    return(FALSE);
                else
                    look_for_spaces(ms, dup_maze, y, x);
            }
            x++;
        }
        y++;
    }
	dup_maze = ft_free_array(dup_maze);
	return (TRUE);
}
