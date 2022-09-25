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

void update_putting_floor(t_game *game, int pos_x, int pos_y)
{
    int estimation_x;
    int estimation_y;
    int width;
    int height;
    void *wall;
    int diff_x;
    int diff_y;

    estimation_x = (pos_x) / IMG_H;
    estimation_y = (pos_y) / IMG_W;
    diff_x = (pos_x + 10) / IMG_H;
    diff_y = (pos_y + 10) / IMG_W;
    if (game->newestmap[estimation_y] && (game->newestmap[estimation_y][estimation_x] == '0'
        || game->newestmap[estimation_y][estimation_x] == 'N'  || game->newestmap[estimation_y][estimation_x] == 'S'
        || game->newestmap[estimation_y][estimation_x] == 'E' || game->newestmap[estimation_y][estimation_x] == 'W'))
    {
        wall = mlx_xpm_file_to_image(game->mlx, game->so_path, &width, &height);
        mlx_put_image_to_window(game->mlx, game->win, wall, estimation_x*IMG_W, estimation_y*IMG_H);
    }
    if (diff_x != estimation_x || diff_y != estimation_y)
    {
        if (game->newestmap[diff_y][diff_x] == '1')
        {
            wall = mlx_xpm_file_to_image(game->mlx, game->no_path, &width, &height);
            mlx_put_image_to_window(game->mlx, game->win, wall, diff_x*IMG_W, diff_y*IMG_H);
        }
        else
        {
            wall = mlx_xpm_file_to_image(game->mlx, game->so_path, &width, &height);
            mlx_put_image_to_window(game->mlx, game->win, wall, diff_x*IMG_W, diff_y*IMG_H); 
        }
    }
    diff_x = (pos_x - 10) / IMG_H;
    diff_y = (pos_y - 10) / IMG_W;
    if (diff_x != estimation_x || diff_y != estimation_y)
    {
        if (game->newestmap[diff_y][diff_x] == '1')
        {
            wall = mlx_xpm_file_to_image(game->mlx, game->no_path, &width, &height);
            mlx_put_image_to_window(game->mlx, game->win, wall, diff_x*IMG_W, diff_y*IMG_H);
        }
        else
        {
            wall = mlx_xpm_file_to_image(game->mlx, game->so_path, &width, &height);
            mlx_put_image_to_window(game->mlx, game->win, wall, diff_x*IMG_W, diff_y*IMG_H); 
        }
    }
}

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
        mlx_destroy_image(game->mlx, game->img->mlx_win);
        mlx_clear_window(game->mlx, game->win);
        // draw_2d_map(game);
    }
    (void)color;
    game->img->mlx_win = mlx_new_image(game->mlx, game->mapp->win_width, game->mapp->win_height);
    game->img->addr_win = mlx_get_data_addr(game->img->mlx_win, &game->img->bpp_win, &game->img->line_len_win, &game->img->endian);
    game->text->mlx_text = mlx_xpm_file_to_image(game->mlx, game->no_path, &game->text->img_w, &game->text->img_h);
	game->text->addr_text = mlx_get_data_addr(game->text->mlx_text, &game->text->bpp_text, &game->text->line_len_text, &game->text->endian);
    // put_wall(game);
    // put_floor(game);
    // circle(game, color);
    spread_rays(game);
}
