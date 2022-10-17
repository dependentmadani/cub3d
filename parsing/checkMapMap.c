/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:41:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/13 09:48:57 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_alone(char **s, int i, int j)
{
	if ((j >= ft_strlen(s[i - 1]) && s[i - 1])
		|| (s[i + 1] && j >= ft_strlen(s[i + 1])))
		ft_print_error_and_exit("invalid map");
}

void	ft_skippp_cp(t_game *my_game, char **t, int *i)
{
	while ((*i) < 6)
	{
		t[*i] = ft_substr(my_game->map[*i], 0, ft_strlen(my_game->map[*i]));
		(*i)++;
	}
}

char	**ft_check_map_map(t_game *my_game)
{
	char	**t;
	int		i;

	t = (char **)ft_calloc(sizeof(char *), my_game->num_rows + 1);
	i = 0;
	ft_skippp_cp(my_game, t, &i);
	while (my_game->map[i])
	{
		if (my_game->map[i][0] == '\0' || (my_game->map[i][0] == '\n'
			&& ft_strlen(my_game->map[i]) >= 1 && my_game->map[i][1] == '\0'))
			ft_print_error_and_exit("invalid map!");
		if (my_game->map[i][0] == '\n')
			t[i] = ft_substr(my_game->map[i], 1, \
				ft_strlen(my_game->map[i]) - 1);
		else
			t[i] = ft_substr(my_game->map[i], 0, ft_strlen(my_game->map[i]));
		i++;
	}
	t[i] = 0;
	if (i == 6)
		return (NULL);
	return (t);
}
