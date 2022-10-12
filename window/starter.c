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

void	check_file_paths_images_2(t_game *game, int *i)
{
	if (!mlx_xpm_file_to_image(game->mlx, game->we_path, \
		&game->text->img_w, &game->text->img_h))
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->we_path);
		*i = -1;
	}
	if (!mlx_xpm_file_to_image(game->mlx, game->ea_path, \
		&game->text->img_w, &game->text->img_h))
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->ea_path);
		*i = -1;
	}
}

void	check_file_paths_images(t_game *game)
{
	int	i;

	i = 0;
	if (!mlx_xpm_file_to_image(game->mlx, game->no_path, \
		&game->text->img_w, &game->text->img_h))
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->no_path);
		i = -1;
	}
	if (!mlx_xpm_file_to_image(game->mlx, game->so_path, \
		&game->text->img_w, &game->text->img_h))
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", game->so_path);
		i = -1;
	}
	check_file_paths_images_2(game, &i);
	if (i == -1)
	{
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	initialize_dx_dy(t_game *game)
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

void	initializer(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_win));
	game->text = ft_calloc(1, sizeof(t_texture));
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	game->rays = ft_calloc(1, sizeof(t_rays));
	game->minimap->map = game->mapp;
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

void	creation_window(t_game *game)
{
	initializer(game);
	create_window(game);
}
