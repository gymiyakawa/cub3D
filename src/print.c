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


// renders teh am p in .cub but without any checks and hardcoded variables.
//		DEPRECATED but kept as base for an actual map renderer
// mlx_image_t	*make_test_map_img(t_main *ms, t_map *map)
// {
// 	int	x;
// 	int	y;


// 	map->m_img = mlx_new_image(ms->mlx, 800, 800);

// 	map->x = 8;
// 	map->y = 8;
// 	map->m_size= 64;
	
// 					int scale_x = 0;;
// 					int scale_y = 0;
	
// 	x = -1;
// 	while (++x < map->x)
// 	{
		
// 		y = -1;
// 		while(++y < map->y)
// 		{ 
// 			if (map->maze[x][y] == 1 + '0')
// 			{
// 				scale_x = x * 100;
// 				scale_y = y * 100;
// 				print_square(map->m_img, scale_x, scale_y, (uint32_t)0xFFFFFFFF);
// 			}
// 			else
// 			{
// 				scale_x = x * 100;
// 				scale_y = y * 100;
// 				print_square(map->m_img, scale_x, scale_y, (uint32_t)0x000000FF);
// 			}
// 		}
// 	}
// 	return (map->m_img);
// }


mlx_image_t	*make_test_map_img(t_main *ms, t_map *map)
{
	int	x;
	int	y;

	map->m_img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);

	map->x = 8;
	map->y = 8;
	map->m_size= 64;
					int scale_x = 0;;
					int scale_y = 0;
	y = -1;
	while (++y <= map->y)
	{
		x = -1;
		while(++x < map->x)
		{ 
			if (map->test_map[y * map->x + x] == 1)
			{
				scale_x = x * 100;
				scale_y = y * 100;
				print_square(map->m_img, scale_x, scale_y, (uint32_t)0xFFFFFFFF);
			}
			else
			{
				scale_x = x * 100;
				scale_y = y * 100;
				print_square(map->m_img, scale_x, scale_y, (uint32_t)0x000000FF);
			}
		}
	}
	return (map->m_img);
}

// print a 100x100 square strating from position x y.
void	print_square(mlx_image_t *img, int x, int y, u_int32_t color)
{
	int i = -1;
	while (++i < 100)
	{
		int j = -1;
		while (++j < 100)
		{
			mlx_put_pixel(img, x + j, y + i, color);
		}
	}
	return ;
}

