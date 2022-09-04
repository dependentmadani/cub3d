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

void    count_the_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (!i && game->map[i][j] && game->map[i][j] != '\n')
        {
            j++;
            game->mapp->map_x = j;
        }
        i++;
    }
    game->mapp->map_y = i;
}

int draw_vert_line(t_game *game, int begin_x, int begin_y, int end_x, int end_y)
{
    int i;
    int j;

    i = begin_x;
    while (i <= end_x)
    {
        j = begin_y;
        while (j < end_y)
        {
            mlx_pixel_put(game->mlx, game->win, i, j, 0x0000FF);
            j++;
        }
        i += IMG_H;
    }
    return (0);
}

int draw_horiz_line(t_game *game, int begin_x, int begin_y, int end_x, int end_y)
{
    int i;
    int j;

    j = begin_y;
    while (j <= end_y)
    {
        i = begin_x;
        while (i < end_x)
        {
            mlx_pixel_put(game->mlx, game->win, i, j, 0x0000FF);
            i++;
        }
        j += IMG_W;
    }
    return (0);
}

void    put_wall(t_game *game)
{
    (void)game;
}

void    put_floor(t_game *game)
{
    (void)game;

}

void put_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] && game->map[i][j] != '\n')
        {
            if (game->map[i][j] == '0')
                put_floor(game);
            else if (game->map[i][j] == '1')
                put_wall(game);
            j++;
        }
        i++;
    }
    draw_horiz_line(game, 0, 0, 64*game->mapp->map_x, 64*game->mapp->map_y);
    draw_vert_line(game, 0, 0, 64*game->mapp->map_x, 64*game->mapp->map_y);
}

void create_window(t_game *game)
{
    count_the_map(game);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, IMG_H * game->mapp->map_x, IMG_W *game->mapp->map_y, "cub3d");
    put_map(game);
    mlx_loop(game->mlx);
}
