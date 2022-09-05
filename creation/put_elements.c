/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:15:21 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/04 22:15:22 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void    circle(t_game *game, int color)
{
    int i;
    int j;
    int r;
    int x;
    int y;
    int d;
    int a;

    r = 5;
    x = 10;
    y = 10;
    i = 0;
    while(i<IMG_H)
    {
        j = 0;
        while(j<IMG_W)
        {
            a=((i-x)*(i-x))+((j-y)*(j-y));
            d=sqrt(a);
            if(r>=d)
                mlx_pixel_put(game->mlx, game->win, game->gamer->player_posx + i,game->gamer->player_posy + j, color);
            j++;
        }
        i++;
    }
}

void    put_wall(t_game *game)
{
    (void)game;
}

void    put_floor(t_game *game)
{
    (void)game;
}

void    put_player(t_game *game, int color)
{
    if (game->gamer->moved)
    {
        mlx_clear_window(game->mlx, game->win);
        draw_2d_map(game);
    }
    circle(game, color);
}
