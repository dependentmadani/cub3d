/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:36:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/10/16 13:36:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*t;

	i = 0;
	t = malloc(count * size);
	if (t == NULL)
		return (0);
	while (i < (size * count))
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	t = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t)
		exit(1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		t[i] = s2[j];
		i++;
		j++;
	}
	return (t);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (n <= 0)
	{
		return (0);
	}
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_rev_strncmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1)-1;
	j = 0;
	while (s1[i] == ' ')
		i--;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		j++;
		i--;
	}
	return (1);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
