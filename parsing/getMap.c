/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:32:28 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/03 23:40:01 by ael-asri         ###   ########.fr       */
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

char	*creat_fill(int x)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("");
	while (i < x)
	{
		s = ft_strjoin(s, "#");
		i++;
	}
//	printf("#s %s", s);
	return (s);
}

void	fill_em(char *s, int *i)
{
	while ((s[*i] == '0' || s[*i] == '1' || s[*i] == 'S' || s[*i] == 'N') && s[*i] != '\0')
		(*i)++;
}

void	skip_em(char *s, int *i)
{
	while (s[*i] == ' ' && s[*i] != '\0')
	{
		// t = ft_strjoin2(t, "#");
		(*i)++;
	}
}

char	**render_new_map(t_game *my_game)
{
	char	**t;
	int		i;
	int		j;
	int		x;
	int		start;
	// int		y;

	i = 6;
	j = 0;
	x = 0;
	start = 0;
	t = (char **)ft_calloc(sizeof(char *), 999);
	// y = 0;
	while (my_game->map[i] != '\0')
	{
		j = 0;
		while (my_game->map[i][j] != '\0')
		{
			// printf("c %c\n", my_game->map[i][j]);
			if (my_game->map[i][j] == ' ')
			{
				start = j;
				skip_em(my_game->map[i], &j);
				// printf("start %d j %d\n", start, j);
				t[x] = ft_strjoin(t[x], creat_fill(j - start));
				// printf("t %s\n", t[x]);
				// t[x] = ft_strjoin(t[x], ft_substr(my_game->map[i], start, j));
				// printf("yo space %s >>%d\n", t[x], j);
				// x++;
			}
			else if (my_game->map[i][j] == '1' || my_game->map[i][j] == '0' || my_game->map[i][j] == 'S' || my_game->map[i][j] == 'N')
			{
				start = j;
				fill_em(my_game->map[i], &j);
				// printf("j %d, start %d\n", j, start);
				t[x] = ft_strjoin(t[x], ft_substr(my_game->map[i], start, j-start));
				// printf("yo valid char %s >>%d\n", t[x], j);
			}
			// else
			// {
			// 	// printf("invalid syntax\n");
			// 	// exit(1);
			// 	j++;
			// }
			// j++;
		}
		// printf("strl %d, longest %d, j %d, libina %d\n", ft_strlen(t[x]), my_game->longestWidth, j, (j - my_game->longestWidth));
		if (j < my_game->longestWidth)
		{
			// printf("y\n");
			start = j;
			while (j < my_game->longestWidth)
				j++;
			t[x] = ft_strjoin(t[x], creat_fill(j - start));
		}
		// my_game->map[i][j] = '\0';
		// printf("check strln %d\n", ft_strlen(t[x]));
		i++;
		x++;
	}
	return (t);
}
/*
char	**render_new_map(t_game *my_game)
{
	int i = 0;
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
			// y = 0;
			while ((ft_strlen(t[i]) + y) < (my_game->longestWidth_end) && my_game->map[x][y] == ' ')
			{
				zyada[y] = '#';
				// printf("y %d\n", y);
				y++;
			}
			if (!my_game->map[x][y])
				zyada[y] = '\0';
			t[i] = ft_strjoin(t[i], zyada);
			// printf("final %s\n", t[i]);
		}
		else
		{
			// j = 0;
			// y = 0;
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
		if (my_game->map[x][y] == '\0')
		{
			i++;
			x++;
			// j = 0;
			y = 0;
		}
	}
	// int w = 0;
	// while (my_game->map[x])
	// {
	// 	y = 0;
	// 	while (my_game->map[x][y])
	// 	{
	// 		while (my_game->map[x][y] == ' ' && my_game->map[x][y] != '\0')
	// 		{
	// 			zyada[y] = '#';
	// 			y++;
	// 		}
	// 		zyada[y] = '\0';
	// 		t[i] = ft_strjoin(t[i], zyada);
	// 		if (y != 0)
	// 			w = y ;
	// 		// printf("the value of w = {%d}\n",w);
	// 		while (y && my_game->map[x][y] != ' ' && my_game->map[x][y] != '\0')
	// 			y++;
	// 		if (y && w != y)
	// 		{
	// 			t[i] = ft_strjoin(t[i], ft_substr(my_game->map[x], w, y));
	// 			y--;
	// 		}
	// 		// printf("the value if string:t={%s}\n",t[i]);
	// 		y++;
	// 	}
	// 	x++;
	// 	i++;
	// }
	i=0;
	while (my_game->map[i])
	{
		free(my_game->map[i]);
		my_game->map[i] = NULL;
		i++;
	}
	return (t);
}
*/
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
	// int start=0;
	// int end=0;
	int	temp;

	i = 0;
	temp = ft_strlen(my_game->map[i]);
	while (my_game->map[i])
	{
		if (temp < ft_strlen(my_game->map[i]))
		{
			temp = ft_strlen(my_game->map[i]);
			int x=0;
			while (my_game->map[i][x] != '1')
				x++;
			my_game->longestWidth_start = x;
			my_game->longestWidth_end = temp;
			// printf("start %d, end %d\n", start, end);
			// printf("*%s*\n", my_game->map[i]);
		}
		i++;
	}
	my_game->longestWidth = temp;
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
	my_game->map = ft_split(temp, '\n');
	if (!my_game->map)
		exit(1);
	// raw map
	// for(int i=0;i<20;i++)
	// 	printf("*%s*", my_game->map[i]);
	check_map_paths(my_game); // hang here
	get_longestWidth(my_game);
	my_game->newmap = render_new_map(my_game);
	// new map
	printf("yo\n");
	printf("\n\n\n");
	check_map(my_game);
	// assign lists
	my_game->gamer = player;
	my_game->mapp = map;
	creation_window(my_game);
	free(temp);
	close(fd);
}
