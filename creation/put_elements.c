/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:15:21 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/08 10:06:20 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_for_direction(t_game *game, char c)
{
	int	i;

	i = 0;
	if (c == 'E')
	{
		game->gamer->player_angle = M_PI;
		i = 1;
	}
	else if (c == 'N')
	{
		game->gamer->player_angle = M_PI_2;
		i = 1;
	}
	else if (c == 'W')
	{
		game->gamer->player_angle = 0;
		i = 1;
	}
	else if (c == 'S')
	{
		game->gamer->player_angle = 3 * M_PI_2;
		i = 1;
	}
	return (i);
}

void	check_direction_of_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->newestmap[i])
	{
		j = 0;
		while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
		{
			if (check_for_direction(game, game->newestmap[i][j]))
			{
				i = -1;
				break ;
			}
			j++;
		}
		if (i == -1)
			break ;
		i++;
	}
}

char	*image_path_finder(t_game *game, double deg_rad)
{
	if ((deg_rad <= M_PI_2 || deg_rad >= 3 * M_PI_2)
		&& game->mapp->side_vertical == 1)
		return (game->we_path);
	else if (deg_rad <= M_PI && game->mapp->side_vertical == 0)
		return (game->no_path);
	else if ((deg_rad <= 3 * M_PI_2 || deg_rad >= M_PI_2)
		&& game->mapp->side_vertical == 1)
		return (game->ea_path);
	else if (deg_rad > M_PI && game->mapp->side_vertical == 0)
		return (game->so_path);
	return (NULL);
}

void	information_imgs(t_game *game, char *filename)
{
	game->text->mlx_text = mlx_xpm_file_to_image(game->mlx, filename, \
		&game->text->img_w, &game->text->img_h);
	if (!game->text->mlx_text)
	{
		perror("Error\n");
		printf("The image path \"%s\" is not correct\n", filename);
		exit(EXIT_FAILURE);
	}
	game->text->addr_text = mlx_get_data_addr(game->text->mlx_text, \
		&game->text->bpp_text, &game->text->line_len_text, &game->text->endian);
}

void	put_player(t_game *game)
{
	if (game->gamer->moved)
	{
		mlx_destroy_image(game->mlx, game->img->mlx_win);
		mlx_destroy_image(game->mlx, game->minimap->new_image);
		mlx_clear_window(game->mlx, game->win);
	}
	game->img->mlx_win = mlx_new_image(game->mlx, game->mapp->win_width, \
		game->mapp->win_height);
	game->img->addr_win = mlx_get_data_addr(game->img->mlx_win, \
		&game->img->bpp_win, &game->img->line_len_win, &game->img->endian);
	game->minimap->new_image = mlx_new_image(game->mlx, \
		game->minimap->win_width, game->minimap->win_height);
	game->minimap->addr_img = mlx_get_data_addr(game->minimap->new_image, \
		&game->minimap->bpp_mini, &game->minimap->line_len_mini, \
		&game->minimap->endian_mini);
	dda_algorithm(game);
	create_minimap(game);
}
