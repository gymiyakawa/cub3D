
#include "../inc/cub3d.h"

void    error_and_exit(char *str, t_main *ms)
{
                        // printf("MS: %p\n", ms);
    printf("Error\n");
    printf("%s\n",str);
	clean_exit(ms);
    exit(1);
}
