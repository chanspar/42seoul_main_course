/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:44:18 by doukim            #+#    #+#             */
/*   Updated: 2023/03/19 19:14:02 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	lensrc;
	size_t	lendst;

	idx = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	dst += lendst;
	while (src[idx] && lendst + idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	if (dstsize > lendst)
		return (lensrc + lendst);
	else
		return (lensrc + dstsize);
}
