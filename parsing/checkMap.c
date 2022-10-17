/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:23:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/13 09:49:56 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_surroundings(char **s, int i, int j)
{
	if (s[i][j - 1] != '1' && s[i][j - 1] != 'S'
		&& s[i][j - 1] != 'N' && s[i][j - 1] != 'E'
		&& s[i][j - 1] != 'W' && s[i][j - 1] != '0')
		ft_print_error_and_exit("invalid map");
	if (s[i][j + 1] != '1' && s[i][j + 1] != 'S'
		&& s[i][j + 1] != 'N' && s[i][j + 1] != 'E'
		&& s[i][j + 1] != 'W' && s[i][j + 1] != '0')
		ft_print_error_and_exit("invalid map");
	if (s[i - 1][j] != '1' && s[i - 1][j] != 'S'
		&& s[i - 1][j] != 'N' && s[i - 1][j] != 'E'
		&& s[i - 1][j] != 'W' && s[i - 1][j] != '0')
		ft_print_error_and_exit("invalid map");
	if (s[i + 1][j] != '1' && s[i + 1][j] != 'S'
		&& s[i + 1][j] != 'N' && s[i + 1][j] != 'E'
		&& s[i + 1][j] != 'W' && s[i + 1][j] != '0')
		ft_print_error_and_exit("invalid map");
}

void	ft_check_for_one_and_only(t_game *game, char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
	{
		game->one_and_only++;
		if (game->one_and_only > 1)
			ft_print_error_and_exit("Must go only with one player!");
	}
}

void	ft_checkkk(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		ft_print_error_and_exit("invalid map");
}

void	ft_check_firs_last(t_game *my_game, int i, int j)
{
	ft_checkkk(my_game->newmap[i][0]);
	ft_checkkk(my_game->newmap[i][ft_strlen(my_game->newmap[i]) - 1]);
	if (my_game->newmap[i][j] == '0' || my_game->newmap[i][j] == 'N'
		|| my_game->newmap[i][j] == 'S' || my_game->newmap[i][j] == 'E'
		|| my_game->newmap[i][j] == 'W')
		ft_check_alone(my_game->newmap, i, j);
	if (my_game->newmap[i][j] == '0')
		ft_check_surroundings(my_game->newmap, i, j);
	if (my_game->newmap[i][j] == 'N'
		|| my_game->newmap[i][j] == 'S' || my_game->newmap[i][j] == 'E'
		|| my_game->newmap[i][j] == 'W')
		ft_check_surroundings(my_game->newmap, i, j);
}

void	ft_check_map(t_game *my_game)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (my_game->newmap[i])
	{
		j = 0;
		while (my_game->newmap[i][j])
		{
			ft_check_for_one_and_only(my_game, my_game->newmap[i][j]);
			ft_chack_char(my_game->newmap[i][j]);
			if (my_game->newmap[i][0] == '\n')
				ft_print_error_and_exit("invalid map");
			if (i == 6)
				ft_checkkk(my_game->newmap[i][j]);
			if (i == (my_game->num_rows - 1))
				ft_checkkk(my_game->newmap[i][j]);
			ft_check_firs_last(my_game, i, j);
			j++;
		}
		i++;
	}
}
