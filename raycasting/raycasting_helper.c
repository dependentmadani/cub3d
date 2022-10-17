/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:07:23 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/06 10:07:23 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_initializer_rays_struct(t_game *game)
{
	game->rays->rx = 0;
	game->rays->ry = 0;
	game->rays->hx = game->gamer->player_posx;
	game->rays->hy = game->gamer->player_posy;
	game->rays->mp = 0;
	game->rays->mx = 0;
	game->rays->my = 0;
	game->rays->vx = game->gamer->player_posx;
	game->rays->vy = game->gamer->player_posy;
	game->rays->h_x0 = 0;
	game->rays->h_y0 = 0;
	game->rays->v_x0 = 0;
	game->rays->v_y0 = 0;
	game->rays->h_fov = 0;
	game->rays->v_fov = 0;
	game->rays->dish = 1000000;
	game->rays->disv = 1000000;
}

void	ft_assign_x0_y0_horizontal(t_game *game, double angle)
{
	game->rays->h_fov = 0;
	if (angle == 0 || angle == M_PI)
	{
		game->rays->rx = game->gamer->player_posx;
		game->rays->ry = game->gamer->player_posy;
		game->rays->h_fov = game->mapp->max_fov;
	}
	if (angle < M_PI)
	{
		game->rays->ry = (((int)game->gamer->player_posy / 64) * 64) - 0.0001;
		game->rays->rx = (game->gamer->player_posy - game->rays->ry) \
			* game->rays->atan + game->gamer->player_posx;
		game->rays->h_y0 = -64;
		game->rays->h_x0 = -game->rays->h_y0 * game->rays->atan;
	}
	if (angle > M_PI)
	{
		game->rays->ry = (((int)game->gamer->player_posy / 64) * 64) + 64;
		game->rays->rx = (game->gamer->player_posy - game->rays->ry) \
			* game->rays->atan + game->gamer->player_posx;
		game->rays->h_y0 = 64;
		game->rays->h_x0 = -game->rays->h_y0 * game->rays->atan;
	}
}

void	ft_check_horizontal_lines(t_game *game, double angle)
{
	game->rays->atan = -1 / tan(angle);
	ft_assign_x0_y0_horizontal(game, angle);
	while (game->rays->h_fov < game->mapp->max_fov)
	{
		game->rays->mx = (int)game->rays->rx >> 6;
		game->rays->my = (int)game->rays->ry >> 6;
		game->rays->mp = game->rays->my * game->mapp->map_x + game->rays->mx;
		if (game->rays->mp > 0
			&& game->rays->mp < game->mapp->map_x * game->mapp->map_y
			&& ft_collision_with_wall(game, game->rays->rx, game->rays->ry))
		{
			game->rays->hx = game->rays->rx;
			game->rays->hy = game->rays->ry;
			game->rays->dish = ft_dist(game->gamer->player_posx, \
				game->gamer->player_posy, game->rays->hx, game->rays->hy);
			game->rays->h_fov = game->mapp->max_fov;
		}
		else
		{
			game->rays->rx += game->rays->h_x0;
			game->rays->ry += game->rays->h_y0;
			game->rays->h_fov += 1;
		}
	}
}

void	ft_assign_x0_y0_vertical(t_game *game, double angle)
{
	game->rays->v_fov = 0;
	if (angle == 0 || angle == M_PI)
	{
		game->rays->rx = game->gamer->player_posx;
		game->rays->ry = game->gamer->player_posy;
		game->rays->v_fov = game->mapp->max_fov;
	}
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
	{
		game->rays->rx = (((int)game->gamer->player_posx / 64) * 64) + 64;
		game->rays->ry = (game->gamer->player_posx - game->rays->rx) \
			* game->rays->ntan + game->gamer->player_posy;
		game->rays->v_x0 = 64;
		game->rays->v_y0 = -game->rays->v_x0 * game->rays->ntan;
	}
	if (angle < M_PI_2 || angle > 3 * M_PI_2)
	{
		game->rays->rx = (((int)game->gamer->player_posx / 64) * 64) - 0.0001;
		game->rays->ry = (game->gamer->player_posx - game->rays->rx) \
			* game->rays->ntan + game->gamer->player_posy;
		game->rays->v_x0 = -64;
		game->rays->v_y0 = -game->rays->v_x0 * game->rays->ntan;
	}
}

void	ft_check_vertical_lines(t_game *game, double angle)
{
	game->rays->ntan = -tan(angle);
	ft_assign_x0_y0_vertical(game, angle);
	while (game->rays->v_fov < game->mapp->max_fov)
	{
		game->rays->mx = (int)game->rays->rx >> 6;
		game->rays->my = (int)game->rays->ry >> 6;
		game->rays->mp = game->rays->my * game->mapp->map_x + game->rays->mx;
		if (game->rays->mp > 0
			&& game->rays->mp < game->mapp->map_x * game->mapp->map_y
			&& ft_collision_with_wall(game, game->rays->rx, game->rays->ry))
		{
			game->rays->vx = game->rays->rx;
			game->rays->vy = game->rays->ry;
			game->rays->disv = ft_dist(game->gamer->player_posx, \
				game->gamer->player_posy, game->rays->vx, game->rays->vy);
			game->rays->v_fov = game->mapp->max_fov;
		}
		else
		{
			game->rays->rx += game->rays->v_x0;
			game->rays->ry += game->rays->v_y0;
			game->rays->v_fov += 1;
		}
	}
}
