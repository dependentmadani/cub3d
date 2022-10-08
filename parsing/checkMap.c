/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:23:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/08 11:13:24 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error_and_exit(char *s)
{
	printf("%s\n", s);
	exit(1);
}

void	check_surroundings(char **s, int i, int j)
{
	if (j > ft_strlen(s[i - 1]) || j > ft_strlen(s[i + 1]))
		print_error_and_exit("invalid map i-1 or i+1");
	if (s[i][j - 1] != '1' && s[i][j - 1] != 'S'
		&& s[i][j - 1] != 'N' && s[i][j - 1] != 'E'
		&& s[i][j - 1] != 'W' && s[i][j - 1] != '0')
		print_error_and_exit("invalid map j-1");
	if (s[i][j + 1] != '1' && s[i][j + 1] != 'S'
		&& s[i][j + 1] != 'N' && s[i][j + 1] != 'E'
		&& s[i][j + 1] != 'W' && s[i][j + 1] != '0')
		print_error_and_exit("invalid map j+1");
	if (s[i - 1][j] != '1' && s[i - 1][j] != 'S'
		&& s[i - 1][j] != 'N' && s[i - 1][j] != 'E'
		&& s[i - 1][j] != 'W' && s[i - 1][j] != '0')
		print_error_and_exit("invalid map i-1");
	if (s[i + 1][j] != '1' && s[i + 1][j] != 'S'
		&& s[i + 1][j] != 'N' && s[i + 1][j] != 'E'
		&& s[i + 1][j] != 'W' && s[i + 1][j] != '0')
		print_error_and_exit("invalid map i+1");
}

void	check_for_one_and_only(t_game *game, char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
	{
		game->one_and_only++;
		if (game->one_and_only > 1)
			print_error_and_exit("Must go only with one player!");
	}
}

void	check_firs_last(t_game *my_game, int i, int j)
{
	if (my_game->newmap[i][0] == '0'
	|| my_game->newmap[i][ft_strlen(my_game->newmap[i]) - 1] == '0')
		print_error_and_exit("invalid map j0 or jn");
	if (my_game->newmap[i][j] == '0' && (my_game->newmap[i - 1][j] == 0
		|| my_game->newmap[i + 1][j] == 0))
		print_error_and_exit("invalid map j+1");
	if (my_game->newmap[i][j] == '0')
		check_surroundings(my_game->newmap, i, j);
}

void	check_map(t_game *my_game)
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
			check_for_one_and_only(my_game, my_game->newmap[i][j]);
			if (my_game->newmap[i][0] == '\n')
				print_error_and_exit("invalid map");
			if (i == 6)
				if (my_game->newmap[i][j] == '0')
					print_error_and_exit("invalid map i_0");
			if (i == (my_game->num_rows - 1))
				if (my_game->newmap[i][j] == '0')
					print_error_and_exit("invalid map i_n");
			check_firs_last(my_game, i, j);
			j++;
		}
		i++;
	}
}
