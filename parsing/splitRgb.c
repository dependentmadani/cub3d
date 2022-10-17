/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitRgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:32:16 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/14 14:45:02 by ael-asri         ###   ########.fr       */
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

static char	**ft_chek_and_fill(char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (s[i])
	{
		temp = i;
		if ((s[i] == c && s[i + 1] == c) || !is_str_digit(&s[ft_strlen(s) - 1]))
			ft_print_error_and_exit("invalid rgb form");
		if (s[i] == c || s[i] == ' ')
		{
			i++;
			continue ;
		}
		while (s[i] != c && s[i] != ' ' && s[i])
			i++;
		t[count] = ft_substr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	return (t);
}

char	**ft_split_rgb(char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = ft_set_count(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (ft_chek_and_fill(t, s, c));
}
