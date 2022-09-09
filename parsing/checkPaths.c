/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:45 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/07 11:34:50 by ael-asri         ###   ########.fr       */
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
	// int	i;
	// int	no_index;

	// no_index = get_last_slach_index(my_game->no_path);
	// printf("no index %d\n");
	if (!ft_rev_strncmp(my_game->no_path, "mpx.") || !ft_rev_strncmp(my_game->so_path, "mpx.") || !ft_rev_strncmp(my_game->ea_path, "mpx.") || !ft_rev_strncmp(my_game->we_path, "mpx."))
	{
		printf("invalid path.xpm");
		exit(0);
	}
	// while (my_game->no_path)
	// {
		
	// 	i++;
	// }
	// return (1);
}

void	rgb_are_valid(t_game *my_game)
{
	// int	i;
	// int	no_index;

	// no_index = get_last_slach_index(my_game->no_path);
	// printf("no index %d\n");
	int		i;
	int		x;
	int		start;

	i = 0;
	x = 0;
	// t = ;
	my_game->char_f_rgb = (char **)ft_calloc(sizeof(char *), 999);
	my_game->char_c_rgb = (char **)ft_calloc(sizeof(char *), 999);
	while (x < 3 && my_game->f_path[i])
	{
		start = i;
		while (my_game->f_path[i] != ',')
			i++;
		// printf("3lach %s start %d i %d\n", ft_substr2(my_game->f_path, start, i), start, i);
		my_game->char_f_rgb[x] = ft_substrzwina(my_game->f_path, start, i);
		if (ft_strlen(my_game->char_f_rgb[x]) > 3)
		{
			printf("invalid rgb value!\n");
			exit(1);
		}
		// printf("wwhhyy %s\n", my_game->f_rgb[x]);
		i++;
		x++;
	}
		// printf("3lach %s\n", my_game->f_rgb[x]);
	my_game->char_f_rgb[x] = 0;
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
	// printf("NO %c %c\n", my_game->map[i][0], my_game->map[i][1]);
/*	if (ft_strncmp(my_game->map[i], "NO ", 3))
	{
		printf("path incorrect!\n");
		exit(1);
	}
	i++;
	if (ft_strncmp(my_game->map[i], "SO ", 3))
	{
		printf("path incorrect!\n");
		exit(1);
	}
	i++;
	if (ft_strncmp(my_game->map[i], "WE ", 3))
	{
		printf("path incorrect!\n");
		exit(1);
	}
	i++;
	if (ft_strncmp(my_game->map[i], "EA ", 3))
	{
		printf("path incorrect!\n");
		exit(1);
	}
	i++;
	if (ft_strncmp(my_game->map[i], "F ", 2))
	{
		printf("path incorrect!\n");
		exit(1);
	}
	i++;
	if (ft_strncmp(my_game->map[i], "C ", 2))
	{
		printf("path incorrect!\n");
		exit(1);
	}*/
	// printf("mal mj\n");
	paths_are_valid(my_game);
	rgb_are_valid(my_game);
}
