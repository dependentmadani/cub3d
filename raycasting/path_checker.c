/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:56:30 by mbadaoui          #+#    #+#             */
/*   Updated: 2022/10/17 17:56:31 by mbadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_so_path(t_game *game)
{
	game->text->mlx_text = game->path->mlx_text_so;
	game->text->addr_text = game->path->addr_text_so;
	game->text->bpp_text = game->path->bpp_text_so;
	game->text->line_len_text = game->path->line_len_text_so;
	game->text->endian = game->path->endian_so;
}

void	ft_no_path(t_game *game)
{
	game->text->mlx_text = game->path->mlx_text_no;
	game->text->addr_text = game->path->addr_text_no;
	game->text->bpp_text = game->path->bpp_text_no;
	game->text->line_len_text = game->path->line_len_text_no;
	game->text->endian = game->path->endian_no;
}

void	ft_ea_path(t_game *game)
{
	game->text->mlx_text = game->path->mlx_text_ea;
	game->text->addr_text = game->path->addr_text_ea;
	game->text->bpp_text = game->path->bpp_text_ea;
	game->text->line_len_text = game->path->line_len_text_ea;
	game->text->endian = game->path->endian_ea;
}

void	ft_we_path(t_game *game)
{
	game->text->mlx_text = game->path->mlx_text_we;
	game->text->addr_text = game->path->addr_text_we;
	game->text->bpp_text = game->path->bpp_text_we;
	game->text->line_len_text = game->path->line_len_text_we;
	game->text->endian = game->path->endian_we;
}

void	ft_path_checker(t_game *game, char *path)
{
	if (game->so_path == path)
		ft_so_path(game);
	else if (game->no_path == path)
		ft_no_path(game);
	else if (game->ea_path == path)
		ft_ea_path(game);
	else if (game->we_path == path)
		ft_we_path(game);
}
