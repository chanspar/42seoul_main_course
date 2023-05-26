/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:52:24 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/24 15:05:42 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || destlen > dstsize)
		return (srclen + dstsize);
	while (i < srclen && (i + destlen) + 1 < dstsize)
	{
		*(dst + destlen + i) = *(src + i);
		i++;
	}
	*(dst + destlen + i) = 0;
	return (destlen + srclen);
}
