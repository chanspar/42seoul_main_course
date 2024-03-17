/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:01:54 by doukim            #+#    #+#             */
/*   Updated: 2023/03/15 21:20:23 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	idx;
	size_t	idx2;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] && idx < len)
	{
		idx2 = 0;
		while (idx + idx2 < len && idx2 < needle_len)
		{
			if (haystack[idx + idx2] != needle[idx2])
				break ;
			idx2++;
		}
		if (idx2 == needle_len)
			return ((char *)haystack + idx);
		idx++;
	}
	return (NULL);
}
