/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:01 by doukim            #+#    #+#             */
/*   Updated: 2023/03/19 19:14:49 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	ft_isset(const char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	char		*start;
	char		*end;
	size_t		idx;

	start = (char *)s1;
	end = start + ft_strlen(s1) - 1;
	while (start <= end && ft_isset(*start, set))
		start++;
	while (start <= end && ft_isset(*end, set))
		end--;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		return (NULL);
	idx = 0;
	while (start <= end)
		ret[idx++] = *(start++);
	ret[idx] = '\0';
	return (ret);
}
