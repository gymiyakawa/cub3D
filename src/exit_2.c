
#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *ms)
{
    printf("Error\n");
    printf("%s\n",str);
    clean_exit(ms);
    exit(1);
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

void	close_fds(void)
{
	int	i;

	i = 3;
	while (i++ < MAX_FILES)
		close(i);
	return ;
}
