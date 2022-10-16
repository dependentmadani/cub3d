/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:28 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 15:38:50 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	checkline(char *s, char **temp, int i)
{
	if (!s && !i)
	{
		free(*temp);
		print_error_and_exit("invalid map");
	}
}

char	*getmaplines(int fd)
{
	char	*t;
	char	*temp;
	char	*s;
	int		i;

	temp = ft_strdup("");
	if (!temp)
		exit(1);
	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			print_error_and_exit("invalid map");
		free(s);
		free(t);
		i++;
	}
	checkline(s, &temp, i);
	return (temp);
}

int	check_rev_file(char *s)
{
	int	i;

	i = 0;
	while (i < (ft_strlen(s) - 4))
		i++;
	if (!ft_strncmp(&s[i], ".cub", 4))
		return (1);
	return (0);
}

char	**generate_newestmap(t_game *game)
{
	char	**t;
	int		i;
	int		j;

	i = 6;
	j = 0;
	t = (char **)ft_calloc(sizeof(char *), game->num_rows + 1);
	while (game->newmap[i])
	{
		t[j] = ft_strdup(game->newmap[i]);
		j++;
		i++;
	}
	t[j] = NULL;
	if (j == 6)
		return (NULL);
	return (t);
}

void	get_map(char *av, t_game *my_game)
{
	int		fd;
	char	*temp;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("invalid file");
	temp = getmaplines(fd);
	if (!temp)
		print_error_and_exit("invalid map");
	my_game->map = ft_split(my_game, temp, '\n');
	if (!my_game->map)
		print_error_and_exit("invalid map");
	my_game->newmap = check_map_map(my_game);
	if (!my_game->newmap)
		print_error_and_exit("invalid map");
	get_longestwidth(my_game);
	check_map(my_game);
	check_map_paths_rgbs(my_game);
	my_game->newestmap = generate_newestmap(my_game);
	if (!my_game->newestmap)
		print_error_and_exit("invalid map");
	free(temp);
	close(fd);
}
