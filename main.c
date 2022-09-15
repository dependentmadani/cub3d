/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/13 15:58:40 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game		tg;
	t_player	*py;
	t_map		*mp;

	if (ac == 2)
	{
		if (!check_rev_file(av[1]))
			print_error_and_exit("invalid file!");
		ft_initializer(&tg);
		// py = ft_calloc(sizeof(t_player), 1);
		py = ft_calloc(sizeof(t_player), 1);
		mp = ft_calloc(sizeof(t_map), 1);
		get_map(av[1], &tg/*, py, mp*/);
		tg.mapp = mp;
		tg.gamer = py;
		printf("sh is good\n");
		creation_window(&tg);
		// for(int i=0;tg.newmap[i];i++)
		// 	printf("-%s-\n", tg.newmap[i]);
		// printf("yo?\n");
	}
	else
		printf("invalid number of arguments!\n");
	return (0);
}
