#include "../inc/cub3d.h"

void	free_main_struct(t_main *ms)
{
	if (ms->colors)
		ms->colors = x_free(ms->colors);
	if (ms)
	{
		if (ms->filename)
			ms->filename = x_free(ms->filename);
		ms = x_free(ms);
	}
}
