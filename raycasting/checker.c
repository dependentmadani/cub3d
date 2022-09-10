/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:13:01 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/05 22:13:02 by mbadaoui         ###   ########.fr       */
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

void    rays_until_wall_north_or_south(t_game* game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000); // to change with my_mlx_pixel_put
        if ((int)game->gamer->player_angle == 1)
            j--;
        else
            j++;
    }
}

void    rays_until_west_or_east(t_game* game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000);  // to change with my_mlx_pixel_put
        if (game->gamer->player_angle == 0)
            i--;
        else
            i++;
    }
}

void    rays_until_west_north(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000);  // to change with my_mlx_pixel_put
        i -= 0.1 + game->gamer->player_dx;
        j -= 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_north_east(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000);  // to change with my_mlx_pixel_put
        i += 0.1 + game->gamer->player_dx;
        j -= 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_east_south(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000);  // to change with my_mlx_pixel_put
        i += 0.1 + game->gamer->player_dx;
        j += 0.1 + game->gamer->player_dy;
    }
}

void    rays_until_south_west(t_game *game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    while (!collision_with_wall(game, i, j))
    {
        my_mlx_pixel_put(game, i, j, 0xff0000); // to change with my_mlx_pixel_put
        i -= 0.1 + game->gamer->player_dx;
        j += 0.1 + game->gamer->player_dy;
    }
}

// void    spread_rays(t_game *game)
// {
//     if (game->gamer->player_angle == PI/2 || game->gamer->player_angle == (3*PI/2))
//         rays_until_wall_north_or_south(game);
//     else if (game->gamer->player_angle == 0 || game->gamer->player_angle == 2*PI)
//         rays_until_west_or_east(game);
//     else if (game->gamer->player_angle > 0 || game->gamer->player_angle < (PI / 2))
//         rays_until_west_north(game);
//     else if (game->gamer->player_angle > (PI/2) || game->gamer->player_angle < (PI))
//         rays_until_north_east(game);
//     else if (game->gamer->player_angle > PI || game->gamer->player_angle < (3*PI/2))
//         rays_until_east_south(game);
//     else if (game->gamer->player_angle > (3*PI/2) || game->gamer->player_angle < (2*PI))
//         rays_until_south_west(game);
// }

double dist(double ax, double ay, double bx, double by, double ang)
{
    return (sqrt((bx - ax)* (bx - ax) + (by - ay)* (by-ay)));
}

void    spread_rays(t_game *game)
{
    int r, mx, my,mp, fov;
    double rx, ry, ra,xo, yo;
    t_map *map;

    ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
    for (r=0; r< 60; r++)
    {
        ///// check the horizontal lines
        fov = 0;
        double disH=1000000, hx=game->gamer->player_posx, hy=game->gamer->player_posy;
        double aTan = -1/tan(ra);
        if (ra < PI) {ry =(((int)game->gamer->player_posy>>6)<<6)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
        if (ra > PI) {ry =(((int)game->gamer->player_posy>>6)<<6)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
        if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        while (fov < 8)
        {
            mx = (int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
            if (mp < mapX*mapY && map[mp]==1){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy, ra); fov=8;}
            else {rx+=xo; ry+=yo;fov+=1;}
        }
        ///// check the vertical lines
        fov = 0;
        float disV=1000000, vx=px, vy=py;
        float nTan = -tan(ra);
        if (ra > P2 && ra < P3) {rx =(((int)px>>6)<<6)-0.0001; ry=(px-rx)*nTan+py; xo=-64; yo=-xo*nTan;}
        if (ra < P2 || ra > P3) {rx =(((int)px>>6)<<6)+64; ry=(px-rx)*nTan+py; xo=64; yo=-xo*nTan;}
        if (ra == 0 || ra==PI) {rx=px; ry=py;fov=8;}
        while (fov < 8)
        {
            mx = (int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
            if (mp < mapX*mapY && map[mp]==1){vx=rx; vy=ry; disV=dist(px, py, vx, vy, ra); fov=8;}
            else {rx+=xo; ry+=yo;fov+=1;}
        }
        if (disV < disH) {rx = vx; ry =vy;}
        if (disH < disV) {rx = hx; ry =hy;}
}
