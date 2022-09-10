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

int collision_with_wall(t_game *game, double pos_x, double pos_y)
{
    int estimation_posx;
    int estimation_posy;

    estimation_posx = (pos_x) / IMG_H;
    estimation_posy = (pos_y) / IMG_W;
    if (estimation_posx >= game->mapp->map_x || estimation_posy >= game->mapp->map_y)
        return (0);
    if (game->newestmap[estimation_posy] && game->newestmap[estimation_posy][estimation_posx] == '1')
        return (1);
    return (0);
}

void    rays_until_wall_north_or_south(t_game* game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        if ((int)game->gamer->player_angle == 1)
            j--;
        else
            j++;
    }
    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    update_putting_floor(game, i, j);
    // while (!collision_with_wall(game, i, j))
    // {
    //     mlx_pixel_put(game->mlx, game->win, i*cos(-PI / 6), j*sin(-PI / 6), 0xff0000);
    //     printf("the value of i {%f}\n", j*sin(-PI / 6));
    //     if ((int)game->gamer->player_angle == 1)
    //         j--;
    //     else
    //         j++;
    // }
}

void    rays_until_west_or_east(t_game* game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        if (game->gamer->player_angle == 0)
            i--;
        else
            i++;
    }
}

void    rays_until_west_north(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        i -= 0.1 + game->gamer->player_dx;
        j -= 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_north_east(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        i += 0.1 + game->gamer->player_dx;
        j -= 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_east_south(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        i += 0.1 + game->gamer->player_dx;
        j += 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_south_west(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        i -= 0.1 + game->gamer->player_dx;
        j += 0.1 + game->gamer->player_dy;
    }
}

void    complete_rays_fov(t_game *game, double player_x, double player_y)
{
    double i;
    double j;
    double vision;

    i = player_x;
    j = player_y;
    vision = -PI / 6;
    while (vision < (PI /6))
    {
        i = player_x;
        j = player_y;
        while (!collision_with_wall(game, i, j))
        {
            mlx_pixel_put(game->mlx, game->win, i*cos(vision), j*sin(vision), 0xff0000);
            if ((int)game->gamer->player_angle == 1)
                j--;
            else
                j++;
            if (vision < 0)
                i--;
            else
                i++;
        }
        vision += game->gamer->fov / IMG_W;
    }
}

void    spread_rays(t_game *game)
{
    if (game->gamer->player_angle == PI/2 || game->gamer->player_angle == (3*PI/2))
        rays_until_wall_north_or_south(game);
    else if (game->gamer->player_angle == 0 || game->gamer->player_angle == 2*PI)
        rays_until_west_or_east(game);
    else if (game->gamer->player_angle > 0 || game->gamer->player_angle < (PI / 2))
        rays_until_west_north(game);
    else if (game->gamer->player_angle > (PI/2) || game->gamer->player_angle < (PI))
        rays_until_north_east(game);
    else if (game->gamer->player_angle > PI || game->gamer->player_angle < (3*PI/2))
        rays_until_east_south(game);
    else if (game->gamer->player_angle > (3*PI/2) || game->gamer->player_angle < (2*PI))
        rays_until_south_west(game);
}
