/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:33:10 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/13 21:43:45 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	else if (dstsize == 1)
	{
		*dst = 0;
		return (srclen);
	}
	while (*(src + i) && dstsize > i + 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (srclen);
}

static int	word_cnt(char *str, char c)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 1;
	while (*str)
	{
		if (*str == c)
			flag = 1;
		else if (*str != c && flag == 1)
		{	
			cnt++;
			flag = 0;
		}
		str++;
	}
	return (cnt);
}

static int	fail_free(char **p, int i)
{
	while (0 <= i)
	{
		free(*(p + i));
		i--;
	}
	free(p);
	return (0);
}

static int	mal_str(char **p, char *str, char c)
{
	int		cnt;
	int		i;
	int		wd_cnt;
	char	*tmp;

	i = 0;
	wd_cnt = word_cnt(str, c);
	while (i < wd_cnt)
	{
		while (*str == c && *str != 0)
			str++;
		cnt = 0;
		tmp = str;
		while (*str != c && *str != 0)
		{
			str++;
			cnt++;
		}
		*(p + i) = (char *)malloc(sizeof(char) * (cnt + 1));
		if (*(p + i) == 0)
			return (fail_free(p, i));
		ft_strlcpy(*(p + i), tmp, cnt + 1);
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		wd_cnt;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	wd_cnt = word_cnt((char *)s, c);
	p = (char **)malloc(sizeof(char *) * (wd_cnt + 1));
	if (p == 0)
		return (0);
	if (mal_str(p, (char *)s, c) == 0)
		return (0);
	p[wd_cnt] = 0;
	return (p);
}
