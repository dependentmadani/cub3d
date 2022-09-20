/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:56:49 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/20 17:50:55 by ael-asri         ###   ########.fr       */
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
	if (game->newestmap[estimation_posy] && game->newestmap[estimation_posy][estimation_posx] == '1')
		return (1);
	return (0);
}
/*
int draw(t_game *game, double end_x, double end_y, int color, int angle)
{
	double d_x;
	double d_y;
	int pixel;
	double pixel_dx;
	double pixel_dy;
	(void)angle;


	pixel_dx = end_x;
	pixel_dy = (game->mapp->win_height/2) - (end_y/2);
	while (pixel_dy <= (game->mapp->win_height/2) + (end_y/2))
	{
		// if (pixel_dx > game->mapp->map_x*IMG_H || pixel_dx < 0)
		// {
		//     pixel--;
		//     continue;
		// }
		// if (pixel_dy > game->mapp->map_y*IMG_W || pixel_dy < 0)
		// {
		//     pixel--;
		//     continue;
		// }
		mlx_pixel_put(game->mlx, game->win, pixel_dx, pixel_dy, color);
		// pixel_dx += d_x;
		pixel_dy += 1;
	}
	return (0);
}
*/
double dist(double ax, double ay, double bx, double by, double ang)
{
	(void)ang;
	return (sqrt((bx - ax)*(bx - ax) + (by - ay)* (by-ay)));
}
/*
void	draw_image(t_game *my_game, double ra, int x, int y)
{
	int	d = ra * (my_game->img_h) / 60;
	void *im;
	int i = 0;

	// double 
	// while (i<10)
	// {	
	// 	im = mlx_xpm_to_image(my_game->mlx, &my_game->no_path, &my_game->map_w, &my_game->map_h);
	// 	mlx_put_image_to_window(my_game->mlx, my_game->win, im, &my_game->map_w, &my_game->map_h);
	// 	i++;
	// }
	void *no = mlx_xpm_to_image(my_game->mlx, &my_game->no_path, &my_game->img_w, &my_game->img_h);
	void *so = mlx_xpm_to_image(my_game->mlx, &my_game->so_path, &my_game->img_w, &my_game->img_h);
	int wallStripH = 0;
	int *colorBuffer;
	colorBuffer = (int *)malloc(sizeof(int) * my_game->mapp->win_width * my_game->mapp->win_height);
//	for (int i=0; i < my_game->mapp->win_width; i++)
//	{
		int wallTopPixel = (my_game->mapp->win_height / 2) - (wallStripH / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		int wallBottomPixel = (my_game->mapp->win_height / 2) + (wallStripH / 2);
		wallBottomPixel = wallBottomPixel > my_game->mapp->win_height ? my_game->mapp->win_height : wallBottomPixel;
		// wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		// drawin wall
		for (int y=0; y < wallTopPixel; y++)
		{
			colorBuffer[(my_game->mapp->win_width * y) + i] = 0xFF333333;
		}
		for (int y=wallTopPixel; y < wallBottomPixel; y++)
		{
			*//*int distanceFromTop = y+ (wallStripH/2) - (my_game->mapp->win_height/2);
			int textureOffsetY = distanceFromTop * ((float)64/wallStripH);

			unsigned int textColor = my_game->newestmap[][(64*textureOffsetY) + textureOffsetX] = textColor;
			my_game->newestmap[x][my_game->mapp->win_width * y] + i = no;*/
		/*	colorBuffer[(my_game->mapp->win_width * y) + i] = rays[i].wasHitVertical ? 0xFFFFFFFF : 0xFFCCCCCC;
		}
		for (int y=wallBottomPixel; y < my_game->mapp->win_height; y++)
		{
			colorBuffer[(my_game->mapp->win_width * y) + i] = 0xFF777777;
		}
//	}
}
*/
int draw(t_game *game, double end_x, double end_y, int color, int angle, int distT, double rx, double ry)
{
	double pixel_dx;
	double pixel_dy=0;
	int		x;
	double		y;
	(void)angle;
	// (void)color;
	(void)ry;
	// (void)rx;
	// (void)distT;

	float distanceProjPlan = (game->mapp->win_width / 2) / tan((60 * (PI / 180)) / 2);
	float projectWallH = (64 / distT) * distanceProjPlan;
	int wallStripH = (int)projectWallH;
	int wallTopPixel = (game->mapp->win_height / 2) - (wallStripH / 2);
	wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
	int wallBottomPixel = (game->mapp->win_height / 2) + (wallStripH / 2);
	wallBottomPixel = wallBottomPixel > game->mapp->win_height ? game->mapp->win_height : wallBottomPixel;
	int *wallTexture;
	wallTexture = malloc(sizeof(int)* 64*64);
	for (int v=0; v<64; v++)
	{
		for (int w=0; w<64; w++)
		{
			wallTexture[64 * w + v] = (v%8 && w%8) ? 0xFFFFFF: 0xFF0000;
		}
	}
	// void *no = mlx_xpm_to_image(game->mlx, &game->no_path, &game->img_w, &game->img_h);
	// // void *so = mlx_xpm_to_image(game->mlx, &game->so_path, &game->img_w, &game->img_h);
	// int bpp=0, endian=0;
	// int *sizeLine=NULL;
	// wallTexture = mlx_get_data_addr(no, &bpp, sizeLine, &endian);
	// draw the ceillin color
	
	game->c_color = ((game->c_rgb[0] << 16) + (game->c_rgb[1] << 8) + (game->c_rgb[2]));
	game->f_color = ((game->f_rgb[0] << 16) + (game->f_rgb[1] << 8) + (game->f_rgb[2]));
	pixel_dx = end_x;
	pixel_dy = (game->mapp->win_height/2) - (end_y/2);
	y = 0;
	(void)color;
	// for (int y=0; y < pixel_dy; y++)
	while (y < game->mapp->win_height)
	{
		x = pixel_dx;
		if (y <= (int)((game->mapp->win_height/2) - (end_y/2)))
		{
			while (x < (pixel_dx + 10))
				mlx_pixel_put(game->mlx, game->win, x++, y, game->c_color);
		}
		else if (y > ((game->mapp->win_height/2) - (end_y/2)) && y <= (int)((game->mapp->win_height/2) + (end_y/2)))
		{
			int textureOffsetX = (int)rx % 64;
			while (x < (pixel_dx + 10))
			{
				int textureOffsetY = (y - end_y) * ((float)64 / wallStripH);
				int texturColor = wallTexture[(64*textureOffsetY) + textureOffsetX];
				mlx_pixel_put(game->mlx, game->win, x++, y, texturColor);
			}
		}
		else
		{
			while (x < (pixel_dx + 10))
				mlx_pixel_put(game->mlx, game->win, x++, y, game->f_color);
		}
		y++;
	}
	
/*	while (y <= (int)((game->mapp->win_height/2) - (end_y/2)))
	{
		x = pixel_dx;
		while (x < (pixel_dx + 10))
			mlx_pixel_put(game->mlx, game->win, x++, y, 0xFF00ff);
		y += 1;
		printf("yoooooo\n");
	}
	// draw the walls color
	printf("dyyy %f\n", pixel_dy);
	printf("dxxx %f\n", pixel_dx);
	pixel_dx = end_x;
	pixel_dy = (game->mapp->win_height/2) - (end_y/2);
	while (pixel_dy <= (int)((game->mapp->win_height/2) + (end_y/2)))
	{
		x = pixel_dx;
		while (x < (pixel_dx + 10))
			mlx_pixel_put(game->mlx, game->win, x++, pixel_dy, color);
		pixel_dy += 1;
	}
	pixel_dx = end_x;
	// pixel_dy = (game->mapp->win_height/2) - (end_y/2);
	y = pixel_dy;
	// draw the floor color
	while (y <= (game->mapp->win_height))
	{
		x = pixel_dx;
		while (x < (pixel_dx + 10))
			mlx_pixel_put(game->mlx, game->win, x++, y, 0xFF7777);
		y += 1;
		printf("yaaaaaa\n");
	}*/
	return (0);
}


void    spread_rays(t_game *game)
{
	int r, fov, mp, mx, my, color;
	double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan, disT;

	ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
	// ra = game->gamer->player_angle;

	//
	// void *no = mlx_xpm_to_image(game->mlx, &game->no_path, &game->img_w, &game->img_h);
	// void *so = mlx_xpm_to_image(game->mlx, &game->so_path, &game->img_w, &game->img_h);
	//
	for (r=0; r< 60; r++)
	{
		///// check the horizontal lines
		fov = 0;
		disH=1000000, hx=game->gamer->player_posx, hy=game->gamer->player_posy;
		aTan = -1/tan(ra);
		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=14;}
		if (ra < PI) {ry =(((int)game->gamer->player_posy/64)*64)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
		if (ra > PI) {ry =(((int)game->gamer->player_posy/64)*64)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
		while (fov < 13)
		{
			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy, ra); fov=14;}
			else {rx+=xo; ry+=yo;fov+=1;}
		}

		///// check the vertical lines
		fov = 0;
		double disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
		nTan = -tan(ra);
		if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=13;}
		if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx/64)*64)+64; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=64; yo=-xo*nTan;}
		if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx/64)*64)-0.0001; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=-64; yo=-xo*nTan;} // problem need to be fixed here
		while (fov < 12)
		{
			mx = (int)rx>>6; my = (int)ry>>6; mp = my*game->mapp->map_x+mx;
			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=13;}
			else {rx+=xo; ry+=yo;fov+=1;}
		}
		if (disV < disH) {rx = vx; ry =vy; disT = disV; color=0x0000ff;}
		if (disH < disV) {rx = hx; ry =hy; disT = disH; color=0xff0000;}
		// printf("the value of ");
		double ca = game->gamer->player_angle - ra; if (ca < 0) {ca += 2*PI;} if (ca > 2*PI) {ca -= 2*PI;} disT = disT*cos(ca);
		// double lineH = (game->mapp->map_size * game->mapp->win_height)/disT; if (lineH > game->mapp->win_height) {lineH = game->mapp->win_height;}
		double lineH = (64*277)/(disT); //if (lineH > game->mapp->win_height) {lineH = game->mapp->win_height;}
		// double lineOffset = (game->mapp->win_height/2) - (lineH/2);
		draw(game, (r)*(game->mapp->win_width/60), lineH,color, ra, disT, rx, ry);
		// draw_image(game, ra);
		// draw(game, (r)*(game->mapp->win_width/60), lineOffset ,color, ra);
		// printf("the value of lineOffset is {%f} and the value of lineH is {%f} and disT {%f}\n", lineOffset, lineH, disT);
		// printf("the value of lineOffset = {%f}\n", lineOffset);
		ra += DR;
		if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
	}
	// printf("the length of of map in x axis {%f} and in y axis {%f}\n", game->mapp->map_x, game->mapp->map_y);
}
