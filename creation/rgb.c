/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:31:18 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/06 12:31:18 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rgb_converter(t_game *game)
{
	game->c_color = ((game->c_rgb[0] << 16) + (game->c_rgb[1] << 8) + \
		(game->c_rgb[2]));
	game->f_color = ((game->f_rgb[0] << 16) + (game->f_rgb[1] << 8) + \
		(game->f_rgb[2]));
}

void	ft_assign_max_fov(t_game *game)
{
	if (game->mapp->map_x > game->mapp->map_y)
		game->mapp->max_fov = game->mapp->map_x + 1;
	else
		game->mapp->max_fov = game->mapp->map_y + 1;
}
