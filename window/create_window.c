/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:07:58 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/17 07:01:15 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#')
			return (1);
		i++;
	}
	return (0);
}

void	ft_count_the_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->newestmap[i])
	{
		j = 0;
		while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
		{
			j++;
			if (game->newestmap[i][j - 1] != '#' && j > game->mapp->map_x)
				game->mapp->map_x = j;
		}
		i++;
	}
	i = 0;
	while (game->newestmap[i])
	{
		game->mapp->map_y += 1;
		i++;
	}
	game->mapp->map_size = game->mapp->map_x * game->mapp->map_y;
}

void	ft_showing_3d_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->newestmap[i])
	{
		j = 0;
		while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
		{
			if (game->newestmap[i][j] == 'N' || game->newestmap[i][j] == 'S'
				|| game->newestmap[i][j] == 'E' || game->newestmap[i][j] == 'W')
			{
				game->gamer->player_posx = IMG_H * j + IMG_H / 2;
				game->gamer->player_posy = IMG_W * i + IMG_W / 2;
				ft_put_player(game);
			}
			j++;
		}
		i++;
	}
}

void	ft_create_window(t_game *game)
{
	ft_count_the_map(game);
	ft_check_file_paths_images(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to create connection of display and software\n");
		exit(EXIT_FAILURE);
	}
	ft_information_imgs(game);
	ft_rgb_converter(game);
	ft_check_direction_of_player(game);
	ft_initialize_dx_dy(game);
	ft_assign_max_fov(game);
	game->win = mlx_new_window(game->mlx, game->mapp->win_width, \
		game->mapp->win_height, "cub3D");
	ft_showing_3d_game(game);
	mlx_hook(game->win, 2, 1L << 0, ft_keyword_move, game);
	mlx_hook(game->win, 4, 1L << 2, ft_mouse_move, game);
	mlx_hook(game->win, 17, 1L << 0, ft_exit_function, game);
	mlx_key_hook(game->win, ft_keyword_move, game);
	mlx_mouse_hook(game->win, ft_mouse_move, game);
	mlx_loop(game->mlx);
}
