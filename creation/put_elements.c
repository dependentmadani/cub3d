/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:15:21 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 13:49:14 by mbadaoui         ###   ########.fr       */
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

void    check_direction_of_player(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->newestmap[i])
    {
        j = 0;
        while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
        {
            if (game->newestmap[i][j] == 'E')
            {
                game->gamer->player_angle = PI;
                i = -1;
                break ;
            }
            else if (game->newestmap[i][j] == 'N')
            {
                game->gamer->player_angle = P2;
                i = -1;
                break ;
            }
            else if (game->newestmap[i][j] == 'W')
            {
                game->gamer->player_angle = 0;
                i = -1;
                break ;
            }
            else if (game->newestmap[i][j] == 'S')
            {
                game->gamer->player_angle = P3;
                i = -1;
                break ;
            }
            j++;
        }
        if (i == -1)
            break ;
        i++;
    }
}

char    *image_path_finder(t_game *game, double deg_rad)
{
    if ((deg_rad <= PI/2 || deg_rad >= 3*PI/2) && game->mapp->side_vertical == 1)
        return (game->ea_path);
    else if (deg_rad <= PI && game->mapp->side_vertical == 0)
        return (game->no_path);
    else if ((deg_rad <= 3*PI/2 || deg_rad >= PI/2) && game->mapp->side_vertical == 1)
        return (game->we_path);
    else if (deg_rad > PI && game->mapp->side_vertical == 0)
        return (game->so_path);
    return (NULL);
}

void    information_imgs(t_game *game, char *filename)
{
    game->text->mlx_text = mlx_xpm_file_to_image(game->mlx, filename, &game->text->img_w, &game->text->img_h);
    if (!game->text->mlx_text)
    {
        perror("Error\n");
        printf("The image path \"%s\" is not correct\n", filename);
        exit(EXIT_FAILURE);
    }
	game->text->addr_text = mlx_get_data_addr(game->text->mlx_text, &game->text->bpp_text, &game->text->line_len_text, &game->text->endian);
    
}

void    rgb_converter(t_game *game)
{
    game->c_color = ((game->c_rgb[0] << 16) + (game->c_rgb[1] << 8) + (game->c_rgb[2]));
	game->f_color = ((game->f_rgb[0] << 16) + (game->f_rgb[1] << 8) + (game->f_rgb[2]));
}

void    put_player(t_game *game)
{
    if (game->gamer->moved)
    {
        mlx_destroy_image(game->mlx, game->img->mlx_win);
        mlx_destroy_image(game->mlx, game->minimap->new_image);
        mlx_clear_window(game->mlx, game->win);
    }
    game->img->mlx_win = mlx_new_image(game->mlx, game->mapp->win_width, game->mapp->win_height);
    game->img->addr_win = mlx_get_data_addr(game->img->mlx_win, &game->img->bpp_win, &game->img->line_len_win, &game->img->endian);
    game->minimap->new_image = mlx_new_image(game->mlx, game->minimap->win_width, game->minimap->win_height);
    game->minimap->addr_img = mlx_get_data_addr(game->minimap->new_image, &game->minimap->bpp_mini, &game->minimap->line_len_mini, &game->minimap->endian_mini);
    // spread_rays(game);
    dda_algorithm(game);
    create_minimap(game);
}
