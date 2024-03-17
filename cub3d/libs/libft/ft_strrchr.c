/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:58:58 by doukim            #+#    #+#             */
/*   Updated: 2023/03/16 15:57:11 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	while (idx > 0)
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
