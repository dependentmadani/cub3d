/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:07:58 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/10 21:21:51 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int empty_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '#')
            return (1);
        i++;
    }
    return (0);
}

void    count_the_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->newestmap[i])
    {
        j = 0;
        while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
        {
            j++;
            if (game->newestmap[i][j-1] != '#' && j > game->mapp->map_x)
                game->mapp->map_x = j;
        }
        i++;
    }
    i = 0;
    while (game->newestmap[i])
    {
        // if (empty_line(game->newestmap[i]))
            game->mapp->map_y +=1;
        i++;
    }
    game->mapp->map_size = game->mapp->map_x * game->mapp->map_y;
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
            mlx_pixel_put(game->mlx, game->win, i, j, 0xffffff);
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
            mlx_pixel_put(game->mlx, game->win, i, j, 0xffffff);
            i++;
        }
        j += IMG_W;
    }
    return (0);
}

void put_map_2d(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->newestmap[i])
    {
        j = 0;
        while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
        {
            if (game->newestmap[i][j] == 'N' || game->newestmap[i][j] == 'S'
                || game->newestmap[i][j] == 'E'|| game->newestmap[i][j] == 'W') 
            {
                game->gamer->player_posx = IMG_H * j + IMG_H/2;
                game->gamer->player_posy = IMG_W * i + IMG_W/2;
                put_player(game, 0x00ff00);
            }
            j++;
        }
        i++;
    }
}

void draw_2d_map(t_game * game)
{
    draw_horiz_line(game, 0, 0, 64*game->mapp->map_x, 64*game->mapp->map_y);
    draw_vert_line(game, 0, 0, 64*game->mapp->map_x, 64*game->mapp->map_y);
}

void create_window(t_game *game)
{
    count_the_map(game);
    game->mlx = mlx_init();
    if (!game->mlx)
	{
		perror("Error\nFailed to create connection of display and software\n");
		exit(EXIT_FAILURE);
	}
    game->win = mlx_new_window(game->mlx, game->mapp->win_width, game->mapp->win_height, "cub3d");
    // game->win = mlx_new_window(game->mlx, IMG_H * game->mapp->map_x +1, IMG_W *game->mapp->map_y +1, "cub3d");
    printf("the value of the last map is {%f}\n", game->mapp->map_y);
    put_map_2d(game);
    mlx_hook(game->win, 2, 1L<<0, keyword_move, game);
    mlx_hook(game->win, 17, 1L<<0, exit_function, game);
	mlx_key_hook(game->win, keyword_move, game);
    mlx_loop(game->mlx);
}
