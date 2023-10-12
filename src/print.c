#include "../inc/cub3d.h"

void	print_color_struct(t_color *c)
{//remember to delete this function
		printf("\nfloor colors\n");
		printf("f R: %d\n", c->f_red);
		printf("f G: %d\n", c->f_green);
		printf("f B: %d\n", c->f_blue);
		printf("f color: %d\n", c->f_color);
		printf("\nceiling colors\n");
		printf("c R: %d\n", c->c_red);
		printf("c G: %d\n", c->c_green);
		printf("c B: %d\n", c->c_blue);
		printf("c color: %d\n", c->c_color);
		return ;
}