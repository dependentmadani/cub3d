/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:37:23 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/06 06:37:24 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	check_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	distance_player_wall(t_game *game)
{
	double	dis_t;

	if (game->rays->disv < game->rays->dish)
	{
		game->rays->rx = game->rays->vx;
		game->rays->ry = game->rays->vy;
		dis_t = game->rays->disv;
		game->mapp->side_vertical = 1;
	}
	if (game->rays->dish < game->rays->disv)
	{
		game->rays->rx = game->rays->hx;
		game->rays->ry = game->rays->hy;
		dis_t = game->rays->dish;
		game->mapp->side_vertical = 0;
	}
	return (dis_t);
}

void	get_wall_length(t_game *game, double disT, double angle)
{
	double	ca;
	double	ratio;

	ratio = (game->mapp->win_width / 2) / tan(0.523599);
	ca = game->gamer->player_angle - angle;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	disT = disT * cos(ca);
	game->mapp->length_wall = (64 * ratio) / disT;
	if (game->mapp->side_vertical == 0)
		game->img->offset = (int)game->rays->rx;
	else if (game->mapp->side_vertical == 1)
		game->img->offset = (int)game->rays->ry;
	game->rays->disv = 1000000;
	game->rays->dish = 1000000;
}

void	create_image_in_window(t_game *game)
{
	game->mapp->position_map_x = game->gamer->player_posx / 64;
	game->mapp->position_map_y = game->gamer->player_posy / 64;
	mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_win, 0, 0);
}

void	dda_algorithm(t_game *game)
{
	int		r;
	double	ra;
	double	dis_t;
	char	*path;

	initializer_rays_struct(game);
	ra = game->gamer->player_angle - DR * 30;
	ra = check_angle(ra);
	r = 0;
	while (r < game->mapp->win_width)
	{
		check_horizontal_lines(game, ra);
		check_vertical_lines(game, ra);
		dis_t = distance_player_wall(game);
		get_wall_length(game, dis_t, ra);
		path = image_path_finder(game, ra);
		if (r == 0 || path != game->text->path_img)
			information_imgs(game, path);
		game->text->path_img = path;
		draw(game, r, game->mapp->length_wall);
		ra += DR / (game->mapp->win_width/60);
		ra = check_angle(ra);
		r++;
	}
	create_image_in_window(game);
}
