/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:46:25 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/05 17:36:16 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putstr_error_exit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

void	ft_putnbr(int n)
{
	long int	i;

	i = n;
	if (i < 0)
		exit(1);
	if (i / 10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar((i % 10) + '0');
}

void	ft_free_map(t_game *my_game)
{
	int	i;

	i = 0;
	while (my_game->map[i] != NULL)
	{
		free(my_game->map[i]);
		i++;
	}
	free(my_game->map);
}
