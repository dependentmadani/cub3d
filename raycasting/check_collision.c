/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:10:51 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/09 12:10:53 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_collision_special_case_1(t_game *game, int pos_x, int pos_y, int direct)
{
	if (game->newestmap[pos_y][pos_x + 1] == '1'
		&& game->newestmap[pos_y + 1][pos_x] == '1')
	{
		if ((game->gamer->player_angle < M_PI_2 && direct == 3)
			|| ((game->gamer->player_angle > M_PI_2
					&& game->gamer->player_angle < M_PI) && direct == 1)
			|| ((game->gamer->player_angle > M_PI
					&& game->gamer->player_angle < 3 * M_PI_2)
				&& direct == 4)
			|| (game->gamer->player_angle > 3 * M_PI_2 && direct == 2))
			return (1);
	}
	if (game->newestmap[pos_y + 1][pos_x] == '1'
		&& game->newestmap[pos_y][pos_x - 1] == '1')
	{
		if ((game->gamer->player_angle < M_PI_2 && direct == 2)
			|| ((game->gamer->player_angle > M_PI_2
					&& game->gamer->player_angle < M_PI) && direct == 3)
			|| ((game->gamer->player_angle > M_PI
					&& game->gamer->player_angle < 3 * M_PI_2)
				&& direct == 1)
			|| (game->gamer->player_angle > 3 * M_PI_2 && direct == 4))
			return (1);
	}
	return (0);
}

int	ft_collision_special_case_2(t_game *game, int pos_x, int pos_y, int direct)
{
	if (game->newestmap[pos_y - 1][pos_x] == '1'
	&& game->newestmap[pos_y][pos_x - 1] == '1')
	{
		if ((game->gamer->player_angle < M_PI_2 && direct == 4)
			|| ((game->gamer->player_angle > M_PI_2
					&& game->gamer->player_angle < M_PI) && direct == 2)
			|| ((game->gamer->player_angle > M_PI
					&& game->gamer->player_angle < 3 * M_PI_2)
				&& direct == 3)
			|| (game->gamer->player_angle > 3 * M_PI_2 && direct == 1))
			return (1);
	}
	if (game->newestmap[pos_y - 1][pos_x] == '1'
		&& game->newestmap[pos_y][pos_x + 1] == '1')
	{
		if ((game->gamer->player_angle < M_PI_2 && direct == 1)
			|| ((game->gamer->player_angle > M_PI_2
					&& game->gamer->player_angle < M_PI) && direct == 4)
			|| ((game->gamer->player_angle > M_PI
					&& game->gamer->player_angle < 3 * M_PI_2)
				&& direct == 2)
			|| (game->gamer->player_angle > 3 * M_PI_2 && direct == 3))
			return (1);
	}
	return (0);
}

int	ft_collision_special_case(t_game *game, double posx, double posy, int dir)
{
	int	pos_x;
	int	pos_y;

	pos_x = posx / IMG_H;
	pos_y = posy / IMG_W;
	if (((int)game->mapp->new_pos_x / 64) == \
		((int)game->gamer->player_posx / 64)
		&& ((int)game->mapp->new_pos_y / 64) == \
			((int)game->gamer->player_posy / 64))
		return (0);
	if (ft_collision_special_case_1(game, pos_x, pos_y, dir))
		return (1);
	else if (ft_collision_special_case_2(game, pos_x, pos_y, dir))
		return (1);
	return (0);
}
