/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:28 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/13 15:59:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*getmaplines(int fd)
{
	char	*t;
	char	*temp;
	char	*s;
	int		i;

	s = ft_strdup("");
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
	if (!s && !i)
	{
		free(temp);
		print_error_and_exit("invalid map");
	}
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



void	get_map(char *av, t_game *my_game/*, t_player *player, t_map *map*/)
{
	int		fd;
	char	*temp;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	temp = getmaplines(fd);
	if (!temp)
		print_error_and_exit("invalid map");
	my_game->map = ft_split(my_game, temp, '\n');
	if (!my_game->map)
		print_error_and_exit("invalid map");
	my_game->newmap = check_map_map(my_game);
	for(int i=0;my_game->newmap[i];i++)
		printf("+%s+\n", my_game->newmap[i]);
	get_longestWidth(my_game);
	my_game->newestmap = render_new_map(my_game);
	for(int i=0;my_game->newestmap[i];i++)
		printf("-%s-\n", my_game->newestmap[i]);
	check_map(my_game);
	check_map_paths_rgbs(my_game);
	// printf("sh is good %s\n", my_game->no_path);
	// exit(1);
	free(temp);
	close(fd);
	
}
