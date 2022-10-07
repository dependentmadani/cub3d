/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderNewMap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/07 16:02:09 by ael-asri         ###   ########.fr       */
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

char	*strcat_hash(int x)
{
	// if (dstsize == 0)
	// 	return (src_len);
	int i = 0;
	char *t = malloc(999);
	while (x > 0)
	{
		t[i] = '#';
		i++;
		x--;
	}
	t[i] = '\0';
	// printf("malawa mok\n");
	// system("leaks cub3D");
	// exit(1);
	return (t);
}

char	*create_fill(int x)
{
	char	*s;
	int		i;

	i = 0;
	// s = NULL;
//	s = ft_strdup("");
	// s = malloc(99);
	// char *c = ft_strdup("#");
	// while (i < x)
	// {
	// 	s = ft_strjoin(s, c);
	// 	i++;
	// }
	s = strcat_hash(x);
	// printf("malawa mok\n");
	// system("leaks cub3D");
	// exit(1);
	// printf("s %s\n", s);
	
	return (s);
}

char	*get_space_tab(char *s, int *j)
{
	char *t=NULL;
	char	*temp;
	int		start;

	start = *j;
	skip_em(s, j);
	temp = create_fill(*j - start);
	// system("leaks cub3D");
	// free(temp);
	// exit(1);
	// t = ft_strdup("");
	t = ft_strjoin(t, temp);
	free(temp);
	// printf("mal mok\n");
	// printf("malawa mok\n");
	// system("leaks cub3D");
	// exit(1);
	return (t);
}

char	*get_other_chars(t_game *game, char *s, int *j)
{
	char *t=NULL;
	char	*temp;
	int		start;

	start = *j;
	// printf("mall mok\n");
	// system("leaks cub3D");
	// exit(1);
	fill_em(game, s, j);
	temp = ft_substr(s, start, *j - start);
	// t = ft_strdup("");
	t = ft_strjoin(t, temp);
	// free(t);
	free(temp);
	
	// for (int i=0; my_game->newestmap[i];i++)
	// {
	// 	free(my_game->newestmap[i]);
	// 	my_game->newestmap[i] = NULL;
	// }
	// free(my_game->newestmap);
	// free(s);
	return (t);
}
