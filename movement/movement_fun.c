/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:28:25 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/04 19:28:26 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    movement_fun(t_game *game, char axis, int direction)
{

    if (axis == 'y' && direction == UP && game->gamer->player_posx >0
        && game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
        && game->gamer->player_posy < game->mapp->map_y*IMG_W)
    {
        game->gamer->player_posy -= game->gamer->speed;
        game->gamer->moved++;
        put_player(game, 0, 0x00ff00);
    }
    else if (axis == 'y' && direction == DOWN && game->gamer->player_posx >0
        && game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
        && game->gamer->player_posy < game->mapp->map_y*IMG_W)
    {
        game->gamer->player_posy += game->gamer->speed;
        game->gamer->moved++;
        put_player(game, 0, 0x00ff00);
    }
    else if (axis == 'x' && direction == LEFT && game->gamer->player_posx >0
        && game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
        && game->gamer->player_posy < game->mapp->map_y*IMG_W) /// will be removed
    {
        game->gamer->player_posx -= game->gamer->speed;
        game->gamer->moved++;
        put_player(game, 0, 0x00ff00);
    }
    else if (axis == 'x' && direction == RIGHT && game->gamer->player_posx >0
        && game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
        && game->gamer->player_posy < game->mapp->map_y*IMG_W) /// will be removed
    {
        game->gamer->player_posx += game->gamer->speed;
        game->gamer->moved++;
        put_player(game, 0, 0x00ff00);
    }
}
