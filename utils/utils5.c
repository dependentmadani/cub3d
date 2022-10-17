/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:57:48 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 15:38:40 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_assign_paths_rgbs2(t_game *my_game, char *s)
{
	int	startend[2];

	startend[0] = 1;
	startend[1] = ft_strlen(s);
	if (!ft_specialstrncmp(s, "F", 1))
	{
		my_game->f_path = ft_substrzwina(s, startend, 0);
		my_game->is_f = 1;
	}
	else if (!ft_specialstrncmp(s, "C", 1))
	{
		my_game->c_path = ft_substrzwina(s, startend, 0);
		my_game->is_c = 1;
	}
}

void	ft_assign_startend(int *startend, char *s)
{
	startend[0] = 2;
	startend[1] = ft_strlen(s);
}

void	ft_assign_paths_rgbs(t_game *my_game, char *s)
{
	int	startend[2];

	ft_assign_startend(startend, s);
	if (!ft_specialstrncmp(s, "NO", 2))
	{
		my_game->no_path = ft_substrzwina(s, startend, 1);
		my_game->is_no = 1;
	}
	else if (!ft_specialstrncmp(s, "SO", 2))
	{
		my_game->so_path = ft_substrzwina(s, startend, 1);
		my_game->is_so = 1;
	}
	else if (!ft_specialstrncmp(s, "WE", 2))
	{
		my_game->we_path = ft_substrzwina(s, startend, 1);
		my_game->is_we = 1;
	}
	else if (!ft_specialstrncmp(s, "EA", 2))
	{
		my_game->ea_path = ft_substrzwina(s, startend, 1);
		my_game->is_ea = 1;
	}
	else
		ft_assign_paths_rgbs2(my_game, s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;
	int		len;
	int		lock;

	i = 0;
	j = 0;
	lock = 0;
	if (!s1)
		s1 = ft_strdup("");
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	t = malloc(sizeof(char) * len);
	if (!t)
		return (NULL);
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		t[i++] = s2[j++];
	t[i] = '\0';
	return (t);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
