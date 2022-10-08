/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:42 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/08 16:45:04 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_sstrcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src)+1);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	sign;
	int	res;
	int	temp;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error_and_exit("rgb values must be digits!");
		i++;
	}
	i = 0;
	temp = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res < temp)
			print_error_and_exit("invalid rgb values");
		temp = res;
		i++;
	}
	return (res * sign);
}

void	is_path_color(t_game *game, char *t, char *s, int *i)
{
	int	temp;

	if (is_path_rgb(t))
	{
		assign_paths_rgbs(game, t);
		if (game->p_valid == 5)
		{
			while (s[*i] == '\n' && s[*i] != '\0')
				(*i)++;
			temp = *i;
			while (s[temp] != '\0')
			{
				if (s[temp] == '\n')
					print_error_and_exit("invalid map");
				if (s[temp] == '1')
					break ;
				temp++;
			}
		}
		game->p_valid++;
	}
}

void	deal_with_c(char *s, int *i)
{
	if (s[*i + 1] != '\0')
		*i += 2;
	else
		(*i)++;
}
