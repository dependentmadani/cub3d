/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:56 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/05 17:32:18 by ael-asri         ###   ########.fr       */
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
	if (!ft_strncmp(s, "EA ", 3))
	{
		my_game->ea_path = ft_substrzwina(s, 3, ft_strlen(s));
		my_game->is_ea = 1;
	}
	else if (!ft_strncmp(s, "F ", 2))
	{
		my_game->f_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_f = 1;
	}
	else if (!ft_strncmp(s, "C ", 2))
	{
		my_game->c_path = ft_substrzwina(s, 2, ft_strlen(s));
		my_game->is_c = 1;
	}
}

void	assign_paths_rgbs(t_game *my_game, char *s)
{
	if (!ft_strncmp(s, "NO ", 3))
	{
		my_game->no_path = ft_substrzwina(s, 3, ft_strlen(s));
		my_game->is_no = 1;
	}
	else if (!ft_strncmp(s, "SO ", 3))
	{
		my_game->so_path = ft_substrzwina(s, 3, ft_strlen(s));
		my_game->is_so = 1;
	}
	else if (!ft_strncmp(s, "WE ", 3))
	{
		my_game->we_path = ft_substrzwina(s, 3, ft_strlen(s));
		my_game->is_we = 1;
	}
	else
		assign_paths_rgbs2(my_game, s);
}

int	is_path_rgb(char *s)
{
	if (!ft_strncmp(s, "NO ", 3) || !ft_strncmp(s, "SO ", 3)
		|| !ft_strncmp(s, "WE ", 3) || !ft_strncmp(s, "EA ", 3)
		|| !ft_strncmp(s, "F ", 2) || !ft_strncmp(s, "C ", 2))
		return (1);
	return (0);
}

void	missin_path_color(t_game *my_game, int count)
{
	if (my_game->is_no != 1 || my_game->is_so != 1 || my_game->is_we != 1
		|| my_game->is_ea != 1 || my_game->is_f != 1 || my_game->is_c != 1)
		print_error_and_exit("missing paths or colors!");
	my_game->num_rows = count;
}
