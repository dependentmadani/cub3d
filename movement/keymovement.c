/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymovement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:25:19 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 18:02:53 by ael-asri         ###   ########.fr       */
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
	return (0);
}

int	mouse_move(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		movement_fun(game, 'x', VIEW_LEFT);
	if (button == 2)
		movement_fun(game, 'x', VIEW_RIGHT);
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
