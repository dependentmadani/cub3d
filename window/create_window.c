/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:07:58 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/02 18:08:01 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void put_map(t_game *game)
{
    (void)game;
}

void create_window(t_game *game)
{
    (void)game;

    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 3200, 2000, "cub3d");
    put_map(game);
    mlx_loop(game->mlx);
}
