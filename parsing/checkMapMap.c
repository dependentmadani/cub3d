/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:41:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/13 16:07:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_map_map(t_game *my_game)
{
	char	**t;
	int		i;

	t = (char **)ft_calloc(sizeof(char *), my_game->num_rows + 1);
	i = -1;
	while (++i < 6)
		t[i] = ft_substr(my_game->map[i], 0, ft_strlen(my_game->map[i]));
	while (my_game->map[i])
	{
		if (my_game->map[i][0] == '\n' && my_game->map[i][1] == '\0')
			print_error_and_exit("invalid map!");
		if (my_game->map[i][0] == '\n')
			t[i] = ft_substr(my_game->map[i], 1, ft_strlen(my_game->map[i])-1);
		else
			t[i] = ft_substr(my_game->map[i], 0, ft_strlen(my_game->map[i]));
		i++;
	}
	t[i] = 0;
	return (t);
}
