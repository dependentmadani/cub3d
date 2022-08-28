/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:23:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/08/28 10:52:41 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int	ft_check_entourage_space(char **array, int pos_x, int pos_y)
// {

// }

void	check_map(t_game *my_game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (my_game->newmap[i])
	{
		j = 0;
		while (my_game->newmap[i][j])
		{
			if (i == 0)
			{
				if (my_game->newmap[i][j] == '0')
				{
					printf("invalid map i0\n");
					exit(1);
				}
			}
			if (my_game->newmap[i][j] == '0')
			{
				if (my_game->newmap[i][j - 1] != '1' && my_game->newmap[i][j - 1] != 'S' && my_game->newmap[i][j - 1] != 'N' && my_game->newmap[i][j - 1] != '0')
				{
					printf("invalid map j-1\n");
					exit(1);
				}
				if (my_game->newmap[i][j + 1] != '1' && my_game->newmap[i][j + 1] != 'S' && my_game->newmap[i][j + 1] != 'N' && my_game->newmap[i][j + 1] != '0')
				{
					printf("invalid map j+1\n");
					exit(1);
				}
				if (my_game->newmap[i - 1][j] != '1' && my_game->newmap[i - 1][j] != 'S' && my_game->newmap[i - 1][j] != 'N'&& my_game->newmap[i - 1][j] != '0')
				{
					printf("invalid map i-1\n");
					exit(1);
				}
				if (my_game->newmap[i + 1][j] != '1' && my_game->newmap[i + 1][j] != 'S' && my_game->newmap[i + 1][j] != 'N'&& my_game->newmap[i + 1][j] != '0')
				{
					printf("invalid map i+1\n");
					exit(1);
					// return ;
				}
			}
			if (my_game->newmap[i+1] == NULL)
			{
				if (my_game->newmap[i][j] == '0')
				{
					printf("invalid map i0\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
