/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:13:34 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/02 09:13:35 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_in_minimap_image(t_game *game, int x, int y, int color)
{
	char	*pixel;

	// printf("value x {%d} and y {%d} value of \n", x, y);
	pixel = game->minimap->addr_img + (y* game->minimap->line_len_mini + ((x)*game->minimap->bpp_mini/8));
	*(int *)pixel = color;
}

void	borders_of_minimap(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->minimap->win_width)
	{
		j = 0;
		while (j < game->minimap->win_height)
		{
			if ((i == 0) || (i == game->minimap->win_width-1) || (j == 0) || (j == game->minimap->win_height-1))
				put_in_minimap_image(game, i , j, 0x1100ff00);
			j++;
		}
		i++;
	}
}

void	length_of_square_minimap(t_game *game)
{
	int length_width;
	int	length_height;
	
	length_width = 10;
	if (game->mapp->map_x * length_width < game->minimap->win_width)
		length_width = game->minimap->win_width / game->mapp->map_x;
	length_height = 10;
	if (game->mapp->map_y * length_height < game->minimap->win_height)
		length_height = game->minimap->win_height / game->mapp->map_y;
	game->minimap->length_square_width = length_width;
	game->minimap->length_square_height = length_height;
}

void	player_as_circle(t_game *game, int color)
{
	int i;
	int j;
	int r;
	int x;
	int y;
	int d;
	int a;

	r = 5;
	x = 0;
	y = 0;
	i = -r;
	while(i<10)
	{
		j = -r;
		while(j<10)
		{
			a=((i-x)*(i-x))+((j-y)*(j-y));
			d=sqrt(a);
			if(r>=d)
				put_in_minimap_image(game, game->minimap->win_width/2 + i,
					game->minimap->win_height/2 + j,
					color);
			j++;
		}
		i++;
	}
}

int draw_line(t_game *game, int color)
{
	double d_x;
	double d_y;
	int pixel;
	double pixel_dx;
	double pixel_dy;

	d_x = 0;
	d_y = 0;
    d_x = cos(game->gamer->player_angle)*10;
    d_y = sin(game->gamer->player_angle)*10;
	pixel = sqrt((d_x * d_x) + (d_y * d_y));
	d_x /= pixel;
	d_y /= pixel;
	pixel_dx = game->minimap->win_width/2;
	pixel_dy = game->minimap->win_height/2;
	while (pixel > 0)
	{
		put_in_minimap_image(game, pixel_dx, pixel_dy, color);
		pixel_dx -= d_x;
		pixel_dy -= d_y;
		pixel--;
	}
	return (0);
}

int	texture_minimap(t_game *game, int x, int y)
{
	int *color;
	int	x_start;
	int	y_start;

	x_start = (int)(x) % 10;
	y_start = (int)(y) % 10;
	color = (int*)(game->minimap->addr_text + (int)(y_start* game->minimap->line_len_text + ((x_start)*game->minimap->bpp_text/8)));
	return (*color);
}

int	check_player_map(t_game *game, int x, int y)
{
	if (y > game->mapp->map_x || x > game->mapp->map_y)
		return (0);
	if (game->newestmap[y][x] == 'W')
		return (1);
	else if (game->newestmap[y][x] == 'S')
		return (1);
	else if (game->newestmap[y][x] == 'N')
		return (1);
	else if (game->newestmap[y][x] == 'E')
		return (1);
	return (0);
}

int	color_minimap(t_game *game, int x, int y)
{
	int	color;

	color = 0;
	if ((int)((game->minimap->magic_x)/10 + (x - game->minimap->start_x)/10) >= game->mapp->map_x || (int)((game->minimap->magic_y)/10 + (y - game->minimap->start_y)/10) >= game->mapp->map_y)
		return (0);
	if (game->newestmap[(int)((game->minimap->magic_y)/10 + (y - game->minimap->start_y)/10)][(int)((game->minimap->magic_x)/10 + (x - game->minimap->start_x)/10)] == '0'
		|| check_player_map(game, (game->minimap->magic_x)/10 + (x - game->minimap->start_x)/10, (game->minimap->magic_y)/10 + (y - game->minimap->start_y)/10))
		color = 0x808080;
	else if (game->newestmap[(int)((game->minimap->magic_y)/10 + (y - game->minimap->start_y)/10)][(int)((game->minimap->magic_x)/10 + (x - game->minimap->start_x)/10)] == '1')
		color = 0xff0000;
	// 	color = texture_minimap(game, x, y);
	return (color);
}

void	put_minimap(t_game *game)
{
	int	x;
	int	y;
	double	start_x;
	double	start_y;
	int color;

	start_x = 0;
	start_y = 0;
	if (game->minimap->start_x != 0)
		start_x = 0;
	else if (game->minimap->start_x == 0)
		start_x = game->mapp->position_map_x*10 - game->minimap->win_width/2;
	if (game->minimap->start_y != 0)
		start_y = 0;
	else if (game->minimap->start_y == 0)
		start_y = game->mapp->position_map_y*10 - game->minimap->win_height/2;
	game->minimap->magic_x = start_x; // the variable used to start to map variable
	game->minimap->magic_y = start_y;
	y = (int)game->minimap->start_y; // the variable used to start to on the new image
	while (y < game->minimap->win_height)
	{
		x = (int)game->minimap->start_x;
		while (x < game->minimap->win_width)
		{
			color = color_minimap(game, x, y);
			put_in_minimap_image(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	mini_moving_map(t_game *game)
{
	double	i;
	double	j;
	double	size_text;

	i = 0.0;
	j = 0.0;
	size_text = 10.0;
	if ((game->minimap->win_width/2 - game->mapp->position_map_x*size_text) > 0)
		i = fabs(game->minimap->win_width/2 - game->mapp->position_map_x*size_text);
	else if ((game->minimap->win_width/2 - game->mapp->position_map_x*size_text) <= 0)
		i = 0.0;
	if ((game->minimap->win_height/2 - game->mapp->position_map_y*size_text) > 0)
		j = fabs(game->minimap->win_height/2 - game->mapp->position_map_y*size_text);
	else if ((game->minimap->win_height/2 - game->mapp->position_map_y*size_text) <= 0)
		j = 0.0;
	game->minimap->start_x = i;
	game->minimap->start_y = j;
	put_minimap(game);
}

void	create_minimap(t_game *game)
{
	borders_of_minimap(game);
	mini_moving_map(game);
	length_of_square_minimap(game);
	player_as_circle(game, 0x0000ff);
	draw_line(game, 0xff0000);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->new_image, 10,10);
}
