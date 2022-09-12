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
    // printf("the value of d_x {%f} and d_y {%f}\n", d_x,d_y);
    pixel = sqrt((d_x * d_x) + (d_y * d_y));
    d_x /= pixel;
    d_y /= pixel;
    pixel_dx = game->gamer->player_posx;
    pixel_dy = game->gamer->player_posy;
    while (pixel)
    {
        if (pixel_dx > game->mapp->map_x*IMG_H || pixel_dx < 0)
        {
            pixel--;
            continue;
        }
        if (pixel_dy > game->mapp->map_y*IMG_W || pixel_dy < 0)
        {
            pixel--;
            continue;
        }
        mlx_pixel_put(game->mlx, game->win, pixel_dx, pixel_dy, color);
        pixel_dx += d_x;
        pixel_dy += d_y;
        pixel--;
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
    int r, fov;
    double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan;

    // ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
    // printf("the value of angle {%f}\n", ra);
    ra = game->gamer->player_angle;
    for (r=0; r< 1; r++)
    {
        ///// check the horizontal lines
        fov = 0;
        disH=1000000, hx=game->gamer->player_posx, hy=game->gamer->player_posy;
        aTan = -1/tan(ra);
        if (ra < PI) {ry =(((int)game->gamer->player_posy / 64)*64)-0.0001; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=-64; xo=-yo*aTan;}
        if (ra > PI) {ry =(((int)game->gamer->player_posy / 64) * 64)+64; rx=(game->gamer->player_posy-ry)*aTan+game->gamer->player_posx; yo=64; xo=-yo*aTan;}
        if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        // printf("before: \tpos x is {%f}\tthe value of rx {%f} and the value of ry {%f} angle nTan is {%f}\n", game->gamer->player_posx, rx, ry, aTan);
        while (fov < 8)
        {
            if (collision_with_wall(game, rx, ry)){hx=rx; hy=ry; disH=dist(game->gamer->player_posx, game->gamer->player_posy, hx, hy, ra); fov=8;}
            else {rx+=xo; ry+=yo;fov+=1;}
        }
        // printf("first: \tpos x is {%f}\tthe value of hx {%f} and the value of hy {%f} angle nTan is {%f}\n", game->gamer->player_posx, hx, hy, aTan);
        // printf("the value of hx {%f} the value of hy {%f}\n", hx, hy);
        // draw_line(game, rx, ry,0xffff00, ra);
        
        // /// check the vertical lines
        
        fov = 0;
        double disV=1000000, vx=game->gamer->player_posx, vy=game->gamer->player_posy;
        nTan = -1*tan(ra);
        if (ra > P2 && ra < P3) {rx =(((int)game->gamer->player_posx/64)*64)+64; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=64; yo=-xo*nTan;}
        if (ra < P2 || ra > P3) {rx =(((int)game->gamer->player_posx/64)*64)-0.0001; ry=(game->gamer->player_posx-rx)*nTan+game->gamer->player_posy; xo=-64; yo=-xo*nTan;} // problem need to be fixed here
        if (ra == 0 || ra==PI) {rx=game->gamer->player_posx; ry=game->gamer->player_posy;fov=8;}
        // printf("before, the value of xo {%f} and y0 {%f}\n", xo, yo);
        // printf("first: \tpos x is {%f}\tthe value of rx {%f} and the value of ry {%f} angle nTan is {%f}\n", game->gamer->player_posx, rx, ry, nTan);
        // printf("position of player in x {%f} and in y {%f}\n", game->gamer->player_posx, game->gamer->player_posy);
        while (fov < 8)
        {
            if (collision_with_wall(game, rx, ry)){vx=rx; vy=ry; disV=dist(game->gamer->player_posx, game->gamer->player_posy, vx, vy, ra); fov=8;}
            else {rx+=xo; ry+=yo;fov+=1;}
        }
        // printf("second: \tpos x is {%f}\tthe value of vx {%f} and the value of vy {%f} angle nTan is {%f}\n", game->gamer->player_posx, vx, vy, nTan);
        // printf("the value of disV {%f} the value of disH {%f}\n", disV, disH);
        if (disV < disH) {rx = vx; ry =vy;}
        if (disH < disV) {rx = hx; ry =hy;}
        draw_line(game, rx, ry,0xff0000, ra);
        // printf("what it tooks is: rx {%f} and ry {%f} and disH = {%f} and disV = {%f}\n", rx, ry, disH, disV);
        ra += DR;
        if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
        // printf("\n");

    }
    // printf("all good and the value of the angle is {%f}\n", ra);
}