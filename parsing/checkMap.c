/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:23:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/03 14:14:05 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_error_and_exit(char *s)
{
	printf("%s\n", s);
	exit(1);
}

void	check_surroundings(char **s, int i, int j)
{
	if (s[i][j - 1] != '1' && s[i][j - 1] != 'S' && s[i][j - 1] != 'N' && s[i][j - 1] != 'E' && s[i][j - 1] != 'W' && s[i][j - 1] != '0')
		print_error_and_exit("invalid map j-1");
	if (s[i][j + 1] != '1' && s[i][j + 1] != 'S' && s[i][j + 1] != 'N' && s[i][j + 1] != 'E' && s[i][j + 1] != 'W' && s[i][j + 1] != '0')
		print_error_and_exit("invalid map j+1");
	if (s[i - 1][j] != '1' && s[i - 1][j] != 'S' && s[i - 1][j] != 'N' && s[i - 1][j] != 'E' && s[i - 1][j] != 'W' && s[i - 1][j] != '0')
		print_error_and_exit("invalid map i-1");
	if (s[i + 1][j] != '1' && s[i + 1][j] != 'S' && s[i + 1][j] != 'N' && s[i + 1][j] != 'E' && s[i + 1][j] != 'W' && s[i + 1][j] != '0')
		print_error_and_exit("invalid map i+1");
}

void	check_map(t_game *my_game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (my_game->newestmap[i] != 0)
	{
		j = 0;
		while (my_game->newestmap[i][j])
		{
			if (i == 0)
			{
				if (my_game->newestmap[i][j] == '0')
					print_error_and_exit("invalid map i0");
			}
			else if (my_game->newestmap[i][j] == '0')
				check_surroundings(my_game->newestmap, i, j);
			else if (my_game->newestmap[i + 1] == NULL)
				if (my_game->newestmap[i][j] == '0')
					print_error_and_exit("invalid map i0");
			j++;
		}
		i++;
	}
}
