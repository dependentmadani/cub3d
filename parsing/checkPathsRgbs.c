/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPathsRgbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:45 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/10 18:54:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paths_are_valid(t_game *my_game)
{
	if (!ft_rev_strncmp(my_game->no_path, "mpx.")
		|| !ft_rev_strncmp(my_game->so_path, "mpx.")
		|| !ft_rev_strncmp(my_game->ea_path, "mpx.")
		|| !ft_rev_strncmp(my_game->we_path, "mpx."))
		print_error_and_exit("invalid path.xpm");
}

int	is_str_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

void	rgb_are_valid(t_game *my_game)
{
	my_game->char_f_rgb = split_rgb(my_game->f_path, ',');
	my_game->char_c_rgb = split_rgb(my_game->c_path, ',');
	if (!my_game->char_f_rgb || !my_game->char_c_rgb)
		exit(1);
}

void	get_rgb_values(t_game *my_game)
{
	int	t;
	int	i;

	my_game->f_rgb = malloc(sizeof(int) * 9);
	my_game->c_rgb = malloc(sizeof(int) * 9);
	if (!my_game->f_rgb || !my_game->c_rgb)
		exit(1);
	i = -1;
	while (my_game->char_f_rgb[++i])
	{
		t = ft_atoi(my_game->char_f_rgb[i]);
		if (t < 0 || t > 255)
			print_error_and_exit("rgb value out of range!");
		my_game->f_rgb[i] = t;
	}
	my_game->f_rgb[i] = '\0';
	i = -1;
	while (my_game->char_c_rgb[++i])
	{
		t = ft_atoi(my_game->char_c_rgb[i]);
		if (t < 0 || t > 255)
			print_error_and_exit("rgb value out of range!");
		my_game->c_rgb[i] = t;
	}
	my_game->c_rgb[i] = '\0';
}

void	check_map_paths_rgbs(t_game *my_game)
{
	paths_are_valid(my_game);
	rgb_are_valid(my_game);
	get_rgb_values(my_game);
	if (my_game->one_and_only != 1)
		print_error_and_exit("player not found x_x");
}
