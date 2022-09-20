/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:56:49 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/15 11:56:51 by mbadaoui         ###   ########.fr       */
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

int draw_line(t_game *game, double end_x, double end_y, int color, int angle)
{
    double d_x;
    double d_y;
    int pixel;
    double pixel_dx;
    double pixel_dy;
    (void)angle;

    d_x = end_x - game->gamer->player_posx;
    d_y = end_y - game->gamer->player_posy;
    pixel = sqrt((d_x * d_x) + (d_y * d_y));
    d_x /= pixel;
    d_y /= pixel;
    pixel_dx = game->gamer->player_posx;
    pixel_dy = game->gamer->player_posy;
    while (pixel > 0)
    {
        mlx_pixel_put(game->mlx, game->win, pixel_dx, pixel_dy, color);
        pixel_dx += d_x;
        pixel_dy += d_y;
        pixel--;
    }
    return (0);
}

// void    img_pix_put(t_map *map, int x, int y, int color)
// {
//     char    *pixel;
//     int     i;

//     i = map->img->bpp - 8;
//     pixel = map->img->addr + (y * map->img->line_len + x * (map->img->bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (map->img->endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (map->img->bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }

// void draw_wall_image(t_game *game, int start_pos_y, int end_pos_y, int start_pos_x)
// {
// 	t_img img;

// 	img = *game->mapp->img;
// 	img.mlx_img = mlx_new_image(game->mlx, game->mapp->win_width, game->mapp->win_height);
// 	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);

// }

int draw(t_game *game, double end_x, double end_y, int color, int angle)
{
	double pixel_dx;
	double pixel_dy;
	int		x;
	(void)angle;

	pixel_dx = end_x;
	pixel_dy = 0;
	while (pixel_dy <= (int)((game->mapp->win_height)))
	{
		x = pixel_dx;
		if (pixel_dy < (game->mapp->win_height/2)-(end_y/2))
		{
			while (x < (pixel_dx + 10))
				mlx_pixel_put(game->mlx, game->win, x++, pixel_dy, game->mapp->color_ceiling);
		}
		else if (pixel_dy > ((game->mapp->win_height/2)-end_y/2) && pixel_dy < ((game->mapp->win_height/2)+end_y/2))
		{
			while (x < (pixel_dx + 10))
				mlx_pixel_put(game->mlx, game->win, x++, pixel_dy, color);
		}
		else
		{
			while (x < (pixel_dx + 10))
				mlx_pixel_put(game->mlx, game->win, x++, pixel_dy, game->mapp->color_floor);
		}
		pixel_dy += 1;
	}
	return (0);
}

double dist(double ax, double ay, double bx, double by, double ang)
{
	(void)ang;
	return (sqrt((bx - ax)*(bx - ax) + (by - ay)* (by-ay)));
}


void    spread_rays(t_game *game)
{
	int r, fov, mp, mx, my, color;
	double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan, disT;

	ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
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
			if (mp > 0 && mp < game->mapp->map_x*game->mapp->map_y && collision_with_wall(game, rx, ry)){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=14;}
			else {rx+=xo; ry+=yo;fov+=1;}
		}
		if (disV < disH) {rx = vx; ry =vy; disT = disV; color=0x0000ff;}
		if (disH < disV) {rx = hx; ry =hy; disT = disH; color=0xff0000;}
		double ca = game->gamer->player_angle - ra; if (ca < 0) {ca += 2*PI;} if (ca > 2*PI) {ca -= 2*PI;} disT = disT*cos(ca);
		double lineH = (64*415)/(disT); if (lineH > game->mapp->win_height) {lineH = game->mapp->win_height;}
		// double top_pixel_wall = game->mapp->win_height/2 - lineH/2;
		// double end_pixel_wall = game->mapp->win_height/2 + lineH/2;
		draw(game, (r)*(game->mapp->win_width/60), lineH,color, ra);
		

		// draw(game, (r)*(game->mapp->win_width/60), lineOffset ,color, ra);
		// printf("the value of lineOffset is {%f} and the value of lineH is {%f} and disT {%f}\n", lineOffset, lineH, disT);
		// printf("the value of lineOffset = {%f}\n", lineOffset);
		ra += DR;
		if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
	}
	// printf("the length of of map in x axis {%f} and in y axis {%f}\n", game->mapp->map_x, game->mapp->map_y);
}
