#include "../inc/cub3d.h"

void	print_color_struct(t_color *c)
{
	//remember to delete this function
	printf("\nfloor colors\n");
	printf("f R: %d\n", c->f_red);
	printf("f G: %d\n", c->f_green);
	printf("f B: %d\n", c->f_blue);
	printf("f color: %u\n", c->f_color);
	printf("\nceiling colors\n");
	printf("c R: %d\n", c->c_red);
	printf("c G: %d\n", c->c_green);
	printf("c B: %d\n", c->c_blue);
	printf("c color: %u\n", c->c_color);
	return ;
}

void	print_textures(t_texture *t)
{
	printf("\nprinting textures\n");
	printf("NO\n");
	printf("%s\n", t->paths[0]);
	printf("width: %d\n", t->mlx_textures[0]->width);
	printf("height: %d\n", t->mlx_textures[0]->height);
	printf("bbp: %d\n", t->mlx_textures[0]->bytes_per_pixel);
	printf("pixels: %s\n", t->mlx_textures[0]->pixels);
	printf("\nSO\n");
	printf("%s\n", t->paths[1]);
	printf("width: %d\n", t->mlx_textures[1]->width);
	printf("height: %d\n", t->mlx_textures[1]->height);
	printf("bbp: %d\n", t->mlx_textures[1]->bytes_per_pixel);
	printf("pixels: %s\n", t->mlx_textures[1]->pixels);
	printf("\nEA\n");
	printf("%s\n", t->paths[2]);
	printf("width: %d\n", t->mlx_textures[2]->width);
	printf("height: %d\n", t->mlx_textures[2]->height);
	printf("bbp: %d\n", t->mlx_textures[2]->bytes_per_pixel);
	printf("pixels: %s\n", t->mlx_textures[2]->pixels);
	printf("\nWE\n");
	printf("%s\n", t->paths[3]);
	printf("width: %d\n", t->mlx_textures[3]->width);
	printf("height: %d\n", t->mlx_textures[3]->height);
	printf("bbp: %d\n", t->mlx_textures[3]->bytes_per_pixel);
	printf("pixels: %s\n", t->mlx_textures[3]->pixels);
	return;
}
