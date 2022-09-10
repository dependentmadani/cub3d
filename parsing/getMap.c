/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:28 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/08 16:55:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*getmaplines(char *s, int fd)
{
	char	*t;
	char	*temp;
	int		i = 0;

	temp = ft_strdup("");
	if (!temp)
		exit(1);
	while (1)
	{
		s = get_next_line(fd); 
		if (!s)
			break ;
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			exit(1);
		free(s);
		free(t);
		i++;
	}
	if (!s && !i)
	{
		free(temp);
		exit(EXIT_FAILURE);
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

void	get_rgb_values(t_game *my_game)
{
	int	t;
	int	i;
	int	x;

	i = 0;
	x = 0;
	my_game->f_rgb = malloc(sizeof(int) * 9);
	my_game->c_rgb = malloc(sizeof(int) * 9);
	while (my_game->char_f_rgb[i])
	{
		t = ft_atoi(my_game->char_f_rgb[i]);
		// printf("yoo %d\n", t);
		if (t < 0 || t > 255)
		{
			printf("invalid rgb value!/n");
			exit(1);
		}
		my_game->f_rgb[x] = t;
		x++;
		i++;
	}
	my_game->f_rgb[x] = '\0';
	// for (int r=0; r<3;r++)
	// 	printf("f rgb value %d\n", my_game->f_rgb[r]);
	i = 0;
	x = 0;
	while (my_game->char_c_rgb[i])
	{
		t = ft_atoi(my_game->char_c_rgb[i]);
		if (t < 0 || t > 255)
		{
			printf("invalid rgb value!/n");
			exit(1);
		}
		// printf("yoo %d\n", t);
		my_game->c_rgb[x] = t;
		x++;
		i++;
	}
	my_game->c_rgb[x] = '\0';
	// for (int r=0; r<3;r++)
	// 	printf("c rgb value %d\n", my_game->c_rgb[r]);
}

void	get_map(char *av, t_game *my_game, t_player *player, t_map *map)
{
	int		fd;
	char	*s;
	char	*temp;

	s = NULL;
	if (!check_rev_file(av))
		ft_putstr_error_exit("invalid file\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	temp = getmaplines(s, fd);
	if (!temp)
		exit(1);
	printf("%s\n", temp);
	my_game->map = ft_split(my_game, temp, '\n');
	if (!my_game->map)
		exit(1);
	// raw map
	// for(int i=0;i<20;i++)
	// 	printf("-%s-", my_game->newmap[i]);
	// check_map_paths(my_game);
	my_game->newmap = check_map_map(my_game);
	for(int i=0;my_game->newmap[i];i++)
		printf("+%s+\n", my_game->newmap[i]);
	get_longestWidth(my_game);
	my_game->newestmap = render_new_map(my_game);
	// exit(1);
	for(int i=0;my_game->newestmap[i];i++)
		printf("-%s-\n", my_game->newestmap[i]);
	// new map
	// printf("www\n\n\n");
	check_map(my_game);
	check_map_paths(my_game);
	get_rgb_values(my_game);
	my_game->mapp = map;
	my_game->gamer = player;
	printf("sh is good\n");
	// exit(1);
	creation_window(my_game);
	free(temp);
	close(fd);
}
