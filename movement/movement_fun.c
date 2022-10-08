/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:28:25 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/05 14:40:18 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement_mouse_fun(t_game *game, char axis, int direction)
{
	if (axis == 'x' && direction == VIEW_RIGHT)
	{
		game->gamer->player_angle += 0.1;
		if (game->gamer->player_angle > 2 * M_PI)
			game->gamer->player_angle -= 2 * M_PI;
		game->gamer->player_dx = cos(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == VIEW_LEFT)
	{
		game->gamer->player_angle -= 0.1;
		if (game->gamer->player_angle < 0)
			game->gamer->player_angle += 2 * M_PI;
		game->gamer->player_dx = cos(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->moved++;
		put_player(game);
	}
}

void	movement_x_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'x' && direction == LEFT)
	{
		if (!collision_with_wall(game, game->gamer->player_posx - \
			game->gamer->player_dy, game->gamer->player_posy + \
			game->gamer->player_dx))
		{
			game->gamer->player_posx -= game->gamer->player_dy;
			game->gamer->player_posy += game->gamer->player_dx;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'x' && direction == RIGHT)
	{
		if (!collision_with_wall(game, game->gamer->player_posx + \
			game->gamer->player_dy, game->gamer->player_posy - \
			game->gamer->player_dx))
		{
			game->gamer->player_posx += game->gamer->player_dy;
			game->gamer->player_posy -= game->gamer->player_dx;
		}
		game->gamer->moved++;
		put_player(game);
	}
}

void	movement_y_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'y' && direction == UP)
	{
		if (!collision_with_wall(game, game->gamer->player_posx - \
			game->gamer->player_dx, game->gamer->player_posy - \
			game->gamer->player_dy))
		{
			game->gamer->player_posx -= game->gamer->player_dx;
			game->gamer->player_posy -= game->gamer->player_dy;
		}
		game->gamer->moved++;
		put_player(game);
	}
	else if (axis == 'y' && direction == DOWN)
	{
		if (!collision_with_wall(game, game->gamer->player_posx + \
			game->gamer->player_dx, game->gamer->player_posy + \
			game->gamer->player_dy))
		{
			game->gamer->player_posx += game->gamer->player_dx;
			game->gamer->player_posy += game->gamer->player_dy;
		}
		game->gamer->moved++;
		put_player(game);
	}
}

void	movement_fun(t_game *game, char axis, int direction)
{
	if (game->gamer->player_posx < 0
		&& game->gamer->player_posx > game->mapp->map_x * IMG_H
		&& game->gamer->player_posy < 0
		&& game->gamer->player_posy > game->mapp->map_y * IMG_W)
		return ;
	movement_x_axis_fun(game, axis, direction);
	movement_y_axis_fun(game, axis, direction);
	movement_mouse_fun(game, axis, direction);
}
