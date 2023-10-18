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
		if (!dup_maze[i])
			error_and_exit(E_MALLOC, ms);
		i++;
	}
	dup_maze[i] = NULL;
	return (dup_maze);
}

bool	flood_fill(t_main *ms, char **dup, int y, int x)
{//need to fix it for when 0 or player is at the end of the shortest string
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	up = y > 0;
	down = y < ms->map->y_max - 1;
	left = x > 0;
	right = x < ms->map->x_max - 1;
	if (y < 0 || y > ms->map->y_max - 1 || x < 0 || x > ms->map->x_max)
		return (FALSE);
	if (dup[y][x] == 'A')
		return (TRUE);
	if (dup[y][x] == '0' || ft_strchr("NSEW", dup[y][x]))
	{
		if ((up && left && dup[y - 1][x - 1] == ' ') || (up && right && dup[y
				- 1][x + 1] == ' ') || (down && left && dup[y + 1][x
				- 1] == ' ') || (down && right && dup[y + 1][x + 1] == ' '))
			return (FALSE);
		dup[y][x] = 'A';
		if (!flood_fill(ms, dup, y - 1, x) || !flood_fill(ms, dup, y + 1, x)
			|| !flood_fill(ms, dup, y, x - 1) || !flood_fill(ms, dup, y, x + 1))
			return (FALSE);
	}
	return (TRUE);
}

bool	check_if_closed(t_main *ms, char **m, int y, int x)
{
	char	**dup_maze;

	dup_maze = duplicate_maze(m, ms);
	if (!dup_maze)
		error_and_exit(E_DUP, ms);
	while (m[y] != NULL)
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '0' || (y == ms->map->p_y && x == ms->map->p_x))
			{
				if (!flood_fill(ms, dup_maze, y, x))
				{
					dup_maze = ft_free_array(dup_maze);
					return (FALSE);
				}
			}
			x++;
		}
		y++;
	}
	dup_maze = ft_free_array(dup_maze);
	return (TRUE);
}

void	pad_maze(t_main *ms, char **maze)
{
	int		i;
	char	*padded;

	i = 0;
	padded = NULL;
	while (maze[i])
	{
		padded = add_padding(maze[i], ms->map->x_max);
		if (!padded)
			error_and_exit(E_PAD, ms);
		free(maze[i]);
		maze[i] = padded;
		i++;
	}
}

char	*add_padding(char *str, int len)
{
	int		i;
	char	*new;

	i = ft_strlen(str);
	if (i == len)
		return (ft_strdup(str));
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, len + 1);
	while (i < len)
		new[i++] = ' ';
	return (new);
}
