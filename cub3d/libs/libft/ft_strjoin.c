/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:54:48 by doukim            #+#    #+#             */
/*   Updated: 2023/03/19 15:25:55 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len = ft_strlen(s1) + ft_strlen(s2);
	char *const		ret = (char *)malloc(len + 1);
	size_t			idx;
	size_t			idx2;

	if (!ret)
		return (NULL);
	idx = 0;
	idx2 = 0;
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	while (s2[idx2])
	{
		ret[idx] = s2[idx2];
		idx++;
		idx2++;
	}
	ret[idx] = '\0';
	return (ret);
}
