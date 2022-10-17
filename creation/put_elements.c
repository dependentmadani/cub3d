/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:15:21 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/17 07:00:52 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_for_direction(t_game *game, char c)
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

void	ft_check_direction_of_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->newestmap[i])
	{
		j = 0;
		while (game->newestmap[i][j] && game->newestmap[i][j] != '\n')
		{
			if (ft_check_for_direction(game, game->newestmap[i][j]))
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

char	*ft_image_path_finder(t_game *game, double deg_rad)
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

void	ft_information_imgs(t_game *game)
{
	game->path->mlx_text_so = mlx_xpm_file_to_image(game->mlx, game->so_path, \
		&game->path->img_w_so, &game->path->img_h_so);
	game->path->addr_text_so = mlx_get_data_addr(game->path->mlx_text_so, \
		&game->path->bpp_text_so, &game->path->line_len_text_so, \
		&game->path->endian_so);
	game->path->mlx_text_no = mlx_xpm_file_to_image(game->mlx, game->no_path, \
		&game->path->img_w_no, &game->path->img_h_no);
	game->path->addr_text_no = mlx_get_data_addr(game->path->mlx_text_no, \
		&game->path->bpp_text_no, &game->path->line_len_text_no, \
		&game->path->endian_no);
	game->path->mlx_text_ea = mlx_xpm_file_to_image(game->mlx, game->ea_path, \
		&game->path->img_w_ea, &game->path->img_h_ea);
	game->path->addr_text_ea = mlx_get_data_addr(game->path->mlx_text_ea, \
		&game->path->bpp_text_ea, &game->path->line_len_text_ea, \
		&game->path->endian_ea);
	game->path->mlx_text_we = mlx_xpm_file_to_image(game->mlx, game->we_path, \
		&game->path->img_w_we, &game->path->img_h_we);
	game->path->addr_text_we = mlx_get_data_addr(game->path->mlx_text_we, \
		&game->path->bpp_text_we, &game->path->line_len_text_we, \
		&game->path->endian_we);
}

void	ft_put_player(t_game *game)
{
	if (game->gamer->moved)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_image(game->mlx, game->img->mlx_win);
		mlx_destroy_image(game->mlx, game->minimap->new_image);
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
	ft_dda_algorithm(game);
	ft_create_minimap(game);
}
