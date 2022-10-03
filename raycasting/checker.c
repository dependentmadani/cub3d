/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:56:49 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/30 13:48:45 by mbadaoui         ###   ########.fr       */
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
	if (estimation_posx < 0 || estimation_posy < 0)
		return (0);
	if (game->newestmap[estimation_posy]
		&& game->newestmap[estimation_posy][estimation_posx] == '1')
		return (1);
	return (0);
}

void    img_pix_put(t_game *game, int x, int y, int color)
{
	char    *pixel;

	pixel = game->img->addr_win + (y * game->img->line_len_win + x * (game->img->bpp_win / 8));
	*(int *)pixel = color;
}

void	get_texture_info(t_game *game, int x, int y, double end_y)
{
	int *color;
	int	x_start;
	int	y_start;
	int	y_value;

	y_start = (int)((game->mapp->win_height/2) - (end_y/2));
	x_start = (game->img->offset) %64;
	y_value = (y - y_start)*64/end_y;
	color = (int*)(game->text->addr_text + (int)(y_value* game->text->line_len_text + ((x_start)*game->text->bpp_text/8)));
	img_pix_put(game, x, y, *color);
}

double dist(double ax, double ay, double bx, double by, double ang)
{
	(void)ang;
	return (sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay)));
}

int draw(t_game *game, double end_x, double end_y)
{
	int		x;
	double	y;

	x = end_x;
	y = 0;
	while (y < game->mapp->win_height)
	{
		if (y < (int)((game->mapp->win_height/2) - (end_y/2)))
			img_pix_put(game, x, y, game->c_color);
		else if (y >= (int)((game->mapp->win_height/2) - (end_y/2)) && y < (int)((game->mapp->win_height/2) + (end_y/2)))
			get_texture_info(game, x, y, end_y);
		else if (y >= (int)((game->mapp->win_height/2) + (end_y/2)))
			img_pix_put(game, x, y, game->f_color);
		y++;
	}
	return (0);
}

void    spread_rays(t_game *game)
{
	int r, fov, mp, mx, my;
	double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan, disT;

	ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
	for (r=0; r< game->mapp->win_width; r++)
	{
		///// check the horizontal lines
		fov = 0;
		disH=1000000, hx=game->gamer->player_posx, hy=game->gamer->player_posy;
		aTan = -1/tan(ra);
		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=14;}
		if (ra < PI) {ry =(((int)game->gamer->player_posy/64)*64)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
		if (ra > PI) {ry =(((int)game->gamer->player_posy/64)*64)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
		while (fov < 20)
		{
			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy, ra); fov=20;}
			else {rx+=xo; ry+=yo;fov+=1;}
		}
		///// check the vertical lines
		fov = 0;
		double disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
		nTan = -tan(ra);
		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=13;}
		if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx/64)*64)+64; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=64; yo=-xo*nTan;}
		if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx/64)*64)-0.0001; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=-64; yo=-xo*nTan;} // problem need to be fixed here
		while (fov < 20)
		{
			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=20;}
			else {rx+=xo; ry+=yo;fov+=1;}
		}
		if (disV < disH) {rx = vx; ry =vy; disT = disV; game->mapp->side_vertical = 1;}
		if (disH < disV) {rx = hx; ry =hy; disT = disH; game->mapp->side_vertical = 0;}
		double ca = game->gamer->player_angle - ra; if (ca < 0) {ca += 2*PI;} if (ca > 2*PI) {ca -= 2*PI;} disT = disT*cos(ca);
		double lineH = (64*415)/(disT); if (lineH > game->mapp->win_height) {lineH = game->mapp->win_height;}
		if (game->mapp->side_vertical == 0)
			game->img->offset = (int)rx;
		else if (game->mapp->side_vertical == 1)
			game->img->offset = (int)ry;
		char *path = image_path_finder(game, ra);
		if (r == 0 || path != game->text->path_img)
			information_imgs(game, path);
		game->text->path_img = path;

		draw(game, r, lineH);

		ra += DR/10;
		if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
	}
	game->mapp->position_map_x = game->gamer->player_posx / 64;
	game->mapp->position_map_y = game->gamer->player_posy / 64;
	mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_win, 0, 0);
}
