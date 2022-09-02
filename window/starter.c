/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:47:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/08/28 11:47:07 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initializer(t_game *game)
{
    game->gamer->fov = 60;
    game->gamer->speed = 20; ///20 pixels per second
    game->gamer->player_posx = 0; /// depends on his position in the map
    game->gamer->player_posy = 0; /// depends on his position in the map
    game->map_w = 320; /// 320 units means 320 pixels
    game->map_h = 200;
    game->mapp->map_x = 0;
    game->mapp->map_y = 0;
}

void    creation_window(t_game *game)
{
    initializer(game);
    create_window(game);
}
