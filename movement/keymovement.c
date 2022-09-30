/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymovement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:25:19 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 15:24:21 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keyword_move(int keyword, t_game *game)
{
	if (keyword == ESC)
		exit_function(game);
	if (keyword == W)
		movement_fun(game, 'y', UP);
	if (keyword == S)
		movement_fun(game, 'y', DOWN);
	if (keyword == D)
		movement_fun(game, 'x', RIGHT);
	if (keyword == A)
		movement_fun(game, 'x', LEFT);
	if (keyword == LEFT_ARROW)
		movement_fun(game, 'x', VIEW_LEFT);
	if (keyword == RIGHT_ARROW)
		movement_fun(game, 'x', VIEW_RIGHT);
	// if (game->map[game->gamer->player_posy][game->gamer->player_posx] == 'E')
	// 	win_funct(game);
	return (0);
}

int	exit_function(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Enough of gaming for this moment!\n");
	exit(EXIT_SUCCESS);
}

int winning_funtion(void)
{
	printf("I was an intesive game, and you did great!\n");
	exit(EXIT_SUCCESS);
}
