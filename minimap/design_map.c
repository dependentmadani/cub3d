/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:13:34 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/02 09:13:35 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_in_minimap_image(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->minimap->addr_img + (y* game->minimap->line_len_mini + ((x)*game->minimap->bpp_mini/8));
	*(int *)pixel = color;
}

void	borders_of_minimap(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i <= game->minimap->win_width)
	{
		j = 0;
		while (j <= game->minimap->win_height)
		{
			if ((i == 0) || (i == game->minimap->win_width-1) || (j == 0) || (j == game->minimap->win_height-1))
				put_in_minimap_image(game, i , j, 0x1100ff00);
			j++;
		}
		i++;
	}
}

void	length_of_square_minimap(t_game *game)
{
	int length_width;
	int	length_height;
	
	length_width = 10;
	if (game->mapp->map_x * length_width < game->minimap->win_width)
		length_width = game->minimap->win_width / game->mapp->map_x;
	length_height = 10;
	if (game->mapp->map_y * length_height < game->minimap->win_height)
		length_height = game->minimap->win_height / game->mapp->map_y;
	game->minimap->length_square_width = length_width;
	game->minimap->length_square_height = length_height;
}

void	player_as_circle(t_game *game, int color)
{
	int i;
	int j;
	int r;
	int x;
	int y;
	int d;
	int a;

	r = 5;
	x = 0;
	y = 0;
	i = -r;
	while(i<10)
	{
		j = -r;
		while(j<10)
		{
			a=((i-x)*(i-x))+((j-y)*(j-y));
			d=sqrt(a);
			if(r>=d)
				put_in_minimap_image(game, game->minimap->win_width/2 + i,
					game->minimap->win_height/2 + j,
					color);
			j++;
		}
		i++;
	}
}

// int draw_line_direction(t_game *game, int color, int angle)
// {
//     double d_x;
//     double d_y;
//     int pixel;
//     double pixel_dx;
//     double pixel_dy;

//     d_x = game->gamer->player_dx;
//     d_y = game->gamer->player_dy;
//     pixel = sqrt((d_x * d_x) + (d_y * d_y));
//     d_x /= pixel;
//     d_y /= pixel;
//     pixel_dx = game->minimap->win_width / 2;
//     pixel_dy = game->minimap->win_height / 2;
//     while (pixel)
//     {
//         mlx_pixel_put(game->mlx, game->win, pixel_dx, pixel_dy, color);
//         if (angle > P3)
//         {
//             pixel_dx -= d_x;
//             pixel_dy += d_y;
//         }
//         else if (angle >= 0)
//         {
//             pixel_dx += d_x;
//             pixel_dy += d_y;        
//         }
//         pixel--;
//     }
//     return (0);
// }

int draw_line(t_game *game, int color)
{
	double d_x;
	double d_y;
	int pixel;
	double pixel_dx;
	double pixel_dy;

	d_x = 0;
	d_y = 0;
    d_x = cos(game->gamer->player_angle)*10;
    d_y = sin(game->gamer->player_angle)*10;
	pixel = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pixel;
	d_y /= pixel;
	printf("the value of d_x {%f} and pixel {%d}\n", d_x, pixel);
	pixel_dx = game->minimap->win_width/2;
	pixel_dy = game->minimap->win_height/2;
	while (pixel > 0)
	{
		put_in_minimap_image(game, pixel_dx, pixel_dy, color);
		pixel_dx -= d_x;
		pixel_dy -= d_y;
		pixel--;
	}
	return (0);
}

void	create_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	borders_of_minimap(game);
	length_of_square_minimap(game);
	player_as_circle(game, 0x0000ff);
	draw_line(game, 0xff0000);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->new_image, 10,10);
}
