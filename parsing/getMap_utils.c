/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:22:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/12 14:48:51 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_realstrlen(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	return (len);
}

void	ft_get_longestwidth(t_game *my_game)
{
	int	i;
	int	temp;
	int	x;

	i = 6;
	temp = ft_strlen(my_game->newmap[i]);
	while (my_game->newmap[i])
	{
		if (temp < ft_strlen(my_game->newmap[i]))
		{
			temp = ft_strlen(my_game->newmap[i]);
			x = 0;
			while (my_game->newmap[i][x] && my_game->newmap[i][x] != '1')
				x++;
		}
		i++;
	}
	my_game->longestwidth = temp;
}

void	ft_chack_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E' && c != ' ')
		ft_print_error_and_exit("invalid character");
}
