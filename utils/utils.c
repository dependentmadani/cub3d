/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:10:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 15:44:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char	*s, int start, int len)
{
	char	*tab;
	int		i;
	int		j;

	tab = NULL;
	if (s == 0)
		return (0);
	if (len >= ft_strlen(s))
		tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			tab[j++] = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_with_index(char *s, t_normsht *t_nsht, int *startend)
{
	char	*tab;

	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit(1);
	while (s[t_nsht->i] != '\0' && s[t_nsht->i] != ' ')
	{
		if (t_nsht->i >= startend[0] && t_nsht->i < startend[1])
		{
			tab[*(t_nsht->j)] = s[t_nsht->i];
			*(t_nsht->j) += 1;
		}
		t_nsht->i++;
	}
	tab[*(t_nsht->j)] = 0;
	return (tab);
}

char	*ft_without_index(char *s, t_normsht *t_nsht, int *startend)
{
	char	*tab;
	char	*t;

	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit(1);
	while (s[t_nsht->i] != '\0')
	{
		if (t_nsht->i >= startend[0] && t_nsht->i < startend[1])
		{
			tab[*(t_nsht->j)] = s[t_nsht->i];
			*(t_nsht->j) += 1;
		}
		t_nsht->i++;
	}
	tab[*(t_nsht->j)] = 0;
	t = ft_trim_last_spaces(tab);
	free(tab);
	return (t);
}

t_normsht	*ft_assign_nsht(int i, int *j)
{
	t_normsht	*t_nsht;

	t_nsht = malloc(sizeof(t_normsht));
	if (!t_nsht)
		exit(1);
	t_nsht->i = i;
	t_nsht->j = j;
	return (t_nsht);
}

char	*ft_substrzwina(char *s, int *startend, int index)
{
	t_normsht	*t_nsht;
	char		*tab;
	int			i;
	int			j;

	if (s == 0)
		return (0);
	i = 0;
	while (i <= ft_strlen(s) && s[i] == ' ')
		i++;
	i += startend[0];
	j = 0;
	while (i <= ft_strlen(s) && s[i] == ' ')
		i++;
	t_nsht = ft_assign_nsht(i, &j);
	(void)index;
	tab = ft_without_index(s, t_nsht, startend);
	free(t_nsht);
	return (tab);
}
