/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:57:50 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/13 20:11:11 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (*(s + i))
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) && *(s2 + i)) && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
			i++;
		else if (*(s1 + i) > *(s2 + i) || *(s1 + i) < *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	}
	if (n == i || (*(s1 + i) == 0 && *(s2 + i) == 0))
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	long long	s1_len;
	long long	s2_len;
	long long	i;
	char		*p;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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

char	*ft_strchr(const char *s, int c)
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

char	*ft_strdup(const char *s1)
{
	long long	src_len;
	long long	idx;	
	char		*p;

	idx = 0;
	src_len = ft_strlen(s1);
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
