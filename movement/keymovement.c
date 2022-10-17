/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymovement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:25:19 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/17 07:01:43 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_keyword_move(int keyword, t_game *game)
{
	if (keyword == ESC)
		ft_exit_function(game);
	if (keyword == W)
		ft_movement_fun(game, 'y', UP);
	if (keyword == S)
		ft_movement_fun(game, 'y', DOWN);
	if (keyword == D)
		ft_movement_fun(game, 'x', RIGHT);
	if (keyword == A)
		ft_movement_fun(game, 'x', LEFT);
	if (keyword == LEFT_ARROW)
		ft_movement_fun(game, 'x', VIEW_LEFT);
	if (keyword == RIGHT_ARROW)
		ft_movement_fun(game, 'x', VIEW_RIGHT);
	return (0);
}

int	ft_mouse_move(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		ft_movement_fun(game, 'x', VIEW_LEFT);
	if (button == 2)
		ft_movement_fun(game, 'x', VIEW_RIGHT);
	return (0);
}

int	ft_exit_function(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->mlx_win);
	mlx_destroy_image(game->mlx, game->minimap->new_image);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	printf("Enough of gaming for this moment!\n");
	exit(EXIT_SUCCESS);
}

void	ft_exit_error(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->mlx_win);
	mlx_destroy_image(game->mlx, game->minimap->new_image);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_FAILURE);
}
