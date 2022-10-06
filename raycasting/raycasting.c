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

// void    spread_rays(t_game *game)
// {
// 	int r, fov, mp, mx, my;
// 	double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan, disT;

// 	ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
// 	for (r=0; r< game->mapp->win_width; r++)
// 	{
// 		///// check the horizontal lines
// 		fov = 0;
// 		disH=1000000; hx=game->gamer->player_posx, hy=game->gamer->player_posy;
// 		aTan = -1/tan(ra);
// 		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=20;}
// 		if (ra < PI) {ry =(((int)game->gamer->player_posy/64)*64)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
// 		if (ra > PI) {ry =(((int)game->gamer->player_posy/64)*64)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
// 		while (fov < 20)
// 		{
// 			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
// 			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy); fov=20;}
// 			else {rx+=xo; ry+=yo;fov+=1;}
// 		}
// 		///// check the vertical lines
// 		fov = 0;
// 		double disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
// 		nTan = -tan(ra);
// 		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=20;}
// 		if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx/64)*64)+64; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=64; yo=-xo*nTan;}
// 		if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx/64)*64)-0.0001; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=-64; yo=-xo*nTan;}
// 		while (fov < 20)
// 		{
// 			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
// 			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy); fov=20;}
// 			else {rx+=xo; ry+=yo;fov+=1;}
// 		}
// 		if (disV < disH) {rx = vx; ry =vy; disT = disV; game->mapp->side_vertical = 1;}
// 		if (disH < disV) {rx = hx; ry =hy; disT = disH; game->mapp->side_vertical = 0;}
// 		double ca = game->gamer->player_angle - ra; if (ca < 0) {ca += 2*PI;} if (ca > 2*PI) {ca -= 2*PI;} disT = disT*cos(ca);
// 		double lineH = (64*415)/(disT);
// 		if (game->mapp->side_vertical == 0)
// 			game->img->offset = (int)rx;
// 		else if (game->mapp->side_vertical == 1)
// 			game->img->offset = (int)ry;
// 		char *path = image_path_finder(game, ra);
// 		if (r == 0 || path != game->text->path_img)
// 			information_imgs(game, path);
// 		game->text->path_img = path;
// 		draw(game, r, lineH);
// 		ra += DR/10;
// 		if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
// 	}
// 	game->mapp->position_map_x = game->gamer->player_posx / 64;
// 	game->mapp->position_map_y = game->gamer->player_posy / 64;
// 	mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_win, 0, 0);
// }

void	initializer_rays_struct(t_game *game)
{
	game->rays->rx = 0;
	game->rays->ry = 0;
	game->rays->hx = game->gamer->player_posx;
	game->rays->hy = game->gamer->player_posy;
	game->rays->mp = 0;
	game->rays->mx = 0;
	game->rays->my = 0;
	game->rays->vx = game->gamer->player_posx;
	game->rays->vy = game->gamer->player_posy;
	game->rays->h_x0 = 0;
	game->rays->h_y0 = 0;
	game->rays->v_x0 = 0;
	game->rays->v_y0 = 0;
	game->rays->h_fov = 0;
	game->rays->v_fov = 0;
	game->rays->disH = 1000000;
	game->rays->disV = 1000000;
}

double	check_angle(double angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2* PI)
		angle -=2 * PI;
	return (angle);
}

void	assign_x0_y0_horizontal(t_game *game, double angle)
{
	game->rays->h_fov = 0;
	if (angle == 0 || angle == PI)
	{
		game->rays->rx = game->gamer->player_posx;
		game->rays->ry = game->gamer->player_posy;
		game->rays->h_fov = 20;
	}
	if (angle < PI)
	{
		game->rays->ry = (((int)game->gamer->player_posy/64)*64)-0.0001;
		game->rays->rx = (game->gamer->player_posy - game->rays->ry)*game->rays->aTan + game->gamer->player_posx;
		game->rays->h_y0 = -64;
		game->rays->h_x0 = -game->rays->h_y0*game->rays->aTan;
	}
	if (angle > PI)
	{
		game->rays->ry = (((int)game->gamer->player_posy/64)*64)+64;
		game->rays->rx = (game->gamer->player_posy - game->rays->ry)*game->rays->aTan + game->gamer->player_posx;
		game->rays->h_y0 = 64;
		game->rays->h_x0 = -game->rays->h_y0*game->rays->aTan;
	}
}

void	check_horizontal_lines(t_game *game, double angle)
{
	game->rays->aTan = -1/tan(angle);
	assign_x0_y0_horizontal(game, angle);
	while (game->rays->h_fov < 20)
	{
		game->rays->mx = (int)game->rays->rx>>6;
		game->rays->my = (int)game->rays->ry>>6;
		game->rays->mp = game->rays->my*game->mapp->map_x + game->rays->mx;
		if (game->rays->mp > 0 && game->rays->mp < game->mapp->map_x*game->mapp->map_y 
			&& collision_with_wall(game, game->rays->rx, game->rays->ry))
		{
			game->rays->hx=game->rays->rx;
			game->rays->hy=game->rays->ry;
			game->rays->disH=dist(game->gamer->player_posx, game->gamer->player_posy, game->rays->hx, game->rays->hy);
			game->rays->h_fov=20;
		}
		else
		{
			game->rays->rx+= game->rays->h_x0;
			game->rays->ry+= game->rays->h_y0;
			game->rays->h_fov+=1;
		}
	}
}

void	assign_x0_y0_vertical(t_game *game, double angle)
{
	game->rays->v_fov = 0;
	if (angle == 0 || angle == PI)
	{
		game->rays->rx = game->gamer->player_posx;
		game->rays->ry = game->gamer->player_posy;
		game->rays->v_fov = 20;
	}
	if (angle > P2 && angle < P3)
	{
		game->rays->rx = (((int)game->gamer->player_posx/64)*64)+64;
		game->rays->ry = (game->gamer->player_posx - game->rays->rx)*game->rays->nTan + game->gamer->player_posy;
		game->rays->v_x0 = 64;
		game->rays->v_y0 = -game->rays->v_x0*game->rays->nTan;
	}
	if (angle < P2 || angle > P3)
	{
		game->rays->rx = (((int)game->gamer->player_posx/64)*64)-0.0001;
		game->rays->ry = (game->gamer->player_posx - game->rays->rx)*game->rays->nTan + game->gamer->player_posy;
		game->rays->v_x0 = -64;
		game->rays->v_y0 = -game->rays->v_x0*game->rays->nTan;
	}
}

void	check_vertical_lines(t_game *game, double angle)
{
	game->rays->nTan = -tan(angle);
	assign_x0_y0_vertical(game, angle);
	while (game->rays->v_fov < 20)
	{
		game->rays->mx = (int)game->rays->rx>>6;
		game->rays->my = (int)game->rays->ry>>6;
		game->rays->mp = game->rays->my*game->mapp->map_x + game->rays->mx;
		if (game->rays->mp > 0 && game->rays->mp < game->mapp->map_x*game->mapp->map_y 
			&& collision_with_wall(game, game->rays->rx, game->rays->ry))
		{
			game->rays->vx=game->rays->rx;
			game->rays->vy=game->rays->ry;
			game->rays->disV=dist(game->gamer->player_posx, game->gamer->player_posy, game->rays->vx, game->rays->vy);
			game->rays->v_fov=20;
		}
		else
		{
			game->rays->rx+= game->rays->v_x0;
			game->rays->ry+= game->rays->v_y0;
			game->rays->v_fov+=1;
		}
	}
}

double	distance_player_wall(t_game *game)
{
	double disT;

	if (game->rays->disV < game->rays->disH)
	{
		game->rays->rx = game->rays->vx;
		game->rays->ry = game->rays->vy;
		disT = game->rays->disV;
		game->mapp->side_vertical = 1;
	}
	if ( game->rays->disH < game->rays->disV)
	{
		game->rays->rx = game->rays->hx;
		game->rays->ry = game->rays->hy;
		disT = game->rays->disH;
		game->mapp->side_vertical = 0;
	}
	return (disT);
}

void	get_wall_length(t_game *game, double disT, double angle)
{
	double	ca;

	ca = game->gamer->player_angle - angle;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	disT = disT * cos(ca);
	game->mapp->length_wall = (64 * 415) / disT;
	if (game->mapp->side_vertical == 0)
		game->img->offset = (int)game->rays->rx;
	else if (game->mapp->side_vertical == 1)
		game->img->offset = (int)game->rays->ry;
	game->rays->disV = 1000000;
	game->rays->disH = 1000000;
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
	double	disT;
	char	*path;

	initializer_rays_struct(game);
	ra = game->gamer->player_angle - DR*30;
	ra = check_angle(ra);
	r = 0;
	while (r < game->mapp->win_width)
	{
		check_horizontal_lines(game, ra);
		check_vertical_lines(game, ra);
		disT = distance_player_wall(game);
		get_wall_length(game, disT, ra);
		path = image_path_finder(game, ra);
		if (r == 0 || path != game->text->path_img)
			information_imgs(game, path);
		game->text->path_img = path;
		draw(game, r, game->mapp->length_wall);
		ra += DR /10;
		ra = check_angle(ra);
		r++;
	}
	create_image_in_window(game);
}
