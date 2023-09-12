/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:55:50 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:24:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	strlen_ft(const char *s)
{
	long long	len;
	long long	i;

	i = 0;
	len = 0;
	while (*(s + i))
	{
		len++;
		i++;
	}
	return (len);
}

char	*strjoin_ft(char const *s1, char const *s2)
{
	long long	s1_len;
	long long	s2_len;
	long long	i;
	char		*p;

	s1_len = strlen_ft(s1);
	s2_len = strlen_ft(s2);
	i = 0;
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (p == 0)
		return (0);
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		p[i] = s2[i - s1_len];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*strchr_ft(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*strdup_ft(const char *s1)
{
	long long	src_len;
	long long	idx;	
	char		*p;

	idx = 0;
	src_len = strlen_ft(s1);
	p = (char *)malloc(sizeof(char) * (src_len + 1));
	if (p == 0)
		return (0);
	while (s1[idx])
	{
		p[idx] = s1[idx];
		idx++;
	}
	p[idx] = 0;
	return (p);
}
