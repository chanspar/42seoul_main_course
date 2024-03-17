/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:24:41 by doukim            #+#    #+#             */
/*   Updated: 2023/03/16 17:53:51 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_strptrlen(char const *s, char c)
{
	size_t	idx;
	size_t	ret;

	ret = 1;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx] && s[idx] != c)
		{
			while (s[idx] && s[idx] != c)
				idx++;
			ret++;
		}
	}
	return (ret);
}

static _Bool	ft_malloc_nullguard(char **ret, size_t ptridx, size_t len)
{
	ret[ptridx] = (char *)malloc(len + 1);
	if (!ret[ptridx])
	{
		while (ptridx > 0)
			free(ret[--ptridx]);
		free(ret);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		ptridx;
	size_t		len;

	ret = (char **)malloc(sizeof(char *) * ft_split_strptrlen(s, c));
	if (!ret)
		return (NULL);
	ptridx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (ft_malloc_nullguard(ret, ptridx, len))
				return (NULL);
			ft_strlcpy(ret[ptridx++], s, len + 1);
			s += len;
		}
	}
	ret[ptridx] = NULL;
	return (ret);
}
