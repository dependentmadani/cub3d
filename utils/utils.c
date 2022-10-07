/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:10:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/07 16:49:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	else if (len < ft_strlen(s))
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

char	*ft_substrzwina(char	*s, int start, int end)
{
	char	*tab;
	int		i;
	int		j;

	tab = NULL;
	if (s == 0)
		return (0);
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit(1);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < end)
			tab[j++] = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
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
