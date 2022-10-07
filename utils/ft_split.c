/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:56:30 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/13 12:54:28 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	set_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_del(char **t, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

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
	else if (!ft_strncmp(s, "EA ", 3))
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

int	is_path_rgb(char *s)
{
	if (!ft_strncmp(s, "NO ", 3) || !ft_strncmp(s, "SO ", 3)
			|| !ft_strncmp(s, "WE ", 3) || !ft_strncmp(s, "EA ", 3)
			|| !ft_strncmp(s, "F ", 2) || !ft_strncmp(s, "C ", 2))
			return (1);
	return (0);
}
static char	**chek_and_fill(t_game *my_game, char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;
	int	p_valid;

	i = 0;
	count = 0;
	p_valid = 0;
	while (s[i])
	{
		temp = i;
		if (s[i] == c && p_valid < 6)
		{
			i++;
			continue ;
		}
		else if (s[i] == c && p_valid >= 6)
			i+=2;
		while (s[i] != c && s[i])
			i++;
		t[count] = ft_substr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		if (is_path_rgb(t[count]))
		{
			assign_paths_rgbs(my_game, t[count]);
			if (p_valid == 5)
				while (s[i] == c)
					i++;
			p_valid++;
		}
		count++;
	}
	t[count] = 0;
	if (my_game->is_no != 1 || my_game->is_so != 1 || my_game->is_we != 1 || my_game->is_ea != 1 || my_game->is_f != 1 || my_game->is_c != 1)
		print_error_and_exit("missing paths or colors!");
	my_game->num_rows = count;
	
	return (t);
}

char	**ft_split(t_game *my_game, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(my_game, t, s, c));
}
