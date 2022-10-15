/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:56 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/15 17:54:49 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_only_spaces(char *s)
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

void	assign_paths_rgbs2(t_game *my_game, char *s)
{
	if (!ft_specialstrncmp(s, "EA", 2))
	{
		my_game->ea_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_ea = 1;
	}
	else if (!ft_specialstrncmp(s, "F", 1))
	{
		my_game->f_path = ft_substrzwina(s, 1, ft_strlen(s));
		my_game->is_f = 1;
	}
	else if (!ft_specialstrncmp(s, "C", 1))
	{
		my_game->c_path = ft_substrzwina(s, 1, ft_strlen(s));
		my_game->is_c = 1;
	}
}

void	assign_paths_rgbs(t_game *my_game, char *s)
{
	if (!ft_specialstrncmp(s, "NO", 2))
	{
		my_game->no_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_no = 1;
	}
	else if (!ft_specialstrncmp(s, "SO", 2))
	{
		my_game->so_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_so = 1;
	}
	else if (!ft_specialstrncmp(s, "WE", 2))
	{
		my_game->we_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_we = 1;
	}
	else
		assign_paths_rgbs2(my_game, s);
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

void	missin_path_color(t_game *my_game, int count)
{
	if (my_game->is_no != 1 || my_game->is_so != 1 || my_game->is_we != 1
		|| my_game->is_ea != 1 || my_game->is_f != 1 || my_game->is_c != 1)
		print_error_and_exit("missing paths or colors!");
	my_game->num_rows = count;
}
