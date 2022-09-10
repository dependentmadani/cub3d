/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderNewMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:24:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/08 16:45:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_em(char *s, int *i)
{
	// printf("dghl %s\n", s);
	while ((s[*i] == '0' || s[*i] == '1' || s[*i] == 'S' || s[*i] == 'N') && s[*i] != '\n')
		(*i)++;
}

void	skip_em(char *s, int *i)
{
	while ((s[*i] == ' ' || s[*i] == '\t') && s[*i] != '\n')
	{
		// t = ft_strjoin2(t, "#");
		(*i)++;
	}
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
	// printf("#s %s", s);
	return (s);
}

char	**render_new_map(t_game *my_game)
{
	char	**t;
	int		i;
	int		j;
	int		x;
	int		start;
	// int		y;

	i = 6;
	j = 0;
	x = 0;
	start = 0;
	t = (char **)ft_calloc(sizeof(char *), my_game->num_rows + 1);
	// y = 0;
	// while (my_game->map[i][0] == '\n')
	// {
	// 	i++;
	// 	printf("hi %d time\n", i);
	// }
	// printf("\nb %s\n", my_game->newmap[i]);
	while (my_game->newmap[i] != '\0')
	{
		j = 0;
		while (my_game->newmap[i][j] != '\0')
		{
			printf("c -%c-\n", my_game->map[i][j]);
			if (my_game->newmap[i][j] == ' ' || my_game->newmap[i][j] == '\t')
			{
				printf("malna\n");
				start = j;
				skip_em(my_game->newmap[i], &j);
				// printf("start %d j %d\n", start, j);
				t[x] = ft_strjoin(t[x], creat_fill(j - start));
			// printf("yya %s\n", t[x]);
				// printf("t %s\n", t[x]);
				// t[x] = ft_strjoin(t[x], ft_substr(my_game->map[i], start, j));
				// printf("yo space %s >>%d\n", t[x], j);
				// x++;
			}
			else if (my_game->newmap[i][j] == '1' || my_game->newmap[i][j] == '0' || my_game->newmap[i][j] == 'S' || my_game->newmap[i][j] == 'N')
			{
				start = j;
				fill_em(my_game->newmap[i], &j);
				// printf("j %d, start %d\n", j, start);
				t[x] = ft_strjoin(t[x], ft_substr(my_game->newmap[i], start, j-start));
				// printf("yo valid char %s >>%d\n", t[x], j);
			}
			else
			{
				printf("invalid character\n");
				exit(1);
				// j++;
			}
			// j++;
		}
		// printf("strl %d, longest %d, j %d, libina %d\n", ft_strlen(t[x]), my_game->longestWidth, j, (j - my_game->longestWidth));
		if (j < my_game->longestWidth)
		{
			// printf("y\n");
			start = j;
			while (j < my_game->longestWidth)
				j++;
			t[x] = ft_strjoin(t[x], creat_fill(j - start));
		}
		// my_game->map[i][j] = '\0';
		// printf("check strln %d\n", ft_strlen(t[x]));
		i++;
		x++;
	}
	t[x] = 0;
	return (t);
}