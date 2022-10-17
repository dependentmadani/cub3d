/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:47:06 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/09 09:37:12 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_file_paths_images_2(t_game *game, int *i)
{
	int	j;

	j = open(game->we_path, O_RDONLY);
	if (j == -1)
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->we_path);
		*i = -1;
	}
	if (j != -1)
		close(j);
	j = open(game->ea_path, O_RDONLY);
	if (j == -1)
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->ea_path);
		*i = -1;
	}
	if (j == -1)
		close(j);
}

void	ft_check_file_paths_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = open(game->no_path, O_RDONLY);
	if (j == -1)
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->no_path);
		i = -1;
	}
	if (j != -1)
		close(j);
	j = open(game->so_path, O_RDONLY);
	if (j == -1)
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->so_path);
		i = -1;
	}
	if (j != -1)
		close(j);
	ft_check_file_paths_images_2(game, &i);
	if (i == -1)
		exit(EXIT_FAILURE);
}

void	ft_initialize_dx_dy(t_game *game)
{
	if (game->gamer->player_angle == 0 || game->gamer->player_angle == M_PI)
	{
		game->gamer->player_dx = cos(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle) * \
			game->gamer->speed;
	}
	else if (game->gamer->player_angle == M_PI_2
		|| game->gamer->player_angle == 3 * M_PI_2)
	{
		game->gamer->player_dx = cos(game->gamer->player_angle) * \
			game->gamer->speed;
		game->gamer->player_dy = sin(game->gamer->player_angle) * \
			game->gamer->speed;
	}
}

void	ft_initialize(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_win));
	game->text = ft_calloc(1, sizeof(t_texture));
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	game->rays = ft_calloc(1, sizeof(t_rays));
	game->path = ft_calloc(1, sizeof(t_path_text));
	game->mapp->win_width = 1200;
	game->mapp->win_height = 800;
	game->minimap->win_width = game->mapp->win_width / 4;
	game->minimap->win_height = game->mapp->win_height / 4;
	game->text->path_img = NULL;
	game->gamer->fov = 60.0;
	game->gamer->speed = 15;
	game->gamer->player_posx = 0;
	game->gamer->player_posy = 0;
	game->gamer->moved = 0;
	game->mapp->map_x = 0;
	game->mapp->map_y = 0;
	game->mapp->theta = 0;
	game->mapp->length_wall = 0;
	game->mapp->intersection_wall = 0;
	game->mapp->side_vertical = 0;
	game->img->offset = 0;
	game->img->scale_resize = 0;
	game->mapp->map_size = 0;
}

void	ft_creation_window(t_game *game)
{
	ft_initialize(game);
	ft_create_window(game);
}
