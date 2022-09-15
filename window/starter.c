/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:47:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/10 11:13:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initializer(t_game *game)
{
    game->gamer->fov = 60.0;
    game->gamer->speed = 5; ///8 pixels per second
    game->gamer->player_posx = 0; /// depends on his position in the map
    game->gamer->player_posy = 0; /// depends on his position in the map
    game->gamer->moved = 0;
    game->gamer->player_angle = PI/2; // it means 90 degree, it should be modified depends on the direction of player at starts
    game->gamer->player_dx = cos(game->gamer->player_angle)*game->gamer->speed;
    game->gamer->player_dy = sin(game->gamer->player_angle)*game->gamer->speed;
    // game->map_w = 320; /// 320 units means 320 pixels
    // game->map_h = 200;
    game->mapp->map_x = 0;
    game->mapp->map_y = 0;
    game->mapp->theta = 0;
    game->mapp->map_size = 0; /// To update: calculate number of rows * number of columns
    game->mapp->win_width = 640;
    game->mapp->win_height = 480;
}

void    creation_window(t_game *game)
{
    initializer(game);
    create_window(game);
}
