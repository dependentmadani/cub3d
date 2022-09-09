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
    x = 0;
    y = 0;
    i = -r;
    while(i<IMG_H)
    {
        j = -r;
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
    int i;
    int j;
    int width;
    int height;
    void *wall;

    i = 0;
    while (game->newestmap[i])
    {
        j = 0;
        while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
        {
            if (game->newestmap[i][j] == '1')
            {
                wall = mlx_xpm_file_to_image(game->mlx, game->no_path, &width, &height);
                mlx_put_image_to_window(game->mlx, game->win, wall, j*IMG_W, i*IMG_H);
            }
            j++;
        }
        i++;
    }
}

void    put_floor(t_game *game)
{
    int i;
    int j;
    int width;
    int height;
    void *wall;

    i = 0;
    while (game->newestmap[i])
    {
        j = 0;
        while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
        {
            if (game->newestmap[i][j] == '0' || game->newestmap[i][j] == 'N' 
                || game->newestmap[i][j] == 'S' || game->newestmap[i][j] == 'E'
                || game->newestmap[i][j] == 'W')
            {
                wall = mlx_xpm_file_to_image(game->mlx, game->so_path, &width, &height);
                mlx_put_image_to_window(game->mlx, game->win, wall, j*IMG_W, i*IMG_H);
            }
            j++;
        }
        i++;
    }
}

void    put_player(t_game *game, int color)
{
    if (game->gamer->moved)
    {
        mlx_clear_window(game->mlx, game->win);
        // draw_2d_map(game);
    }
    put_wall(game);
    put_floor(game);
    circle(game, color);
    spread_rays(game);
}
