/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:13:34 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/05 14:40:45 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_color_minimap(t_game *game, int x, int y)
{
	int	color;

	color = 0;
	if ((int)((game->minimap->magic_x) / 10 + \
		(x - game->minimap->start_x) / 10) >= game->mapp->map_x
	|| (int)((game->minimap->magic_y) / 10 + \
	(y - game->minimap->start_y) / 10) >= game->mapp->map_y)
		return (0);
	if (ft_strlen(game->newestmap[(int)((game->minimap->magic_y) / 10 + \
		(y - game->minimap->start_y) / 10)]) < (int)((game->minimap->magic_x) / \
		10 + (x - game->minimap->start_x) / 10))
		return (0);
	if (game->newestmap[(int)((game->minimap->magic_y) / 10 + \
		(y - game->minimap->start_y) / 10)][(int)((game->minimap->magic_x) / \
		10 + (x - game->minimap->start_x) / 10)] == '0' \
		|| ft_check_player_map(game, (game->minimap->magic_x) / 10 + \
		(x - game->minimap->start_x) / 10, (game->minimap->magic_y) / 10 + \
		(y - game->minimap->start_y) / 10))
		color = 0x808080;
	else if (game->newestmap[(int)((game->minimap->magic_y) / 10 + \
		(y - game->minimap->start_y) / 10)][(int)((game->minimap->magic_x) / \
		10 + (x - game->minimap->start_x) / 10)] == '1')
		color = 0x339999;
	return (color);
}

void	ft_put_minimap(t_game *game)
{
	int		x;
	int		y;
	int		color;

	game->minimap->magic_x = 0;
	game->minimap->magic_y = 0;
	if (game->minimap->start_x == 0)
		game->minimap->magic_x = game->mapp->position_map_x * 10 - \
			game->minimap->win_width / 2;
	if (game->minimap->start_y == 0)
		game->minimap->magic_y = game->mapp->position_map_y * 10 - \
			game->minimap->win_height / 2;
	y = (int)game->minimap->start_y;
	while (y < game->minimap->win_height)
	{
		x = (int)game->minimap->start_x;
		while (x < game->minimap->win_width)
		{
			color = ft_color_minimap(game, x, y);
			ft_put_in_minimap_image(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_mini_moving_map(t_game *game)
{
	double	i;
	double	j;
	double	size_text;

	i = 0.0;
	j = 0.0;
	size_text = 10.0;
	if ((game->minimap->win_width / 2 - \
		game->mapp->position_map_x * size_text) > 0)
		i = fabs(game->minimap->win_width / 2 - \
			game->mapp->position_map_x * size_text);
	else if ((game->minimap->win_width / 2 - \
			game->mapp->position_map_x * size_text) <= 0)
		i = 0.0;
	if ((game->minimap->win_height / 2 - \
		game->mapp->position_map_y * size_text) > 0)
		j = fabs(game->minimap->win_height / 2 - \
			game->mapp->position_map_y * size_text);
	else if ((game->minimap->win_height / 2 - \
			game->mapp->position_map_y * size_text) <= 0)
		j = 0.0;
	game->minimap->start_x = i;
	game->minimap->start_y = j;
	ft_put_minimap(game);
}

void	ft_create_minimap(t_game *game)
{
	ft_borders_of_minimap(game);
	ft_mini_moving_map(game);
	ft_length_of_square_minimap(game);
	ft_player_as_circle(game, 0x0000ff);
	ft_draw_line(game, 0xff0000);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->minimap->new_image, 10, 10);
}
