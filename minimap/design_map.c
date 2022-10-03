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
					game->mapp->win_width/2 + j,
					color);
			j++;
		}
		i++;
	}
}

void	create_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	borders_of_minimap(game);
	length_of_square_minimap(game);
	// player_as_circle(game, 0x0000ff);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->new_image, 10,10);
}
