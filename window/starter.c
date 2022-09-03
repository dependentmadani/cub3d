/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:47:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/08/28 11:47:07 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initializer(t_game *game)
{
    game->img_h = 64;
    game->img_w = 64;
    game->gamer->angle_view = 45;
    game->map_w = 0;
    game->map_h = 0;
}

void    creation_window(t_game *game)
{
    initializer(game);
}
