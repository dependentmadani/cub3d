/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/07 19:38:07 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	main(int ac, char **av)
{
	t_game		tg;
	t_player	*py;
	t_map		*mp;

	if (ac == 2)
	{
		if (!ft_check_rev_file(av[1]))
			ft_print_error_and_exit("invalid file!");
		ft_initializer(&tg);
		py = ft_calloc(sizeof(t_player), 1);
		mp = ft_calloc(sizeof(t_map), 1);
		ft_get_map(av[1], &tg);
		tg.mapp = mp;
		tg.gamer = py;
		ft_creation_window(&tg);
	}
	else
		printf("invalid number of arguments!\n");
	exit(0);
}
