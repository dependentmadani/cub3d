/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:53:41 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/06 13:53:42 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_texture_minimap(t_game *game, int x, int y)
{
	int	*color;
	int	x_start;
	int	y_start;

	x_start = (int)(x) % 10;
	y_start = (int)(y) % 10;
	color = (int *)(game->minimap->addr_text + (int)(y_start * \
		game->minimap->line_len_text + \
		((x_start) * game->minimap->bpp_text / 8)));
	return (*color);
}

int	ft_check_player_map(t_game *game, int x, int y)
{
	if (game->newestmap[y][x] == 'W')
		return (1);
	else if (game->newestmap[y][x] == 'S')
		return (1);
	else if (game->newestmap[y][x] == 'N')
		return (1);
	else if (game->newestmap[y][x] == 'E')
		return (1);
	return (0);
}
