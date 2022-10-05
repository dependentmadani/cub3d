/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderNewMap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/05 14:34:01 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_em(t_game *game, char *s, int *i)
{
	while ((s[*i] == '0' || s[*i] == '1' || s[*i] == 'S' || s[*i] == 'N'
			|| s[*i] == 'E' || s[*i] == 'W') && s[*i] != '\n')
	{
		check_for_one_and_only(game, s[*i]);
		(*i)++;
	}
}

void	skip_em(char *s, int *i)
{
	while ((s[*i] == ' ' || s[*i] == '\t') && s[*i] != '\n')
		(*i)++;
}

char	*creat_fill(int x)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("");
	while (i < x)
	{
		s = ft_strjoin(s, "#");
		i++;
	}
	return (s);
}

char	*get_space_tab(char *t, char *s, int *j)
{
	int	start;

	start = *j;
	skip_em(s, j);
	t = ft_strjoin(t, creat_fill(*j - start));
	return (t);
}

char	*get_other_chars(t_game *game, char *t, char *s, int *j)
{
	int	start;

	start = *j;
	fill_em(game, s, j);
	t = ft_strjoin(t, ft_substr(s, start, *j - start));
	return (t);
}
