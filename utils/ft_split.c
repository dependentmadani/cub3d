/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:56:30 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 15:16:15 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_set_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_del(char **t, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

int	ft_check_for_c(t_game *game, char *s, char c, int *i)
{
	if (s[*i] == c && game->p_valid < 6)
	{
		(*i)++;
		return (1);
	}
	return (0);
}

static char	**ft_chek_and_fill(t_game *my_game, char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (s[i])
	{
		temp = i;
		if (ft_check_for_c(my_game, s, c, &i))
			continue ;
		else if (s[i] == c && my_game->p_valid >= 6)
			ft_deal_with_c(s, &i);
		while (s[i] != c && s[i])
			i++;
		t[count] = ft_substr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		ft_is_path_color(my_game, t[count], s, &i);
		count++;
	}
	t[count] = 0;
	ft_missin_path_color(my_game, count);
	return (t);
}

char	**ft_split(t_game *my_game, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = ft_set_count(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 2));
	if (t == NULL)
		return (0);
	return (ft_chek_and_fill(my_game, t, s, c));
}
