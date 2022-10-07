/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderNewMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:24:08 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/07 16:05:42 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	t = ft_strjoin(t, create_fill(*j - start));
	return (t);
}

void	check_for_one_and_only(t_game *game, char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
	{
		game->one_and_only++;
		if (game->one_and_only > 1)
			print_error_and_exit("Must go only with one player!");
	}
}

char	*check_cases(t_game *my_game, int i, int *j)
{
	char *temp=NULL;
	// temp = ft_strdup("");
	check_for_one_and_only(my_game, my_game->newmap[i][*j]);
	if (my_game->newmap[i][*j] == ' ' || my_game->newmap[i][*j] == '\t')
	{	
		temp = get_space_tab(my_game->newmap[i], j);
	}
	else if (other_chars_condition(my_game->newmap[i][*j]))
		{
			temp = get_other_chars(my_game, my_game->newmap[i], j);
		}
	else
		print_error_and_exit("invalid character!");
	printf("mal mok\n");
	system("leaks cub3D");
	exit(1);
	return temp;
}

char	**render_new_map(t_game *my_game)
{
	char	**t=NULL;
	int		i;
	int		x;
	int		j;

	i = 6;
	x = 0;
	// t = (char **)ft_calloc(sizeof(char *), my_game->num_rows + 1);
	while (my_game->newmap[i] != '\0')
	{
		j = 0;
		while (my_game->newmap[i][j] != '\0')
			t[x] = ft_strjoin(t[x], check_cases(my_game, i, &j));
		if (j < my_game->longestwidth)
			t[x] = filling_countinues(t[x], &j, my_game->longestwidth);
		x++;
		i++;
	}
	t[x] = 0;
	// printf("malawa mok\n");
	// system("leaks cub3D");
	// exit(1);
	// my_game->newestmap = t;
	
	return (t);
}
