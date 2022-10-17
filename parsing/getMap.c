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

void	ft_checkline(char *s, char **temp, int i)
{
	if (!s && !i)
	{
		free(*temp);
		ft_print_error_and_exit("invalid map");
	}
}

char	*ft_getmaplines(int fd)
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
		s = ft_get_next_line(fd);
		if (!s)
			break ;
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			ft_print_error_and_exit("invalid map");
		free(s);
		free(t);
		i++;
	}
	ft_checkline(s, &temp, i);
	return (temp);
}

int	ft_check_rev_file(char *s)
{
	int	i;

	i = 0;
	while (i < (ft_strlen(s) - 4))
		i++;
	if (!ft_strncmp(&s[i], ".cub", 4))
		return (1);
	return (0);
}

char	**ft_generate_newestmap(t_game *game)
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

void	ft_get_map(char *av, t_game *my_game)
{
	int		fd;
	char	*temp;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_print_error_and_exit("invalid file");
	temp = ft_getmaplines(fd);
	if (!temp)
		ft_print_error_and_exit("invalid map");
	my_game->map = ft_split(my_game, temp, '\n');
	if (!my_game->map)
		ft_print_error_and_exit("invalid map");
	my_game->newmap = ft_check_map_map(my_game);
	if (!my_game->newmap)
		ft_print_error_and_exit("invalid map");
	ft_get_longestwidth(my_game);
	ft_check_map(my_game);
	ft_check_map_paths_rgbs(my_game);
	my_game->newestmap = ft_generate_newestmap(my_game);
	if (!my_game->newestmap)
		ft_print_error_and_exit("invalid map");
	free(temp);
	close(fd);
}
