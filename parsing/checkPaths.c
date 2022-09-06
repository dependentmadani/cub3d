/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:45 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/05 11:41:28 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_paths(t_game *my_game)
{
	int	i;

	i = 0;
	// printf("NO %c %c\n", my_game->map[i][0], my_game->map[i][1]);
	if (ft_strncmp(my_game->map[i], "NO ", 3))
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
	}
}
