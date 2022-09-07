/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:10:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/09/07 11:32:54 by ael-asri         ###   ########.fr       */
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
	// if (len >= ft_strlen(s))
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (0);
	// else if (len < ft_strlen(s))
	// 	tab = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		// printf("-%c-\n", s[i]);
		if (i >= start && i < end)
		{
			tab[j++] = s[i];
		}
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

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	int len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	// printf("yo %s yo %s\n", s1, s2);
	t = malloc(sizeof(char) * len);
	if (!t)
		return (NULL);
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		t[i] = s2[j];
		i++;
		j++;
	}
	t[i] = '\0';
	// printf("joini %s\n", t);
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

	// printf("yyy\n");
	i = ft_strlen(s1)-1;
	j = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		j++;
		i--;
	}
	// if (n <= 0)
	// {
	// 	return (0);
	// }
	// i = ft_strlen(s1);
	// while ((s1[i] || s2[i]) && i > (ft_strlen(s1) - n))
	// {
	// 	if (s1[i] > s2[i])
	// 		return (1);
	// 	else if (s1[i] < s2[i])
	// 		return (-1);
	// 	i--;
	// }
	return (1);
}

int	ft_strlcpy(char *dst, char *src, int	dstsize)
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

char	*ft_sstrcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src)+1);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	// while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	// 	|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	// 	i++;
	// if (str[i] == '+' || str[i] == '-')
	// {
	// 	if (str[i] == '-')
	// 		sign = -1;
	// 	else if (str[i] == '+')
	// 		sign = 1;
	// 	i++;
	// }
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("rgb values must be digits!\n");
			exit(1);
		}
		i++;
	}
	i=0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
