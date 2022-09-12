/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:13:01 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/09/11 13:36:56 by ael-asri         ###   ########.fr       */
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
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        if ((int)game->gamer->player_angle == 1)
            j--;
        else
            j++;
        complete_rays_fov(game, i, j);
    }
}

void    rays_until_west_or_east(t_game* game)
{
    double i;
    double j;

    i = game->gamer->player_posx;
    j = game->gamer->player_posy;
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
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
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
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
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
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
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
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
    // update_putting_floor(game, i, j);
    while (!collision_with_wall(game, i, j))
    {
        mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
        i -= 0.1 + game->gamer->player_dx;
        j += 0.1 + game->gamer->player_dy;
    }
}

// void    complete_rays_fov(t_game *game, double player_x, double player_y)
// {
//     double i;
//     double j;
//     double vision;

//     i = player_x;
//     j = player_y;
//     vision = -PI / 6;
//     while (vision < (PI /6))
//     {
//         if (vision < 0)
//         {
//             i -= cos(vision)*game->gamer->speed;
//             j -= sin(vision)*game->gamer->speed;
//         }
//         else if (vision > 0)
//         {
//             i += cos(vision)*game->gamer->speed;
//             j += sin(vision)*game->gamer->speed;
//         }
//         mlx_pixel_put(game->mlx, game->win, i, j, 0xff0000);
//         vision += game->gamer->fov / IMG_W;
//     }
// }

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

int draw_line(t_game *game, double end_x, double end_y, int color, int angle)
{
    double d_x;
    double d_y;
    int pixel;
    double pixel_dx;
    double pixel_dy;
    // (void)angle;

    d_x = end_x - game->gamer->player_posx;
    d_y = end_y - game->gamer->player_posy;
    pixel = sqrt((d_x * d_x) + (d_y * d_y));
    d_x /= pixel;
    d_y /= pixel;
    pixel_dx = game->gamer->player_posx;
    pixel_dy = game->gamer->player_posy;
    while (pixel)
    {
        mlx_pixel_put(game->mlx, game->win, pixel_dx, pixel_dy, color);
        if (angle > P3)
        {
            pixel_dx -= d_x;
            pixel_dy += d_y;
        }
        else if (angle >= 0)
        {
            pixel_dx += d_x;
            pixel_dy += d_y;        
        }
        pixel--;
    }
    return (0);
}

double dist(double ax, double ay, double bx, double by, double ang)
{
    (void)ang;
    return (sqrt((bx - ax)* (bx - ax) + (by - ay)* (by-ay)));
}

void    spread_rays(t_game *game)
{
    int r, mx, my,mp, fov;
    double rx, ry, ra,xo, yo, disH, disV, hx, hy, vx, vy, aTan;
    (void)mp;
    ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
    // ra = game->gamer->player_angle;
    for (r=0; r< 60; r++)
    {
        ///// check the horizontal lines
        fov = 0;
        disH=1000000, hx=game->gamer->player_posx, hy=game->gamer->player_posy;
        aTan = -1/tan(ra);
        if (ra < PI) {ry =(((int)game->gamer->player_posy/64)*6)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
        if (ra > PI) {ry =(((int)game->gamer->player_posy/6)*6)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
        if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        while (fov < 8)
        {
            mx = (int)(rx)/64; my=(int)(ry)/64;  /// (ry >> 6 means that: ry / 64)
            if (mx <= game->mapp->map_x && my <= game->mapp->map_y && game->newestmap[my][mx]== '1'){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy, ra); fov=8;}
            else {rx+=xo; ry+=yo;fov+=1;}
            draw_line(game, rx, ry,0xff0000, ra);
        }
        ///// check the vertical lines
        // fov = 0;
        // float disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
        // float nTan = -tan(ra);
        // if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx>>6)<<6)-0.0001; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=-64; yo=-xo*nTan;}
        // if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx>>6)<<6)+64; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=64; yo=-xo*nTan;}
        // if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        // while (fov < 8)
        // {
        //     mx = (int)(rx)>>6; my=(int)(ry)>>6; mp=my*IMG_W+mx;
        //     if (mp < IMG_H*IMG_W && game->newestmap[my][mx]=='1'){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=8;}
        //     else {rx+=xo; ry+=yo;fov+=1;}
        // }
        // if (disV < disH) {rx = vx; ry =vy;}
        // if (disH < disV) {rx = hx; ry =hy;}
        // fov = 0;
        // disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
        // aTan = -tan(ra);
        // if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx/6)*6)-0.0001; ry=(game->gamer->player_posx-rx)*aTan+game->gamer->player_posy; xo=-64; yo=-xo*aTan;} // looking left
        // if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx/6)*6)+64; ry=(game->gamer->player_posx-rx)*aTan+game->gamer->player_posy; xo=64; yo=-xo*aTan;} // looking right
        // if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        // while (fov < 8)
        // {
        //     mx = (int)(rx)/64; my=(int)(ry)/64;  /// (ry >> 6 means that: ry / 64)
        //     if (mx <= game->mapp->map_x && my <= game->mapp->map_y && game->newestmap[my][mx]== '1'){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=8;}
        //     else {rx+=xo; ry+=yo;fov+=1;}
        //     draw_line(game, rx, ry,0xff0000, ra);
        // }
        
        /////////////////
        ra += DR;
    }
}
