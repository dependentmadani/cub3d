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

void create_window(t_game *game)
{
    void *mlx;
    void *mlx_win;
    (void)game;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 3200, 2000, "cub3d");
    mlx_loop(mlx);
}
