/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderNewMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:24:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/03 14:13:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_em(char *s, int *i)
{
	while ((s[*i] == '0' || s[*i] == '1' || s[*i] == 'S' || s[*i] == 'N' || s[*i] == 'E' || s[*i] == 'W') && s[*i] != '\n')
		(*i)++;
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

char	*get_other_chars(char *t, char *s, int *j)
{
	int	start;

	start = *j;
	fill_em(s, j);
	t = ft_strjoin(t, ft_substr(s, start, *j - start));
	return (t);
}

int	other_chars_condition(char c)
{
	if (c == '1' || c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

char	*filling_countinues(char *t, int *j, int longestWidth)
{
	int	start;

	start = *j;
	while (*j < longestWidth)
		(*j)++;
	t = ft_strjoin(t, creat_fill(*j - start));
	return (t);
}

char	**render_new_map(t_game *my_game)
{
	char	**t;
	int		i;
	int		x;
	int		j;

	i = 6;
	j = 0;
	x = 0;
	t = (char **)ft_calloc(sizeof(char *), my_game->num_rows + 1);
	while (my_game->newmap[i] != '\0')
	{
		j = 0;
		while (my_game->newmap[i][j] != '\0')
		{
			if (my_game->newmap[i][j] == ' ' || my_game->newmap[i][j] == '\t')
				t[x] = get_space_tab(t[x], my_game->newmap[i], &j);
			else if (other_chars_condition(my_game->newmap[i][j]))
				t[x] = get_other_chars(t[x], my_game->newmap[i], &j);
			else
				print_error_and_exit("invalid character!");
		}
		if (j < my_game->longestWidth)
			t[x] = filling_countinues(t[x], &j, my_game->longestWidth);
		x++;
		i++;
	}
	t[x] = 0;
	return (t);
}