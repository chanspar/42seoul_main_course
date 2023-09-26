/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:24:57 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 17:25:43 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_strdup(const char *s1)
{
	size_t		src_len;	
	char		*p;
	char		*tmp;

	src_len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (src_len + 1));
	if (p == 0)
		return (0);
	tmp = p;
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = 0;
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*p;

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
