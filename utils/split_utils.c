/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:56 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 15:45:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim_last_spaces(char *s)
{
	char	*t;
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ')
		i--;
	t = ft_substr(s, 0, i + 1);
	return (t);
}

int	ft_specialstrncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	if (n <= 0)
	{
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[i] == ' ' && s1[i] != '\0')
		i++;
	while (s1[i] && n)
	{
		if (s1[i] > s2[j])
			return (1);
		else if (s1[i] < s2[j])
			return (-1);
		i++;
		j++;
		n--;
	}
	return (0);
}

void	ft_missin_path_color(t_game *my_game, int count)
{
	if (my_game->is_no != 1 || my_game->is_so != 1 || my_game->is_we != 1
		|| my_game->is_ea != 1 || my_game->is_f != 1 || my_game->is_c != 1)
		ft_print_error_and_exit("missing paths or colors!");
	my_game->num_rows = count;
}
