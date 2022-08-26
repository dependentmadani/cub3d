/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/08/26 11:12:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ft_strncmp(av[1], "NO", 2))
			printf("NO\n");
		else if (ft_strncmp(av[1], "SO", 2))
			printf("SO\n");
		else if (ft_strncmp(av[1], "WE", 2))
			printf("WE\n");
		else if (ft_strncmp(av[1], "EA", 2))
			printf("EA\n");
	}
	else
		perror("invalid number of arguments!\n");
	return (0);
}
