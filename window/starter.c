/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:47:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/10 11:13:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initialize_dx_dy(t_game *game)
{
    if (game->gamer->player_angle == 0 || game->gamer->player_angle == PI)
    {
        game->gamer->player_dx = cos(game->gamer->player_angle)*game->gamer->speed;
        game->gamer->player_dy = sin(game->gamer->player_angle)*game->gamer->speed;
    }
    else if (game->gamer->player_angle == P2 || game->gamer->player_angle == P3)
    {
        game->gamer->player_dx = cos(game->gamer->player_angle)*game->gamer->speed;
        game->gamer->player_dy = sin(game->gamer->player_angle)*game->gamer->speed;
    }
    printf("the value of player_dx {%f} and player_dy {%f}\n", game->gamer->player_dx, game->gamer->player_dy);
}

void    initializer(t_game *game)
{
    game->img = ft_calloc(1, sizeof(t_win));
    game->text = ft_calloc(1, sizeof(t_texture));
    game->minimap = ft_calloc(1, sizeof(t_minimap));
    game->minimap->map = game->mapp;
    game->mapp->win_width = 640;
    game->mapp->win_height = 480;
    game->minimap->win_width = game->mapp->win_width / 4;
    game->minimap->win_height = game->mapp->win_height / 4;
    game->text->path_img = NULL;
    game->gamer->fov = 60.0;
    game->gamer->speed = 5; ///8 pixels per second
    game->gamer->player_posx = 0; /// depends on his position in the map
    game->gamer->player_posy = 0; /// depends on his position in the map
    game->gamer->moved = 0;
    game->mapp->map_x = 0;
    game->mapp->map_y = 0;
    game->mapp->theta = 0;
    game->mapp->len_wall = 0;
    game->mapp->intersection_wall = 0;
    game->mapp->side_vertical = 0;
    game->img->offset = 0;
    game->img->scale_resize = 0;
    game->mapp->map_size = 0; /// To update: calculate number of rows * number of columns
}

void    creation_window(t_game *game)
{
    initializer(game);
    create_window(game);
}
