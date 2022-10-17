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

void	ft_movement_y_up_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'y' && direction == UP)
	{
		game->mapp->new_pos_x = game->gamer->player_posx - \
			game->gamer->player_dx;
		game->mapp->new_pos_y = game->gamer->player_posy - \
			game->gamer->player_dy;
		if (!ft_collision_with_wall(game, game->mapp->new_pos_x, \
			game->mapp->new_pos_y)
			&& !ft_collision_special_case(game, game->mapp->new_pos_x, \
				game->mapp->new_pos_y, 3))
		{
			game->gamer->player_posx -= game->gamer->player_dx;
			game->gamer->player_posy -= game->gamer->player_dy;
		}
		game->gamer->moved++;
		ft_put_player(game);
	}
}

void	ft_movement_y_down_axis_fun(t_game *game, char axis, int direction)
{
	if (axis == 'y' && direction == DOWN)
	{
		game->mapp->new_pos_x = game->gamer->player_posx + \
			game->gamer->player_dx;
		game->mapp->new_pos_y = game->gamer->player_posy + \
			game->gamer->player_dy;
		if (!ft_collision_with_wall(game, game->mapp->new_pos_x, \
			game->mapp->new_pos_y)
			&& !ft_collision_special_case(game, game->mapp->new_pos_x, \
				game->mapp->new_pos_y, 4))
		{
			game->gamer->player_posx += game->gamer->player_dx;
			game->gamer->player_posy += game->gamer->player_dy;
		}
		game->gamer->moved++;
		ft_put_player(game);
	}
}

void	ft_movement_fun(t_game *game, char axis, int direction)
{
	if (game->gamer->player_posx < 0
		&& game->gamer->player_posx > game->mapp->map_x * IMG_H
		&& game->gamer->player_posy < 0
		&& game->gamer->player_posy > game->mapp->map_y * IMG_W)
		return ;
	ft_movement_x_left_axis_fun(game, axis, direction);
	ft_movement_x_right_axis_fun(game, axis, direction);
	ft_movement_y_up_axis_fun(game, axis, direction);
	ft_movement_y_down_axis_fun(game, axis, direction);
	ft_movement_mouse_fun(game, axis, direction);
}
