/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:56:49 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 13:48:45 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	collision_with_wall(t_game *game, double pos_x, double pos_y)
{
	int	estimation_posx;
	int	estimation_posy;

	estimation_posx = (pos_x) / IMG_H;
	estimation_posy = (pos_y) / IMG_W;
	if (estimation_posx >= game->mapp->map_x
		|| estimation_posy >= game->mapp->map_y)
		return (0);
	if (estimation_posx < 0 || estimation_posy < 0)
		return (0);
	if (game->newestmap[estimation_posy]
		&& game->newestmap[estimation_posy][estimation_posx] == '1')
		return (1);
	return (0);
}

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->img->addr_win + (y * game->img->line_len_win + \
			x * (game->img->bpp_win / 8));
	*(int *)pixel = color;
}

void	get_texture_info(t_game *game, int x, int y, double end_y)
{
	int	*color;
	int	x_start;
	int	y_start;
	int	y_value;

	y_start = (int)((game->mapp->win_height / 2) - (end_y / 2));
	x_start = (game->img->offset) % 64;
	y_value = (y - y_start) * 64 / end_y;
	color = (int *)(game->text->addr_text + (int)(y_value * \
		game->text->line_len_text + ((x_start) * game->text->bpp_text / 8)));
	img_pix_put(game, x, y, *color);
}

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	draw(t_game *game, double end_x, double end_y)
{
	int		x;
	double	y;

	x = end_x;
	y = 0;
	while (y < game->mapp->win_height)
	{
		if (y < (int)((game->mapp->win_height / 2) - (end_y / 2)))
			img_pix_put(game, x, y, game->c_color);
		else if (y >= (int)((game->mapp->win_height / 2) - (end_y / 2))
			&& y < (int)((game->mapp->win_height / 2) + (end_y / 2)))
			get_texture_info(game, x, y, end_y);
		else if (y >= (int)((game->mapp->win_height / 2) + (end_y / 2)))
			img_pix_put(game, x, y, game->f_color);
		y++;
	}
	return (0);
}
