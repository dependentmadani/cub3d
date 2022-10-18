/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPathsRgbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:45 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/18 11:02:12 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_paths_are_valid(t_game *my_game)
{
	if (!ft_rev_strncmp(my_game->no_path, "mpx.")
		|| !ft_rev_strncmp(my_game->so_path, "mpx.")
		|| !ft_rev_strncmp(my_game->ea_path, "mpx.")
		|| !ft_rev_strncmp(my_game->we_path, "mpx."))
		ft_print_error_and_exit("invalid path.xpm");
}

int	is_str_digit(char *s)
{
	int	i;

	i = 0;
	if (!ft_strncmp(s, "-0", 2))
		return (1);
	if (s[i] == '+' && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_rgb_are_valid(t_game *my_game)
{
	int	x;

	x = -1;
	check_vis(my_game->f_path, my_game->c_path);
	my_game->char_f_rgb = ft_split_rgb(my_game->f_path, ',');
	my_game->char_c_rgb = ft_split_rgb(my_game->c_path, ',');
	if (!my_game->char_f_rgb || !my_game->char_c_rgb)
		exit(1);
	while (my_game->char_f_rgb[++x])
		if (!is_str_digit(my_game->char_f_rgb[x]))
			ft_print_error_and_exit("rgb values must be only digits!");
	if (x != 3)
		ft_print_error_and_exit("invalid rgb syntax!");
	x = -1;
	while (my_game->char_c_rgb[++x])
		if (!is_str_digit(my_game->char_c_rgb[x]))
			ft_print_error_and_exit("rgb values must be only digits!");
	if (x != 3)
		ft_print_error_and_exit("invalid rgb syntax!");
}

void	ft_get_rgb_values(t_game *my_game)
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
			ft_print_error_and_exit("rgb value out of range!");
		my_game->f_rgb[i] = t;
	}
	my_game->f_rgb[i] = '\0';
	i = -1;
	while (my_game->char_c_rgb[++i])
	{
		t = ft_atoi(my_game->char_c_rgb[i]);
		if (t < 0 || t > 255)
			ft_print_error_and_exit("rgb value out of range!");
		my_game->c_rgb[i] = t;
	}
	my_game->c_rgb[i] = '\0';
}

void	ft_check_map_paths_rgbs(t_game *my_game)
{
	ft_paths_are_valid(my_game);
	ft_rgb_are_valid(my_game);
	ft_get_rgb_values(my_game);
	if (my_game->one_and_only != 1)
		ft_print_error_and_exit("player not found x_x");
}
