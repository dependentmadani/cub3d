/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:10:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/06 13:10:07 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_player_as_circle(t_game *game, int color)
{
	int	i;
	int	j;
	int	r;
	int	d;
	int	a;

	r = 5;
	i = -r;
	while (i < 10)
	{
		j = -r;
		while (j < 10)
		{
			a = (i * i) + (j * j);
			d = sqrt(a);
			if (r >= d)
				ft_put_in_minimap_image(game, game->minimap->win_width / 2 + i, \
					game->minimap->win_height / 2 + j, \
					color);
			j++;
		}
		i++;
	}
}

int	ft_draw_line(t_game *game, int color)
{
	double	d_x;
	double	d_y;
	int		pixel;
	double	pixel_dx;
	double	pixel_dy;

	d_x = 0;
	d_y = 0;
	d_x = cos(game->gamer->player_angle) * 10;
	d_y = sin(game->gamer->player_angle) * 10;
	pixel = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pixel;
	d_y /= pixel;
	pixel_dx = game->minimap->win_width / 2;
	pixel_dy = game->minimap->win_height / 2;
	while (pixel > 0)
	{
		ft_put_in_minimap_image(game, pixel_dx, pixel_dy, color);
		pixel_dx -= d_x;
		pixel_dy -= d_y;
		pixel--;
	}
	return (0);
}

void	ft_put_in_minimap_image(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->minimap->addr_img + (y * game->minimap->line_len_mini + \
		((x) * game->minimap->bpp_mini / 8));
	*(int *)pixel = color;
}

void	ft_borders_of_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->minimap->win_width)
	{
		j = 0;
		while (j < game->minimap->win_height)
		{
			if ((i == 0) || (i == game->minimap->win_width - 1) || (j == 0)
				|| (j == game->minimap->win_height - 1))
				ft_put_in_minimap_image(game, i, j, 0x1100ff00);
			j++;
		}
		i++;
	}
}

void	ft_length_of_square_minimap(t_game *game)
{
	int	length_width;
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
