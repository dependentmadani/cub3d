/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:22:35 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/09 05:22:36 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mapp->addr + (y * game->mapp->line_length + x * (game->mapp->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


/***
///example to based on to work on raycasting


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.bits_per_pixel = 1;
	img.line_length = 10;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int i = 0;
	int j = 0;
	while (i < 50)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF00FF);
		//mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
		i++;
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
		//mlx_pixel_put(mlx, mlx_win, 100,100,0x00FF00FF);
	mlx_destroy_image(mlx, img.img);
	printf("was here\n");
	mlx_loop(mlx);
}

***/