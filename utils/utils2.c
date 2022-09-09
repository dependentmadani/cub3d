/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:46:25 by ael-asri          #+#    #+#             */
/*   Updated: 2022/08/27 18:53:53 by ael-asri         ###   ########.fr       */
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

void	free_map(t_game *my_game)
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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*t;

	i = 0;
	t = malloc(count * size);
	if (t == NULL)
		return (0);
	while (i < (size * count))
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	t = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t)
		exit(1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		t[i] = s2[j];
		i++;
		j++;
	}
	return (t);
}
