#include "../inc/cub3d.h"

void	print_color_struct(t_color *c)
{
	//remember to delete this function
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

void	print_textures(t_texture *t)
{
	printf("\nprinting textures\n");
	printf("NO\n");
	print_img_struct(&t->n_tex);
	printf("\nSO\n");
	print_img_struct(&t->s_tex);
	printf("\nWE\n");
	print_img_struct(&t->w_tex);
	printf("\nEA\n");
	print_img_struct(&t->e_tex);
	return;
}

void	print_img_struct(t_img *img)
{
	printf("HEIGHT: %d\n", img->height);
	printf("WIDTH: %d\n", img->width);
	printf("PATH: %s", img->path);
	printf("FD: %d\n", img->text_fd);
	return ;
}