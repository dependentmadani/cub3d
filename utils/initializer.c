/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:10:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/05 15:00:45 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_initializer(t_game *my_game)
{
	my_game->is_no = 0;
	my_game->is_so = 0;
	my_game->is_we = 0;
	my_game->is_ea = 0;
	my_game->is_f = 0;
	my_game->is_c = 0;
	my_game->one_and_only = 0;
	my_game->p_valid = 0;
	my_game->min_rad = (-1 * PI / 2) - 1500;
	my_game->min_rad = (-1 * PI / 2) + 1500;
}
