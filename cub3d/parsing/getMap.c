/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:28 by ael-asri          #+#    #+#             */
/*   Updated: 2022/08/28 11:02:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*getmaplines(char *s, int fd)
{
	char	*t;
	char	*temp;

	temp = ft_strdup("");
	if (!temp)
		exit(1);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
	// printf("yo\n");
		t = temp;
		temp = ft_strjoin(t, s);
		if (!temp)
			exit(1);
		free(s);
		free(t);
	}
	// if (temp[0] == 0)
	// 	ft_putstr_error_exit("invalid map\n");
	// printf("map %s\n", temp);
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

char	**render_new_map(t_game *my_game)
{
	int i = 0, j=0;
	int x=0,y=0;
	char **t;

	char *zyada;
	t = (char **)ft_calloc(sizeof(char *), 999);
	zyada = (char *)ft_calloc(sizeof(char), 256);
	if (!t)
		exit(1);
	while (t[i])
	{
		t[i] = (char *)ft_calloc(sizeof(char), 256);
		if (!t[i])
			exit(1);
		i++;
	}
	printf("-------\n");
	i = 0;
	while (my_game->map[x])
	{
		if (ft_strlen(my_game->map[x]) != my_game->longestWidth)
		{
			j = 0;
			y = 0;
			while (my_game->map[x][y] == ' ' && my_game->map[x][y] != '\0')
			{
				zyada[y] = '#';
				y++;
			}
			zyada[y] = '\0';
			t[i] = ft_strjoin(t[i], zyada);
			int w=y;
			while (my_game->map[x][y] != ' ' && my_game->map[x][y] != '\0')
			{
				y++;
			}
			t[i] = ft_strjoin(t[i], ft_substrzwina(my_game->map[x], w, y));
			y = 0;
			while ((ft_strlen(t[i]) + y) < (my_game->longestWidth_end))
			{
				zyada[y] = '#';
				// printf("y %d\n", y);
				y++;
			}
			zyada[y] = '\0';
			t[i] = ft_strjoin(t[i], zyada);
			// printf("final %s\n", t[i]);
		}
		else
		{
			j = 0;
			y = 0;
			while (my_game->map[x][y] == ' ' && my_game->map[x][y] != '\0')
			{
				zyada[y] = '#';
				y++;
			}
			zyada[y] = '\0';
			t[i] = ft_strjoin(t[i], zyada);
			int w = y;
			while (my_game->map[x][y] != ' ' && my_game->map[x][y] != '\0')
			{
				y++;
			}
			t[i] = ft_strjoin(t[i], ft_substrzwina(my_game->map[x], w, y));
		}
		i++;
		x++;
	}
	i=0;
	while (my_game->map[i])
	{
		free(my_game->map[i]);
		my_game->map[i] = NULL;
		i++;
	}
	i = 0;
	printf("*********\n");
	printf("*********\n");
	printf("*********\n\n\n");
	
	return (t);
}

int ft_realstrlen(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	return (len);
}

void get_longestWidth(t_game *my_game)
{
	int	i;
	int start=0;
	int end=0;
	int	temp;

	i = 0;
	temp = ft_realstrlen(my_game->map[i]);
	while (my_game->map[i])
	{
		if (temp < ft_realstrlen(my_game->map[i]))
		{
			temp = ft_realstrlen(my_game->map[i]);
			int x=0;
			while (my_game->map[i][x] != '1')
				x++;
			my_game->longestWidth_start = x;
			my_game->longestWidth_end = temp;
			printf("start %d, end %d\n", start, end);
			printf("*%s*\n", my_game->map[i]);
		}
		i++;
	}
	my_game->longestWidth = temp;
}

void	get_map(char *av, t_game *my_game)
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
	// if (temp[ft_strlen(temp) - 1] == '\n')
	// 	ft_putstr_error_exit("invalid map\n");
	my_game->map = ft_split(temp, '\n');
	if (!my_game->map)
		exit(1);
	get_longestWidth(my_game);
	my_game->newmap = render_new_map(my_game);
	for(int i=0;i<14;i++)
		printf("%s\n", my_game->newmap[i]);
	check_map(my_game);
	free(temp);
	close(fd);
}
