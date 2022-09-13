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
    // d_x /= pixel;
    d_y /= pixel;
    // pixel_dx = game->gamer->player_posx;
    pixel_dx = end_x;
    pixel_dy = game->gamer->player_posy;
    while (pixel > 0)
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
    int r, fov, mp, mx, my, color;
    double rx, ry, ra,xo, yo, disH, hx, hy, aTan, nTan, disT;

    ra = game->gamer->player_angle-DR*30; if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
    // ra = game->gamer->player_angle;
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
        double ca = game->gamer->player_angle - ra; if (ca < 0) {ca += 2*PI;} if (ca > 2*PI) {ca -= 2*PI;} disT = disT*cos(ca);
        double lineH = (game->mapp->map_size * game->mapp->win_height)/disT; if (lineH > game->mapp->win_height) {lineH = game->mapp->win_height;}
        double lineOffset = (game->mapp->win_height/2) - (lineH/2);
        // printf("the size of map is {%d} and disT = {%f}\n", game->mapp->map_size, disT);
        // printf("the value of lineH {%f} and the value of lineOffset = {%f}\n", lineH, lineOffset);
        // draw_line(game, (r)*game->mapp->map_x, -lineH/2 + lineOffset,0xff0000, ra);
        draw_line(game, (r)*(game->mapp->win_width/60), lineH+lineOffset ,color, ra);
        draw_line(game, (r)*(game->mapp->win_width/60), lineOffset ,color, ra);

        ra += DR;
        if (ra<0) {ra +=2*PI;} if (ra > 2*PI) {ra-=2*PI;};
    }
}