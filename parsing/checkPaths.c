/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:45 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/05 18:39:24 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_last_slach_index(char *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == '\\')
			index = i;
		i++;
	}
	return (index);
}

void	paths_are_valid(t_game *my_game)
{
	if (!ft_rev_strncmp(my_game->no_path, "mpx.")
		|| !ft_rev_strncmp(my_game->so_path, "mpx.")
		|| !ft_rev_strncmp(my_game->ea_path, "mpx.")
		|| !ft_rev_strncmp(my_game->we_path, "mpx."))
	{
		printf("invalid path.xpm");
		exit(0);
	}
}

void	rgb_are_valid1(t_game *my_game)
{
	int		i;
	int		x;
	int		start;

	i = 0;
	x = 0;
	my_game->char_f_rgb = (char **)ft_calloc(sizeof(char *), 999);
	my_game->char_c_rgb = (char **)ft_calloc(sizeof(char *), 999);
	while (x < 3 && my_game->f_path[i])
	{
		start = i;
		while (my_game->f_path[i] != ',')
			i++;
		my_game->char_f_rgb[x] = ft_substrzwina(my_game->f_path, start, i);
		if (ft_strlen(my_game->char_f_rgb[x]) > 3)
		{
			printf("invalid rgb value!\n");
			exit(1);
		}
		i++;
		x++;
	}
	my_game->char_f_rgb[x] = 0;
}

void	rgb_are_valid2(t_game *my_game)
{
	int		i;
	int		x;
	int		start;

	i = 0;
	x = 0;
	while (x < 3 && my_game->c_path[i])
	{
		start = i;
		while (my_game->c_path[i] != ',')
			i++;
		my_game->char_c_rgb[x] = ft_substrzwina(my_game->c_path, start, i);
		if (ft_strlen(my_game->char_c_rgb[x]) > 3)
		{
			printf("invalid rgb value!\n");
			exit(1);
		}
		i++;
		x++;
	}
	my_game->char_c_rgb[x] = 0;
}

void	check_map_paths(t_game *my_game)
{
	int	i;

	i = 0;
	paths_are_valid(my_game);
	rgb_are_valid1(my_game);
	rgb_are_valid2(my_game);
}
