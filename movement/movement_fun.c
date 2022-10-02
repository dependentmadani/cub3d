/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:28:25 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 17:54:57 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    movement_fun(t_game *game, char axis, int direction)
{
	if (axis == 'y' && direction == UP && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		if (!collision_with_wall(game, game->gamer->player_posx-game->gamer->player_dx , game->gamer->player_posy- game->gamer->player_dy))
		{
			game->gamer->player_posx -= game->gamer->player_dx;
			game->gamer->player_posy -= game->gamer->player_dy;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'y' && direction == DOWN && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		if (!collision_with_wall(game, game->gamer->player_posx+game->gamer->player_dx , game->gamer->player_posy+ game->gamer->player_dy))
		{
			game->gamer->player_posx += game->gamer->player_dx;
			game->gamer->player_posy += game->gamer->player_dy;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == LEFT && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		if (!collision_with_wall(game, game->gamer->player_posx- game->gamer->player_dy, game->gamer->player_posy+ game->gamer->player_dx))
		{
			game->gamer->player_posx -=  game->gamer->player_dy;
			game->gamer->player_posy += game->gamer->player_dx;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == RIGHT && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		if (!collision_with_wall(game, game->gamer->player_posx+ game->gamer->player_dy , game->gamer->player_posy- game->gamer->player_dx))
		{
			game->gamer->player_posx +=  game->gamer->player_dy;
			game->gamer->player_posy -= game->gamer->player_dx;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == VIEW_RIGHT && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		game->gamer->player_angle += 0.1;
		if (game->gamer->player_angle > 2*PI)
		    game->gamer->player_angle -= 2* PI;
		game->gamer->player_dx = cos(game->gamer->player_angle)*game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle)*game->gamer->speed;
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == VIEW_LEFT && game->gamer->player_posx >0
		&& game->gamer->player_posx < game->mapp->map_x*IMG_H && game->gamer->player_posy >0
		&& game->gamer->player_posy < game->mapp->map_y*IMG_W)
	{
		game->gamer->player_angle -= 0.1;
		if (game->gamer->player_angle < 0)
		    game->gamer->player_angle += 2* PI;
		game->gamer->player_dx = cos(game->gamer->player_angle)*game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle)*game->gamer->speed;
		game->gamer->moved++;
		put_player(game);
	}
}
