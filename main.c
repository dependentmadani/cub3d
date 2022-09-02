/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/08/27 14:57:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "NO", 2))
			printf("NO\n");
		else if (!ft_strncmp(av[1], "SO", 2))
			printf("SO\n");
		else if (!ft_strncmp(av[1], "WE", 2))
			printf("WE\n");
		else if (!ft_strncmp(av[1], "EA", 2))
			printf("EA\n");
		t_game tg;
		t_player *py;
		t_map *mp;
		py = ft_calloc(sizeof(t_player), 1);
		mp = ft_calloc(sizeof(t_map), 1);
		get_map(av[1], &tg, py, mp);
	}
	else
		printf("invalid number of arguments!\n");
	return (0);
}
