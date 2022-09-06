/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:13:01 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/05 22:13:02 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int collision_with_wall(t_game *game, int pos_x, int pos_y)
{
    int estimation_posx;
    int estimation_posy;

    estimation_posx = (pos_x) / IMG_H;
    estimation_posy = (pos_y) / IMG_W;
    if (estimation_posx > game->mapp->map_x || estimation_posy > game->mapp->map_y)
        return (0);
    if (game->newestmap[estimation_posy][estimation_posx] == '1')
        return (1);
    return (0);
}

void    rays_until_wall_north(t_game* game)
{
    int i;
    int j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        j--;
    }
}

// void    rays_until_wall_west(t_game* game)
// {
//     int i;
//     int j;

//     i = game->gamer->player_posx;
//     j = game->gamer->player_posy;
//     while (!collision_with_wall(game, i, j))
//     {
//         mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
//         i -= 1;
//         j -= 1;
//     }
// }

void    spread_rays(t_game *game, int direction_player, char axis)
{
    (void)direction_player;
    (void)axis;
    // if (direction_player == UP && axis == 'y')
        rays_until_wall_north(game);
//     else if (direction_player == LEFT && axis == 'x')
//         rays_until_wall_west(game);
}
