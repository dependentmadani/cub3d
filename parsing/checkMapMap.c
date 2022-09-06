/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:41:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/06 12:12:28 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_map_map(t_game *my_game)
{
	char	**t;
	int		i;
	t = (char **)ft_calloc(sizeof(char *), 999);
	i = 0;
	// printf("~%s~\n", my_game->map[5]);
	while (i < 6)
	{
		t[i] = ft_substr(my_game->map[i], 0, ft_strlen(my_game->map[i]));
		i++;
	}
	while (my_game->map[i])
	{
		// if (my_game->map[i][0] != '\n')
			t[i] = ft_substr(my_game->map[i], 1, ft_strlen(my_game->map[i])-1);
			// printf("t[%d]: %s", i, t[i]);
		i++;
	}
	t[i] = 0;
	i = 0;
	while (t[i])
	{
		if (t[i][0] == '\n')
		{
			printf("~%d- invalid shit!\n", i);
			exit(1);
		}
		i++;
	}
	return (t);
}
