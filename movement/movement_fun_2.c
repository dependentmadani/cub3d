/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_fun_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:26:30 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/09 12:26:31 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_movement_mouse_fun(t_game *game, char axis, int direction)
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
		ft_put_player(game);
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
		ft_put_player(game);
	}
}

void	ft_movement_x_left_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'x' && direction == LEFT)
	{
		game->mapp->new_pos_x = game->gamer->player_posx - \
			game->gamer->player_dy;
		game->mapp->new_pos_y = game->gamer->player_posy + \
			game->gamer->player_dx;
		if (!ft_collision_with_wall(game, game->mapp->new_pos_x, \
			game->mapp->new_pos_y)
			&& !ft_collision_special_case(game, game->mapp->new_pos_x, \
			game->mapp->new_pos_y, 1))
		{
			game->gamer->player_posx -= game->gamer->player_dy;
			game->gamer->player_posy += game->gamer->player_dx;
		}
		game->gamer->moved++;
		ft_put_player(game);
	}
}

void	ft_movement_x_right_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'x' && direction == RIGHT)
	{
		game->mapp->new_pos_x = game->gamer->player_posx + \
			game->gamer->player_dy;
		game->mapp->new_pos_y = game->gamer->player_posy - \
			game->gamer->player_dx;
		if (!ft_collision_with_wall(game, game->mapp->new_pos_x, \
			game->mapp->new_pos_y)
			&& !ft_collision_special_case(game, game->mapp->new_pos_x, \
				game->mapp->new_pos_y, 2))
		{
			game->gamer->player_posx += game->gamer->player_dy;
			game->gamer->player_posy -= game->gamer->player_dx;
		}
		game->gamer->moved++;
		ft_put_player(game);
	}
}
